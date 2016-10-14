#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <TM1637Display.h>

const uint64_t pipe = 0x12E8F0F0E1LL;

RF24 radio(7, 8);
int data[2];
TM1637Display display(2, 3);

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  
  display.setBrightness(15);
  display.showNumberDec(0);             
}

void loop() {
  if ( radio.available() ) {
      radio.read( data, sizeof(data) );

    Serial.println(data[0]);
    display.showNumberDec(data[0]);
  }
}

