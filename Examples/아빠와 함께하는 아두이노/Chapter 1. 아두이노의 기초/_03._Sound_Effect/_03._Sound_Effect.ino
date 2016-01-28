#include <sound_effect.h>

int pin_buzzer = 5;

void setup() {
	pinMode(pin_buzzer, OUTPUT);
}

void loop() {
	seR2D2(pin_buzzer);
	delay(1000);

	seCloseEncounters(pin_buzzer);
	delay(1000);

	seAriel(pin_buzzer);
	delay(1000);

	seLaugh(pin_buzzer);
	delay(1000);

	seLaugh2(pin_buzzer);
	delay(1000);

	seSqueak(pin_buzzer);
	delay(1000);

	seWaka(pin_buzzer);
	delay(1000);

	seCatcall(pin_buzzer);
	delay(1000);

	seOhhh(pin_buzzer);
	delay(1000);

	seUhoh(pin_buzzer);
	delay(1000);

	seChang(pin_buzzer);
	delay(1000);

	seCoo(pin_buzzer);
	delay(1000);

	seOh(pin_buzzer);
	delay(1000);

	sePhone(pin_buzzer);
	delay(1000);

	seSiren(pin_buzzer);
	delay(1000);

	seSpace1(pin_buzzer);
	delay(1000);

	seSpace2(pin_buzzer);
	delay(1000);

	seFanfare(pin_buzzer);
	delay(1000);

	seAlarm(pin_buzzer);
	delay(1000);

	seTelefone(pin_buzzer);
	delay(1000);

	seTonarkade(pin_buzzer);
	delay(1000);

	seTonarkade2(pin_buzzer);
	delay(1000);

	seSad(pin_buzzer);
	delay(1000);

	seVictory(pin_buzzer);
	delay(1000);

	seAssorted(pin_buzzer);
	delay(1000);
}
