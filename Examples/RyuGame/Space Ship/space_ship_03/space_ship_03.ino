#include <RyuGame.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"
#include "Missile.h"

int pin_left = 7;
int pin_right = 8;
int pin_fire = 12;

GameEngine gameEngine(13, 6, 5, 4, 3, 2);
SpaceShip spaceShip;
Enemies Enemies;

void setup() 
{
  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pin_right, INPUT_PULLUP);
  pinMode(pin_fire, INPUT_PULLUP);

  gameEngine.addControl(&spaceShip);
  gameEngine.addControl(&Enemies);
  gameEngine.start();
}

void loop() 
{
  if (digitalRead(pin_left) == LOW) {
    spaceShip.x--;
    if (spaceShip.x < 4) spaceShip.x = 4;
  }
  
  if (digitalRead(pin_right) == LOW) {
    spaceShip.x++;
    if (spaceShip.x > 78) spaceShip.x = 78;    
  }
  
  if ((digitalRead(pin_fire) == LOW) && spaceShip.getEnabled()) {
    sound_effect_fire(gameEngine.getAudioTrack());
    Missile *missile = new Missile(spaceShip.x, spaceShip.y);
    gameEngine.addControl(missile);
  }
                
  gameEngine.update();
}