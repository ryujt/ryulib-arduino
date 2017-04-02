#include "BluetoothScanner.h"
#include <Servo.h> 
#include <VibrationSensor.h>
#include <sound_effect.h>

BluetoothScanner scanner(10, 11, "2898:7B:B185C7");
Servo servo;
VibrationSensor sensor(2);

void setup() 
{
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);

  scanner.begin();  
}

bool old_locked = true;
bool is_locked = false;

void loop()
{  
  scanner.update();

  is_locked = scanner.getStrength() < 180;

  if (is_locked) {
    if (sensor.isActive()) {
      digitalWrite(5, HIGH);
      seAlarm(13);
      digitalWrite(5, LOW);
    }
  }

  if (is_locked == old_locked)  {
    delay(10);
    return;
  }

  old_locked = is_locked;
  
  if (is_locked) {
    servo.attach(9);
    servo.write(0);
    delay(500);
    servo.detach();
  } else {
    servo.attach(9);
    servo.write(180);
    delay(500);
    servo.detach();
  }
}


