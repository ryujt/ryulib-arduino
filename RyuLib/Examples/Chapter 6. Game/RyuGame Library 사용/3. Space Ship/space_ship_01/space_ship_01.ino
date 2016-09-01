#include <RyuGame.h>
#include "Globals.h"
#include "SpaceShip.h"

int pin_left = 7;
int pin_right = 8;

GameEngine gameEngine(13, 2, 3, 4, 5, 6);
SpaceShip spaceShip;

void setup() 
{
  pinMode(pin_left, INPUT_PULLUP);
  pinMode(pin_right, INPUT_PULLUP);

  gameEngine.addControl(&spaceShip);
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