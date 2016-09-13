#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 7
#define CSN_PIN 8

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN);
int valarray[2];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);

  valarray[0] = 658;
  valarray[1] = 207;
}

void loop() {
  radio.write( valarray, sizeof(valarray) );

  valarray[0]++;
  valarray[1]++;
}
