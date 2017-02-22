#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// https://goo.gl/7u813w 모듈이나 LCD4884 등의 조이스틱을 다룰 때 사용합니다.
// 여기서는 https://goo.gl/7YRzH9 모듈을 사용합니다. KEY_UP 등의 상수만 사용합니다.
// 나중에 조이스틱 모듈을 변경하더라도 같은 동작을 그대로 유지하기 위함입니다.
#include <analog_keyboard.h>

// 일종의 통신 아이디입니다.  pipe가 같은 송수신기끼리만 통신이됩니다.
const uint64_t pipe = 0x12E8F0F0E1LL;

// RF 통신을 하기 위해서 radio라는 박스(객체)를 만듭니다.
RF24 radio(7, 8);

// 한 번에 주고 받을 수 있는 데이터를 정수 두 개로 합니다.
// 이 예제에서는 한 개만 사용하고 있습니다.
// 더 많은 개수의 데이터 전송도 가능합니다.
int data[2];

// 모터 드라이버의 4개의 제어 핀에 연결합니다.
// 두 개의 모터를 제어할 수 있으며, 각 모터마다 2개의 핀이 필요합니다.
// 속도를 제어하려면, 모터마다 1개의 핀이 추가로 필요합니다.
const int a_01 = 2;  
const int a_02 = 3; 
const int b_01 = 4;
const int b_02 = 5;

void setup() {
//  Serial.begin(9600);
//  Serial.println("setup");
  
  // 무선 모듈을 시작합니다.
  radio.begin();

  // 무선모듈을 오픈합니다. 
  radio.openReadingPipe(1,pipe);

  // 수신을 시작합니다.  이제부터 데이터를 수신할 준비가 됩니다.
  radio.startListening();

  // 모터 드라이버에 연결된 4개의 핀을 출력용으로 준비시킵니다.
  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);
}

int command = 0;

void loop() {
  // 무선 모듈에 데이터가 수신되어 있을 때 데이터를 읽습니다.
  while (radio.available()) {
    radio.read(data, sizeof(data));

    // 읽은 데이터 중 첫 번째를 command에 복사합니다.
    command = data[0];
    
//    Serial.println(data[0]);
  }
  
  // forward, command가 KEY_UP 같으면 전진하도록 합니다.
  // 모터 마다 HIGH와 LOW 즉 +와 - 전압을 주면 모터가 돌아갑니다.
  if (command == KEY_UP) {
    digitalWrite(a_01, HIGH);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, HIGH);
    digitalWrite(b_02, LOW);
  }

  //  backward, forward와 반대방향으로 모터를 돌립니다. 
  if (command == KEY_DOWN) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, HIGH);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, HIGH);
  }

  //  left, 두 모터의 돌아가는 방향을 서로 반대로하면 제자리에서 돌게 됩니다.
  // 왼쪽으로 돌도록 합니다.
  if (command == KEY_LEFT) {
    digitalWrite(a_01, HIGH);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, HIGH);
  }

  //  right, left와 반대로 동작하게 합니다.
  if (command == KEY_RIGHT) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, HIGH);
    digitalWrite(b_01, HIGH);
    digitalWrite(b_02, LOW);  
  }

  // stop, 모터를 모두 멈춥니다.
  if (command == KEY_FIRE) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, LOW);
  } 
}
