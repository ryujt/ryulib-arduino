#include <RyuGame.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"

int pin_left = 7;
int pin_right = 8;

GameEngine gameEngine(13, 6, 5, 4, 3, 2);
SpaceShip spaceShip;
Enemies Enemies;

void setup() 
{
  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pin_right, INPUT_PULLUP);

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
  
  gameEngine.update();
}