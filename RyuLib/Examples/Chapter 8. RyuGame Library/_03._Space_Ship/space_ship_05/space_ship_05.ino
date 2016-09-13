// 우주선과 적기의 충돌 테스트 추가

#include <RyuGame.h>
#include <analog_keyboard.h>
#include "Globals.h"
#include "SpaceShip.h"
#include "Enemies.h"
#include "Missile.h"

int missile_interval = 500;
int missile_counter = 0;

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
  
  if ((key == KEY_FIRE) && spaceShip.getEnabled() && (missile_counter >= missile_interval)) {
    sound_effect_fire(gameEngine.getAudioTrack());
    missile_counter = 0;
    Missile *missile = new Missile(spaceShip.x, spaceShip.y);
    gameEngine.addControl(missile);
  }

  GameControlBase *control = spaceShip.checkCollision();
  if ((control != NULL)  && (control->getID() == Enemy_ID)) {
          control->setDeleted(true);
          spaceShip.setEnabled(false);
          sound_effect_game_end(gameEngine.getAudioTrack());
  }

  int tick = gameEngine.update();

  if (missile_counter < missile_interval) missile_counter = missile_counter + tick;
}
