#include <RyuGame.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"
#include "ScoreBoard.h"

int pint_right = 12;
int pin_left = 11;
int pin_fire = 10;

GameEngine *engine; 
GameLayer *mainLayer;

void setup() 
{
  Serial.begin(9600);  

  engine = new GameEngine(13, 7, 6, 5, 4, 3);

  pinMode(pint_right, INPUT_PULLUP);
  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pin_fire, INPUT_PULLUP);

  mainLayer = engine->addLayer();
  mainLayer->addControl( new SpaceShip() );
  mainLayer->addControl( new Enemies() );
  mainLayer->addControl( new ScoreBoard() );

  engine->start();

  sound_effect_game_start(engine->getAudioTrack());
}

void loop() 
{
  is_right_down = digitalRead(pint_right) == LOW; 
  is_left_down = digitalRead(pin_left) == LOW;
  is_fire_down = digitalRead(pin_fire) == LOW;

  engine->update();
}
