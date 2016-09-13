// 미사일 발사 기능 추가

#include <RyuGame.h>
#include <analog_keyboard.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"
#include "Missile.h"

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
  
  if ((key == KEY_FIRE) && spaceShip.getEnabled()) {
    sound_effect_fire(gameEngine.getAudioTrack());
    Missile *missile = new Missile(spaceShip.x, spaceShip.y);
    gameEngine.addControl(missile);
  }
                
  gameEngine.update();
}
