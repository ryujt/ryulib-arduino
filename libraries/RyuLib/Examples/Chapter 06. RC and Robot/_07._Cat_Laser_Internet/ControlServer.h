#ifndef CONTROL_SERVER_H
#define CONTROL_SERVER_H


#include <Arduino.h>
#include <ESP8266WiFi.h>


class ControlServer
{
private:
	WiFiServer server_;
public:
	ControlServer()
		: server_(80)
	{

	}

	void begin()
	{
		server_.begin();
	}

	char getCommand()
	{
		WiFiClient client = server_.available();
		if (!client) return 0x00;

		Serial.println("new client");

		String line = client.readStringUntil('\n');
		Serial.println(line);
		Serial.println(line.substring(5,  6).c_str()[0]);

		client.println("HTTP/1.1 200 OK");
		client.println("Content-Type: text/html");
		client.println("Connection: close"); 
		client.println();
		client.println("Ok!");

		client.stop();  

		return line.substring(5,  6).c_str()[0];
	}

};


#endif // CONTROL_SERVER_H