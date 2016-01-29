#include <RyuGame.h>

class SpaceShip : public GameControlBase
{
private:
public:
  void start() 
  {
    x = 43;
    y = 45;
  }

  void update(unsigned long tick) 
  {
    _LCD->fillCircle(x, y, 2, BLACK);
  }
};

GameEngine gameEngine(13, 6, 5, 4, 3, 2);
SpaceShip spaceShip;

int pin_left = 7;
int pin_right = 8;

void setup() {
  gameEngine.addControl(&spaceShip);
  gameEngine.start();

  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pin_right, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(pin_left) == LOW) {
    spaceShip.x--;
//    spaceShip.x = spaceShip.x - 1;
  }
  
  if (digitalRead(pin_right) == LOW) {
    spaceShip.x++;
//    spaceShip.x = spaceShip.x + 1;
  }

  gameEngine.update();
}

