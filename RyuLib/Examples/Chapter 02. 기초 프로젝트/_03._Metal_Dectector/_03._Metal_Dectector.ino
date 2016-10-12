const int limit = 4;
int avg = 0;
int buzzer_count = 0;

void setup() {
//  Serial.begin(9600);

  pinMode(13, OUTPUT);

  for (int i=0; i<20; i++) {
    avg = avg + analogRead(0);
    delay(50);
  }
  avg = avg / 20;

  tone(13, 400);
  delay(1000);
  noTone(13);
}

void loop() {
  int volume = analogRead(0);

//  Serial.println(volume);

//  Serial.println(avg);
//  Serial.println(volume);
//  Serial.println(abs(volume -avg));
//  Serial.println("-----");
  
  if (abs(volume -avg) > limit) {    
    tone(13, 400);
    delay(1000);
    noTone(13);
    delay(1000);
  }
  
  delay(100);
}

