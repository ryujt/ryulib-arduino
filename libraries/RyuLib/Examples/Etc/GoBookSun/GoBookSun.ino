#include "MotorControl.h"
#include "LocationSensor.h"
#include "Satellite.h"

MotorControl motor;
LocationSensor location;
Satellite satellite;

void on_LocationSensor_Error()
{
}

void on_LocationSensor_Position()
{
}

void on_Satellite_AskPosition()
{
}

void on_Satellite_ClearPosition()
{
}

void on_Satellite_AddPosition()
{
}

void on_Satellite_SetPosition()
{
}

void setup() {
  Serial.begin(9600);
  
  location.setOnError(on_LocationSensor_Error);
  location.setOnPosition_(on_LocationSensor_Position);

  satellite.setOnAskPosition(on_Satellite_AskPosition);
  satellite.setOnClearPosition(on_Satellite_ClearPosition);
  satellite.setOnAddPosition(on_Satellite_AddPosition);
  satellite.setOnSetPosition(on_Satellite_SetPosition);
}

void loop() {
  location.tick();
  satellite.tick();
}
