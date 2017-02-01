#ifndef WIFI_TOOLS_H
#define WIFI_TOOLS_H


#include <Arduino.h>
#include <ESP8266WiFi.h>


class WiFiConnector
{
private:
	long old_tick_;
	int connect_count_;

	char *ssid_;
	char *password_;
public:
	WiFiConnector(char *ssid, char *password)
		: old_tick_(0), connect_count_(0),
		  ssid_(ssid), password_(password)
	{
	}

	void connect()
	{
		long tick = millis();
		long term;
		if ((tick < old_tick_) || (old_tick_ == 0)) term = 0;
		else term = tick - old_tick_;
		old_tick_ = tick;

  		if (connect_count_ > 0) connect_count_ = connect_count_ - term;
	
		if ((WiFi.status() != WL_CONNECTED) && (connect_count_ <= 0)) {
			connect_count_ = 5000;
			WiFi.begin(ssid_, password_);
			// Serial.println("(WiFi.status() != WL_CONNECTED) && (connect_count <= 0)");
			return;
		}

		if (WiFi.status() != WL_CONNECTED) {
			// Serial.println("WiFi.status() != WL_CONNECTED");
			return;
		}
	}
};


#endif // WIFI_TOOLS_H
