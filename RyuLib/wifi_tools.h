#ifndef WIFI_TOOLS_H
#define WIFI_TOOLS_H


#include <Arduino.h>
#include <ESP8266WiFi.h>


class WiFiConnector
{
private:
	// 처음으로 접속 된 순간을 감지하기 위하여
	bool on_connected_;

	// 처음으로 접속 된 것을 이미 처리하였는가?
	bool on_connected_fired_;

	long old_tick_;
	int connect_count_;

	char *ssid_;
	char *password_;
public:
	WiFiConnector(char *ssid, char *password)	
		: on_connected_(false), on_connected_fired_(false),
		  old_tick_(0), connect_count_(0),
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
			Serial.println("(WiFi.status() != WL_CONNECTED) && (connect_count <= 0)");
			return;
		}

		if ((on_connected_fired_ == false) && (WiFi.status() == WL_CONNECTED)) {
			on_connected_fired_ = true;
			on_connected_ = true;
		}
	}

	/// 현재 접속 중인가?
	bool isConnected()
	{
		return WiFi.status() == WL_CONNECTED;
	}

	/// 접속 된 이후로 처음 호출 되었는가?
	bool onConnected()
	{
		if (on_connected_) {
			on_connected_ = false;
			return true;
		}

		return false;
	}
};


#endif // WIFI_TOOLS_H
