#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <analog_keyboard.h>

// 일종의 통신 아이디입니다.  pipe가 같은 송수신기끼리만 통신이됩니다.
const uint64_t pipe = 0x12E8F0F0E1LL;

// 조이스틱 모듈에서 사용하는 핀들입니다.
const int pin_sw = 2;
const int pin_x = 0;
const int pin_y = 1;

// RF 통신을 하기 위해서 radio라는 박스(객체)를 만듭니다.
RF24 radio(7, 8);

// 한 번에 주고 받을 수 있는 데이터를 정수 두 개로 합니다.
// 이 예제에서는 한 개만 사용하고 있습니다.
// 더 많은 개수의 데이터 전송도 가능합니다.
int data[2];

void setup() {
  // 조이스틱 버턴을 준비합니다.  
  // PULLUP을 하는 이유는 디바운싱을 위해서입니다.
  pinMode(pin_sw, INPUT_PULLUP);

  // 무선 모듈을 시작합니다.
  radio.begin();

  // 무선 모듈을 전송 상태로 오픈합니다.
  radio.openWritingPipe(pipe);
}

void loop() {
  data[0] = 0;
  
  // 조이스틱의 x 축 좌표를 읽어 옵니다.
  int x = analogRead(pin_x);

  // 조이스틱의 y 축 좌표를 읽어 옵니다.
  int y = analogRead(pin_y);

  // 중앙에 있을 때 500 정도 이면 이를 벗어나면 왼쪽과 오른쪽이 됩니다.
  if (x < 400) data[0] = KEY_LEFT;
  if (x > 600) data[0] = KEY_RIGHT;

  // 중앙에 있을 때 500 정도 이면 이를 벗어나면 윗쪽과 아랫쪽이 됩니다.
  if (y < 400) data[0] = KEY_UP;
  if (y > 600) data[0] = KEY_DOWN;

  // 버턴이 눌러지면 LOW 상태가 됩니다.
  if (digitalRead(pin_sw) == LOW) data[0] = KEY_FIRE;

  // 조이스틱이나 버턴이 눌러졌다면, 데이터를 전송합니다.
  if (data != 0) radio.write(data, sizeof(data));
}
