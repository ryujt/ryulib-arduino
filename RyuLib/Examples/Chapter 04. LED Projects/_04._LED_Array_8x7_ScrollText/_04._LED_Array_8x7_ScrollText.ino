#include <SparkFun_LED_8x7.h>

static byte led_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();
}

void loop() {
  Plex.scrollText("Hello. :)", 1, true);
}
