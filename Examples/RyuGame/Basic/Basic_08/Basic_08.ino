#include <RyuGame.h>
#include <cheetah.h>

class Cheetah : public GameControlBase
{
private:
  int tick_count = 0;
  int index = 0;
public:
  void start() 
  {
    x = (84 - CHEETAH_WIDTH ) / 2;
    y = (48 - CHEETAH_HEIGHT) / 2;
  }

  void update(unsigned long tick) 
  {
    _LCD->drawBitmap(x, y, cheetah_image[index], CHEETAH_WIDTH, CHEETAH_HEIGHT, BLACK);

    tick_count = tick_count + tick;
    if (tick_count > 100) {
      tick_count = 0;
      index++;
      if (index >= CHEETAH_COUNT) index = 0;
    }
  }
};

GameEngine gameEngine(13, 6, 5, 4, 3, 2);
Cheetah cheetah;

void setup() {
  gameEngine.addControl(&cheetah);
  gameEngine.start();
}

void loop() {
  gameEngine.update();
}

