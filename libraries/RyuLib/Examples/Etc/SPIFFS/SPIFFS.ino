#include "FS.h"

void setup() {
  Serial.begin(9600);
  Serial.println("\nVery basic Spiffs example, writing 10 lines to SPIFFS filesystem, and then read them back");

  SPIFFS.begin();
  
//  Serial.println("Please wait for SPIFFS to be formatted");
//  SPIFFS.format();
//  Serial.println("Spiffs formatted");
//
//  File f = SPIFFS.open("/options.ini", "w");
//  if (!f) Serial.println("file open failed");
//  f.println("Hello?");
//  f.close();
}

void loop() {
  File f = SPIFFS.open("/options.ini", "r");
  if (!f) Serial.println("file open failed");
  String s = f.readStringUntil('\n');
  Serial.println(s);
  f.close();

  delay(3000);
} 
