#include <math.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kalman.h"
#include "MotorDriver.h"

/* MPU-6050 sensor */
#define MPU6050_ACCEL_XOUT_H 0x3B // R
#define MPU6050_PWR_MGMT_1 0x6B // R/W
#define MPU6050_PWR_MGMT_2 0x6C // R/W
#define MPU6050_WHO_AM_I 0x75 // R
#define MPU6050_I2C_ADDRESS 0x68

struct GyroKalman angX;
struct GyroKalman angY;
struct GyroKalman angZ;

/*
* R represents the measurement covariance noise. In this case,
* it is a 1x1 matrix that says that we expect 0.3 rad jitter
* from the accelerometer.
*/
static const float R_angle = 0.3; 		//.3 default

/*
* Q is a 2x2 matrix that represents the process covariance noise.
* In this case, it indicates how much we trust the acceleromter
* relative to the gyros
*/
static const float Q_angle = 0.01;	//0.01 (Kalman)
static const float Q_gyro = 0.04;	//0.04 (Kalman)

//These are the limits of the values I got out of the Nunchuk accelerometers (yours may vary).
const int lowX = -2150;
const int highX = 2210;
const int lowY = -2150;
const int highY = 2210;
const int lowZ = -2150;
const int highZ = 2550;


/* time */
unsigned long prevSensoredTime = 0;
unsigned long curSensoredTime = 0;

int xInit[5] = {0,0,0,0,0};
int yInit[5] = {0,0,0,0,0};
int zInit[5] = {0,0,0,0,0};
int initIndex = 0;
int initSize = 5;
int xCal = 0;
int yCal = 0;
int zCal = 1800;

MotorDriver motors;
SoftwareSerial bluetooth(11, 12);

void setup()
{
	int error;
	uint8_t c;

	initGyroKalman(&angX, Q_angle, Q_gyro, R_angle);
	initGyroKalman(&angY, Q_angle, Q_gyro, R_angle);
	initGyroKalman(&angZ, Q_angle, Q_gyro, R_angle);

	Serial.begin(9600);
  Wire.begin();

	// default at power-up:
	// Gyro at 250 degrees second
	// Acceleration at 2g
	// Clock source at internal 8MHz
	// The device is in sleep mode.
	//
	error = MPU6050_read (MPU6050_WHO_AM_I, &c, 1);
	Serial.print(F("WHO_AM_I : "));
	Serial.print(c,HEX);
	Serial.print(F(", error = "));
	Serial.println(error,DEC);

	// According to the datasheet, the 'sleep' bit
	// should read a '1'. But I read a '0'.
	// That bit has to be cleared, since the sensor
	// is in sleep mode at power-up. Even if the
	// bit reads '0'.
	error = MPU6050_read (MPU6050_PWR_MGMT_2, &c, 1);
	Serial.print(F("PWR_MGMT_2 : "));
	Serial.print(c,HEX);
	Serial.print(F(", error = "));
	Serial.println(error,DEC);

	// Clear the 'sleep' bit to start the sensor.
	MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);

  motors.begin();

  bluetooth.begin(9600);  
}

int height = 0;

void loop()
{
  while (bluetooth.available() > 0) {
    char ch = bluetooth.read();
    Serial.println(ch);

    switch (ch) {
      case 'S': {
        height = 0;
        motors.setHeight(height);
      } break;
      
      case 'U': {
        height = height + 5;
        motors.setHeight(height);
      } break;
      
      case 'D': {
        height = height - 5;
        motors.setHeight(height);
      } break;
    }
  }

	int error;
	double dT;
	accel_t_gyro_union accel_t_gyro;
	
 	curSensoredTime = millis();

	error = MPU6050_read (MPU6050_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));
	if(error != 0) {
		Serial.print(F("Read accel, temp and gyro, error = "));
		Serial.println(error,DEC);
	}

	// Swap all high and low bytes.
	// After this, the registers values are swapped,
	// so the structure name like x_accel_l does no
	// longer contain the lower byte.
	uint8_t swap;
	#define SWAP(x,y) swap = x; x = y; y = swap
	SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
	SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l);
	SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
	SWAP (accel_t_gyro.reg.t_h, accel_t_gyro.reg.t_l);
	SWAP (accel_t_gyro.reg.x_gyro_h, accel_t_gyro.reg.x_gyro_l);
	SWAP (accel_t_gyro.reg.y_gyro_h, accel_t_gyro.reg.y_gyro_l);
	SWAP (accel_t_gyro.reg.z_gyro_h, accel_t_gyro.reg.z_gyro_l);
	
	if(prevSensoredTime > 0) {
		int gx1=0, gy1=0, gz1 = 0;
		float gx2=0, gy2=0, gz2 = 0;

		int loopTime = curSensoredTime - prevSensoredTime;

		gx2 = angleInDegrees(lowX, highX, accel_t_gyro.value.x_gyro);
		gy2 = angleInDegrees(lowY, highY, accel_t_gyro.value.y_gyro);
		gz2 = angleInDegrees(lowZ, highZ, accel_t_gyro.value.z_gyro);

		predict(&angX, gx2, loopTime);
		predict(&angY, gy2, loopTime);
		predict(&angZ, gz2, loopTime);

		gx1 = update(&angX, accel_t_gyro.value.x_accel) / 10;
		gy1 = update(&angY, accel_t_gyro.value.y_accel) / 10;
		gz1 = update(&angZ, accel_t_gyro.value.z_accel) / 10;

		if(initIndex < initSize) {
			xInit[initIndex] = gx1;
			yInit[initIndex] = gy1;
			zInit[initIndex] = gz1;
			if(initIndex == initSize - 1) {
				int sumX = 0; int sumY = 0; int sumZ = 0;
				for(int k=1; k <= initSize; k++) {
					sumX += xInit[k];
					sumY += yInit[k];
					sumZ += zInit[k];
				}

				xCal -= sumX/(initSize -1);
				yCal -= sumY/(initSize -1);
				zCal = (sumZ/(initSize -1) - zCal);
			}
			initIndex++;
		} else {
  			gx1 += xCal;
  			gy1 += yCal;
		}

//		Serial.print(F("Angle x,y,z : "));
//		Serial.print(gx1, DEC);
//		Serial.print(F(", "));
//		Serial.print(gy1, DEC);
//		Serial.print(F(", "));
//		Serial.print(gz1, DEC);
//		Serial.println(F(""));

    motors.setX(gy1 - 62);
    motors.setY(-gx1);
	}

	prevSensoredTime = curSensoredTime;
	delay(200);	
}


/**************************************************
 * Sensor read/write
 **************************************************/
int MPU6050_read(int start, uint8_t *buffer, int size)
{
	int i, n, error;
	
	Wire.beginTransmission(MPU6050_I2C_ADDRESS);
	
	n = Wire.write(start);
	if (n != 1)
		return (-10);
	
	n = Wire.endTransmission(false); // hold the I2C-bus
	if (n != 0)
		return (n);
	
	// Third parameter is true: relase I2C-bus after data is read.
	Wire.requestFrom(MPU6050_I2C_ADDRESS, size, true);
	i = 0;
	while(Wire.available() && i<size)
	{
		buffer[i++]=Wire.read();
	}
	if ( i != size)
		return (-11);
	return (0); // return : no error
}

int MPU6050_write(int start, const uint8_t *pData, int size)
{
	int n, error;
	
	Wire.beginTransmission(MPU6050_I2C_ADDRESS);
	
	n = Wire.write(start); // write the start address
	if (n != 1)
		return (-20);
		
	n = Wire.write(pData, size); // write data bytes
	if (n != size)
		return (-21);
		
	error = Wire.endTransmission(true); // release the I2C-bus
	if (error != 0)
		return (error);
	return (0); // return : no error
}

int MPU6050_write_reg(int reg, uint8_t data)
{
	int error;
	error = MPU6050_write(reg, &data, 1);
	return (error);
}

/**************************************************
 * Raw data processing
 **************************************************/
float angleInDegrees(int lo, int hi, int measured) {
	float x = (hi - lo)/180.0;
	return (float)measured/x;
}


