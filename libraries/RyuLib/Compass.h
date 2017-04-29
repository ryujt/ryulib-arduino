#ifndef COMPASS_H
#define COMPASS_H

#include <Arduino.h>
#include <Wire.h>

//0011110b, I2C 7bit address of HMC5883
#define COMPASS_ADDRESS 0x1E 

#define X_OFFSET  30
#define Y_OFFSET 128
#define Z_OFFSET   0

class Compass {
private:
public:
  void begin()
  {
    Wire.begin();
    Wire.beginTransmission(COMPASS_ADDRESS); //open communication with HMC5883
    Wire.write(0x02); //select mode register
    Wire.write(0x00); //continuous measurement mode
    Wire.endTransmission();
  }

  double get_angle()
  {
    //Tell the HMC5883 where to begin reading data
    Wire.beginTransmission(COMPASS_ADDRESS);
    Wire.write(0x03); //select register 3, X MSB register
    Wire.endTransmission();
   
    //Read data from each axis, 2 registers per axis
    int x,y,z;
    Wire.requestFrom(COMPASS_ADDRESS, 6);
    if(6<=Wire.available()){
      x = Wire.read() << 8 | Wire.read();
      z = Wire.read() << 8 | Wire.read();
      y = Wire.read() << 8 | Wire.read();
    }

    return atan2((double)y + Y_OFFSET, (double)x + X_OFFSET) * (180 / 3.141592654) + 180; 
  }
};

#endif // COMPASS_H