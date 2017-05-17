#ifndef OPTIONS_H
#define OPTIONS_H


#include <Arduino.h>
#include "FS.h"


class Options
{
private:
  bool is_opend_;
	String key_;
	String ssid_;
	String password_;
public:
	Options() 
    : is_opend_(false)
	{
    SPIFFS.begin();
	}

	void load_from_file()
	{
    Serial.println("Options.load_from_file()");

		File f = SPIFFS.open("/options.ini", "r");
		if (!f) {
      Serial.println("file open failed");
		  return;
		}

    is_opend_ = true;

		key_ = f.readStringUntil('\n');
		ssid_ = f.readStringUntil('\n');
		password_ = f.readStringUntil('\n');

		f.close();

    Serial.println(key_);
    Serial.println(ssid_);
    Serial.println(password_);
	}

	void save_to_file() {
		Serial.println("Options.save_to_file().");

		SPIFFS.begin();
		Serial.println("Please wait for SPIFFS to be formatted.");
		SPIFFS.format();
		Serial.println("Spiffs formatted.");

		File f = SPIFFS.open("/options.ini", "w");
		if (!f) return;

		f.print(key_ + "\n");
		f.print(ssid_ + "\n");
		f.print(password_ + "\n");

		f.close();

    Serial.println(key_);
    Serial.println(ssid_);
    Serial.println(password_);
	}

  bool is_opend() { return is_opend_; }

	String get_key() { return key_; }
	String get_ssid() { return ssid_; }
	String get_password() { return password_; }

	String set_key(String value) { 
    Serial.println("Options.set_key() - " + value);
	  key_ = value; 
	}
 
	String set_ssid(String value) { 
    Serial.println("Options.set_ssid() - " + value);
	  ssid_ = value; 
	}
  
	String set_password(String value) { 
    Serial.println("Options.set_password() - " + value);
	  password_ = value; 
	}
};


#endif // OPTIONS_H
