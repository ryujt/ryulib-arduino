#include <RyuGame.h>

static const unsigned char PROGMEM enemy_image[] =
{ 
        0b00011000,
        0b00111100,
        0b01111110,
        0b11011011,
        0b11111111,
        0b01011010,
        0b10000001,
        0b01000010
};

class Enemy : public GameControlBase
{
private:
public:
  void start() 
  {
    x = (84 - 8) / 2;
    y = (48 - 8) / 2;
  }

  void update(unsigned long tick) 
  {
    _LCD->drawBitmap(x, y, enemy_image, 8, 8, BLACK);
  }
};

GameEngine gameEngine(13, 2, 3, 4, 5, 6);
Enemy enemy;

void setup() {
  gameEngine.addControl(&enemy);
  gameEngine.start();
}

void loop() {
  gameEngine.update();
}

