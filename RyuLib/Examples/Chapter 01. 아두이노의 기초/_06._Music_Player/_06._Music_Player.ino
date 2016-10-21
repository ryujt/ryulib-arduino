#include <sound_effect.h>

void setup() {
	pinMode(13, OUTPUT);
}

void loop() {
	beep(13, note_C5, 300); 
	beep(13, note_E5, 300); 
	beep(13, note_E5, 300); 

	delay(300);

	beep(13, note_E5, 300); 
	beep(13, note_G5, 300); 
	beep(13, note_G5, 300); 

	delay(300);

	beep(13, note_D5, 300); 
	beep(13, note_F5, 300); 
	beep(13, note_F5, 300); 

	delay(300);

	beep(13, note_A5, 300); 
	beep(13, note_B5, 300); 
	beep(13, note_B5, 300); 

	delay(300);
}
