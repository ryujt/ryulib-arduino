#include <RyuGame.h>
#include <analog_keyboard.h>
#include "Globals.h"
#include "Snake.h"
#include "Foods.h"

// 게임 종료 처리가 된 적이 있는 가?
bool is_game_end_fire = false;

GameEngine gameEngine(13, 2, 3, 4, 5, 6);
Snake snake;
Foods foods;

void setup() {
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

  int key = readKey(0);
  switch(key) {
    case KEY_LEFT:  snake.setDX(-1); break;
    case KEY_RIGHT: snake.setDX( 1); break;
    case KEY_UP:    snake.setDY(-1); break;
    case KEY_DOWN:  snake.setDY( 1); break;
  }

  int tick = gameEngine.update();

  if (foods.eat(snake.getX(), snake.getY())) {
    sound_effect_fire(gameEngine.getAudioTrack());
    snake.incSize();    
  }
}
