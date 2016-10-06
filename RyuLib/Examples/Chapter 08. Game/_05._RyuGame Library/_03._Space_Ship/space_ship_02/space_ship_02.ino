// 적기가 나타나도록 수정

#include <RyuGame.h>
#include <analog_keyboard.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"

GameEngine gameEngine(13, 2, 3, 4, 5, 6);
SpaceShip spaceShip;
Enemies Enemies;

void setup() 
{
  gameEngine.addControl(&spaceShip);
  gameEngine.addControl(&Enemies);
  gameEngine.start();
}

void loop() 
{
  int key = readKey(0);

  if (key == KEY_LEFT) {
    spaceShip.x--;
    if (spaceShip.x < 4) spaceShip.x = 4;
  }
  
  if (key == KEY_RIGHT) {
    spaceShip.x++;
    if (spaceShip.x > 78) spaceShip.x = 78;    
  }
  
  gameEngine.update();
}
