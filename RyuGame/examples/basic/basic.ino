#include <RyuGame.h>
#include "Control.h"

GameEngine *engine = new GameEngine(7, 6, 5, 4, 3);
GameLayer *mainLayer;
Control *control = new Control();

void setup() 
{
  Serial.begin(9600);

  mainLayer = engine->addLayer();
  mainLayer->addControl(control);
  
  engine->start();
}

void loop() 
{
  engine->update();
}
