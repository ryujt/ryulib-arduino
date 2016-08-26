#include <RyuGame.h>
#include "Globals.h"
#include "Snake.h"
#include "Foods.h"

int pin_left  = 3;
int pin_right = 4;
int pin_up    = 6;
int pin_down  = 7;
int pin_fire  = 8;

// 게임 종료 처리가 된 적이 있는 가?
bool is_game_end_fire = false;

GameEngine gameEngine(13, 2, 3, 4, 5, 6);
Snake snake;
Foods foods;

void setup() {
  pinMode(pin_left,  INPUT_PULLUP);
  pinMode(pin_right, INPUT_PULLUP);
  pinMode(pin_up,    INPUT_PULLUP);
  pinMode(pin_down,  INPUT_PULLUP);
  pinMode(pin_fire,  INPUT_PULLUP);

  gameEngine.addControl(&snake);
  gameEngine.addControl(&foods);
  gameEngine.start();

  // 3.7v 건전지를 사용 할 때 필요합니다.
//  gameEngine.getLCD()->setContrast(60);

  sound_effect_game_start(gameEngine.getAudioTrack());
}

void loop() {
  if ((is_game_end_fire == false) && (is_game_end)) {
    is_game_end_fire = true;
    sound_effect_game_end(gameEngine.getAudioTrack());   
  }

  if (digitalRead(pin_left) == LOW) snake.setDX(-1);
  if (digitalRead(pin_right) == LOW) snake.setDX(1);
  if (digitalRead(pin_up) == LOW) snake.setDY(-1);
  if (digitalRead(pin_down) == LOW) snake.setDY(1);

  int tick = gameEngine.update();

  if (foods.eat(snake.getX(), snake.getY())) {
    sound_effect_fire(gameEngine.getAudioTrack());
    snake.incSize();    
  }
}
