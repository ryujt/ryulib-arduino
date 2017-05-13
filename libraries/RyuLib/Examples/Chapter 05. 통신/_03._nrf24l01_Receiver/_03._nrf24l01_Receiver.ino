#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0x12E8F0F0E1LL;

RF24 radio(7, 8);
int data[2];

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

bool is_on = false;

void loop() {
  if ( radio.available() ) {
      radio.read( data, sizeof(data) );

    Serial.println(data[0]);

    if (data[0] == 100) {
      is_on = !is_on;
      if (is_on) digitalWrite(2, HIGH);
       else digitalWrite(2, LOW);
    }
  }
}


