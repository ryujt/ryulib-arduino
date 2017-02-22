void setup() {
  Serial.begin(9600);
}

void loop() {
  int humidity;

  // 습할 수록 낮은 숫자가 읽혀진다.
  // 그래서 최대 숫자를 읽혀진 숫자로 빼주면
  // 습할 수록 커지는 상태가 된다.
  humidity = 1023 - analogRead(0);

  Serial.println(humidity);

  if (humidity < 400) {
    tone(13, 400);
  } else {
    noTone(13);
  }

  delay(100);
}
