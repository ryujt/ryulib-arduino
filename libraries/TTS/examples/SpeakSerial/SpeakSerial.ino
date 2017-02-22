
#include "TTS.h"

TTS tts(3);

void setup(void) {
  Serial.begin(57600);
  pinMode(13, OUTPUT);
}

char line[80];
int pos = 0;

void loop(void) {
  if (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c == '\n') {
      digitalWrite(13, HIGH);
      line[pos++] = 0;
      if (line[0] == '+') {
        int p = atoi(line+1);
        tts.setPitch(p);
      } else {
        Serial.println(line);
        tts.sayText(line);
      }
      pos = 0;
      digitalWrite(13, LOW);
    } else
      line[pos++] = c;
  }
}
