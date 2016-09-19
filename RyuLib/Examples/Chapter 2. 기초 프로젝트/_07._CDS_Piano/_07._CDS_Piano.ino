#include <sound_effect.h>

void setup() {
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
}

void loop() {
  int max_volt = 400;
  int note = -1;
  
//  Serial.println(analogRead(0));
    
  for (int i=0; i<8; i++) {
    int volt = analogRead(i);
    if (volt > max_volt) {
      max_volt = volt;
      note = i;
    }
  }

  switch (note) {
    case 0: tone(13, note_C4); break;
    case 1: tone(13, note_D4); break;
    case 2: tone(13, note_E4); break;
    case 3: tone(13, note_F4); break;
    case 4: tone(13, note_G4); break;
    case 5: tone(13, note_A4); break;
    case 6: tone(13, note_B4); break;
    case 7: tone(13, note_C5); break;
    default: noTone(13);
  }  
}
