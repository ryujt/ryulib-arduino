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

void setup() {
  gameEngine.addControl(&spaceShip);
  gameEngine.start();
}

void loop() {
  gameEngine.update();
}

