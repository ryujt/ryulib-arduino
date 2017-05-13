 #include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0x12E8F0F0E1LL;

RF24 radio(7, 8);
int valarray[2];

void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);

  valarray[0] = 100;
  valarray[1] = 222;
}

void loop() {
  radio.write( valarray, sizeof(valarray) );
  delay(1000);
}
