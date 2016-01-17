#include <RyuGame.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"
#include "ScoreBoard.h"

int pin_left = 11;
int pint_right = 12;

GameEngine *engine = new GameEngine(7, 6, 5, 4, 3);
GameLayer *mainLayer;

void setup() 
{
  Serial.begin(9600);

  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pint_right, INPUT_PULLUP);

  mainLayer = engine->addLayer();
  mainLayer->addControl( new SpaceShip() );
  mainLayer->addControl( new Enemies() );
  mainLayer->addControl( new ScoreBoard() );
  
  engine->start();
}

void loop() 
{
  is_left_down = digitalRead(pin_left) == LOW;
  is_right_down = digitalRead(pint_right) == LOW; 
  
  engine->update();
}
