#include <SoftwareSerial.h>
#include <GPS.h>
#include <Compass.h>
#include <Interval.h>

// 독도 위치
//const double target_lat = 37.2412295;
//const double target_lon = 131.8647985;

// 양천공원
//const double target_lat = 37.5179259;
//const double target_lon = 126.8683118;

// 율동공원 놀이터
const double target_lat = 37.377633;
const double target_lon = 127.147710;

const int motor_05 = 3; 
const int motor_06 = 5;

const int full_speed = 255;
const int middle_speed = 200;
const int low_speed = 100;

// 10:TX, 11:RX
SoftwareSerial ss(10, 11);

GPS gps;
Compass compass;
Interval interval(1000);

bool is_stoped = false;

void setup() {
  Serial.begin(9600);

  ss.begin(9600);

  // 테스트 한 센서가 368도 기울져 있다.
  // 탱크에 센서를 반대 방향으로 달아서 -180
  compass.set_angle_offset(368 - 180);
  compass.begin();

  pinMode(motor_05, OUTPUT);
  pinMode(motor_06, OUTPUT);
}

void forward()
{
  analogWrite(motor_05, full_speed);
  analogWrite(motor_06, full_speed);
}

void left()
{
  analogWrite(motor_05, full_speed);
  analogWrite(motor_06, middle_speed);
}

void right()
{
  analogWrite(motor_05, middle_speed);
  analogWrite(motor_06, full_speed);
}

void left_only()
{
  analogWrite(motor_05, low_speed);
  analogWrite(motor_06, 0);
}

void right_only()
{
  analogWrite(motor_05, 0);
  analogWrite(motor_06, low_speed);
}

void stop()
{
  analogWrite(motor_05, 0);
  analogWrite(motor_06, 0);
}

void loop() {
  while (ss.available()) {
    char ch = ss.read();
    gps.decode(ch);
//    Serial.print(ch);
  }

  double lat = gps.get_lat(); 
  double lon = gps.get_lon(); 
  double distance = get_distance(lat, lon, target_lat, target_lon);

  int angle = compass.get_angle();
  int target_angle = get_heading(lat, lon, target_lat, target_lon);

  if (interval.onTime()) {
    Serial.print("angle: ");
    Serial.println(angle);
    
    Serial.print("target_angle: ");
    Serial.println(target_angle);
    
    Serial.print("get_distance: ");
    Serial.println(distance);
  }

  if (is_stoped) {
    stop();
    return;
  }

  if ((angle - target_angle) > 5) {
    left();    
  } else if ((angle - target_angle) < -5) {
    right();
  } else {
    forward();
  }

  if (distance <= 10) {
    is_stoped = true;
    stop();
  }
}
