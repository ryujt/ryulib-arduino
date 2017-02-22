#ifndef HTTP_TOOLS_H
#define HTTP_TOOLS_H


#include <Arduino.h>
#include <WiFiClient.h>


class HttpGet
{
private:
	WiFiClient client_;
public:
	HttpGet()
		: client_()
	{
	}

	void get(char *host, int port, String url)
	{
		if (!client_.connect(host, port)) {
			Serial.println("!client_.connect(host_, post_)");
			return;
		}

		client_.print(
			String("GET ") + url + " HTTP/1.1\r\n" +
			"Host: " + host + "\r\n" +
			"User-Agent: ESP8266\r\n" +
			"Connection: close\r\n\r\n"
		);
	}

	bool available()
	{
		return client_.connected() && client_.available();
	}

	String readln()
	{
		return client_.readStringUntil('\n');
	}
};


#endif // HTTP_TOOLS_H
