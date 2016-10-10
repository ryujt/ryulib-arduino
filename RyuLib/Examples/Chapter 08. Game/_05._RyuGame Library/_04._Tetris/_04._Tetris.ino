#include <RyuGame.h>
#include <analog_keyboard.h>
#include "Music.h"
#include "Board.h"
#include "BlockChain.h"

GameEngine gameEngine(13, 2, 3, 4, 5, 6);

Music music;
Board board;
BlockChain next(&board, 0);
BlockChain current(&board, 0);

// 블록이 떨어지는 간격이다.  숫자가 클 수록 느려진다.
int block_speed = 500;
int block_count = 0;

bool is_game_end = false;

void setup() {
  Serial.begin(9600);
  
  gameEngine.addControl(&music);
  gameEngine.addControl(&board);
  gameEngine.addControl(&next);
  gameEngine.addControl(&current);
  gameEngine.start();

  // 3.7v 건전지를 사용 할 때 필요합니다.
//  gameEngine.getLCD()->setContrast(60);
}

void loop() {
  if (is_game_end) return;
  
  int key = readKey(0);
  switch(key) {
    case KEY_UP:    current.move_left(); break;
    case KEY_DOWN:  current.move_right(); break;
    case KEY_RIGHT: current.rotate(); break;
    
    case KEY_LEFT: {
      current.landing();
      block_count = 0;
    }
    break;  

    case KEY_FIRE: {
      if (current.get_type() != 0) break;
      
      randomSeed(millis());

      current.set_type(random(7)+1);

      next.set_type(random(7)+1);
      next.goto_xy(8, 0);
    } 
    break;

    default: current.set_direction(0);
  }

  int tick = gameEngine.update();

  if (current.get_type() == 0) return;

  block_count = block_count + tick;
  if (block_count >= block_speed) {
    block_count = block_count - block_speed;

    if (current.move_down() == false) {
      if (current.remove() == false) {
        is_game_end = true;
        gameEngine.getAudioTrack()->stop();
      }

      block_speed = block_speed - 5;

      if (board.erase_full_line()) {
        gameEngine.getAudioTrack()->stop();
        gameEngine.getAudioTrack()->play(note_E5, 50);
        gameEngine.getAudioTrack()->play(note_E4, 50);
      }     

      current.set_type(next.get_type());

      next.set_type(random(7)+1);
      next.goto_xy(8, 0);      
    }
  }
}

