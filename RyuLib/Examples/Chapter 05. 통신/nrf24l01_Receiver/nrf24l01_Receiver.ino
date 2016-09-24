#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <TM1637Display.h>

#define CE_PIN 7
#define CSN_PIN 8

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(7, 8);
int valarray[2];

TM1637Display display(2, 3);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  
  display.setBrightness(0xff);
  display.showNumberDec(0);             
}

void loop() {
  if ( radio.available() ) {
      radio.read( valarray, sizeof(valarray) );

    Serial.println(valarray[0]);
    display.showNumberDec(valarray[0]);
  }
}

