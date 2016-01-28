#include <sound_effect.h>

int pin_buzzer = 5;

void setup() {
	pinMode(pin_buzzer, OUTPUT);
}

//C 도
//D 레
//E 미
//F 파
//G 솔
//A 라
//B 시

void loop() {
	beep(pin_buzzer, note_C5, 300); 
	beep(pin_buzzer, note_E5, 300); 
	beep(pin_buzzer, note_E5, 300); 

	delay(300);

	beep(pin_buzzer, note_E5, 300); 
	beep(pin_buzzer, note_G5, 300); 
	beep(pin_buzzer, note_G5, 300); 

	delay(300);

	beep(pin_buzzer, note_D5, 300); 
	beep(pin_buzzer, note_F5, 300); 
	beep(pin_buzzer, note_F5, 300); 

	delay(300);

	beep(pin_buzzer, note_A5, 300); 
	beep(pin_buzzer, note_B5, 300); 
	beep(pin_buzzer, note_B5, 300); 

	delay(300);
}
