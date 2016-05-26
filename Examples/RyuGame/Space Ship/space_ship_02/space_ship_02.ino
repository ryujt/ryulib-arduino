#include <RyuGame.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"

int pin_left  = 4;
int pin_right = 5;
int pin_up    = 6;
int pin_down  = 7;
int pin_fire  = 8;

GameEngine gameEngine(3, 9, 10, 11, 12, 13);
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