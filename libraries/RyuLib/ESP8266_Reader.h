#ifndef ESP8266_READER_H
#define ESP8266_READER_H


#include <Arduino.h>


class ESP8266Reader : public Stream
{
private:
public:
	ESP8266Reader() {}

	int available() { return 1; }

	size_t write(uint8_t c) 
	{ 
		Serial.print((char) c);
		return 1; 
	}
	int read() 
	{ 
		return 0; 
	}

	int peek() { return 0; }
	void flush() {}
};



#endif // ESP8266_READER_H
