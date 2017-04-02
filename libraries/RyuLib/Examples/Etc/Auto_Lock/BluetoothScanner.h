#ifndef BLUETOOTH_SCANNER_H
#define BLUETOOTH_SCANNER_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "InqString.h"

#define TIMEOUT 5000
#define INTERVAL 5000

class BluetoothScanner
{
private:  
  SoftwareSerial BTSerial;
  InqString inq_string;
  unsigned long old_tick_;

  void waitFor()
  {
    unsigned long tick = millis(); 
    while (BTSerial.available() == 0) {
      delay(10);
      if ((millis() - tick) > TIMEOUT) break;
    }
    
    while (BTSerial.available()) {
      char ch = BTSerial.read();
      // Serial.write(ch);

      inq_string.putChar(ch);
    }
  }

  void writeTo(String text)
  {
    Serial.println("Command: " + text);
    BTSerial.write(text.c_str());
    waitFor();  
  }
public:
  BluetoothScanner(int rx, int tx, String address) 
    : BTSerial(rx, tx), inq_string(address)
  {

  }

  void begin()
  {
    old_tick_ = millis();

    BTSerial.begin(38400);  

    writeTo("AT+INIT\r\n");
    writeTo("AT+IAC=9E8B33\r\n");
    writeTo("AT+CLASS=0\r\n");
    writeTo("AT+INQM=1,5,5\r\n");
    writeTo("AT+INQ\r\n");
  }

  void update()
  {
    while (BTSerial.available()) {
      char ch = BTSerial.read();
      // Serial.write(ch);

      inq_string.putChar(ch);
    }

    unsigned long tick = millis();
    if (((tick - old_tick_) > INTERVAL) || (tick < old_tick_)) {
      writeTo("AT+INQ\r\n");
      old_tick_ = millis();
    }
  }

  String getAddress()
  {
    return inq_string.getAddress();
  }

  int getStrength()
  {
    return inq_string.getStrength(); 
  }
};

#endif // BLUETOOTH_SCANNER_H
