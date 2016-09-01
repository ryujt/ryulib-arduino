#include <RyuGame.h>
#include <cheetah.h>

class Cheetah : public GameControlBase
{
private:
  int _TickCount = 0;
  int _Index = 0;
public:
  void start() 
  {
    x = (84 - CHEETAH_WIDTH ) / 2;
    y = (48 - CHEETAH_HEIGHT) / 2;
  }

  void update(unsigned long tick) 
  {
    _LCD->drawBitmap(x, y, cheetah_image[_Index], CHEETAH_WIDTH, CHEETAH_HEIGHT, BLACK);

    _TickCount = _TickCount + tick;
    if (_TickCount > 100) {
      _TickCount = 0;
      _Index++;
      if (_Index >= CHEETAH_COUNT) _Index = 0;
    }
  }
};

GameEngine gameEngine(13, 2, 3, 4, 5, 6);
Cheetah cheetah;

void setup() {
  gameEngine.addControl(&cheetah);
  gameEngine.start();
}

void loop() {
  gameEngine.update();
}

