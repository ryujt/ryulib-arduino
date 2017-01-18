void setup() {
  // TODO: 수업 중에 반복문으로 교체하여 반복문의 필요성 설명
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  
  // TODO: 버턴을 사용하는 방법으로 변경
  srand(analogRead(0));
  int no = (rand() % 6) + 1;
  
  // TODO: 수업 중에 switch문으로 교체하여 반복문의 필요성 설명
  if (no == 1) {
    digitalWrite(8, HIGH);
  }

  if (no == 2) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

  if (no == 3) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
  }

  if (no == 4) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
  }

  if (no == 5) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  if (no == 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
}

void loop() {
}
