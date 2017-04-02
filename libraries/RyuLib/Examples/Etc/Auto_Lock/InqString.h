#ifndef INQSTRING_H
#define INQSTRING_H

#include <Arduino.h>

#define TIMEOUT 10000

class InqString
{
private:
	String address_;
	String temp_;
	String strength_;

	unsigned long old_tick_;

	void parseInq()
	{
		 Serial.println("parseInq: " + temp_);

		if (temp_.substring(0, 3).equals("INQ") == false) {
			// Serial.println("equals(INQ) == false - " + temp_);
			return;
		}

		// INQ:64CC:2E:320160,5A020C,FFC5
		// 012345678901234567890123456789

		// Serial.println("");
		// Serial.println("parseInq");

		String address = temp_.substring(4, 18);

		if (address.equals(address_) == false) {
			Serial.println("(address.equals(address_) == false - " + address);
			return;
		}

		strength_ = temp_.substring(28);

		// Serial.println("address_: " + address_);
		// Serial.println("strength_: " + strength_);
		// Serial.println("");

		old_tick_ = millis();
	}
public:
	InqString(String address)
		: address_(address)
	{
		old_tick_ = 0;
	}

	bool putChar(char ch)
	{
		switch (ch) {
			case '+': temp_ = ""; break;

			case '\r': 
			case '\n': 
			{
				if (temp_.length() > 0) {
					parseInq(); 
					temp_ = "";
					return true;
				}
			} break;

			default: temp_ = temp_ + ch;
		}

		return false;
	}

	String getAddress()
	{
		unsigned long tick = millis();
		if ((old_tick_ == 0) || ((tick-old_tick_) > TIMEOUT) || (tick < old_tick_)) return "";

		return address_;
	}

	int getStrength()
	{
		unsigned long tick = millis();

		if ((old_tick_ == 0) || ((tick-old_tick_) > TIMEOUT) || (tick < old_tick_)) {
//			Serial.print("old_tick_: "); Serial.println(old_tick_);
//			Serial.print("tick: "); Serial.println(tick);

			return 0;
		}

		return (int) strtol(strength_.c_str(), 0, 16); 
	}
};

#endif // INQSTRING_H
