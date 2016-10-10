#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H


#include <RyuGame.h>


struct Block {
  signed char x;
  signed char y;

  bool can_draw()
  {
        return y >= 0;
  }
};

class Board;

class BlockChain : public GameControlBase
{
private:
  Board *_board;
  int _type;
  Block _blocks[4];
  int _block_count;
  int _old_direction;
  void BlockChain::make_block_type_1();
  void BlockChain::make_block_type_2();
  void BlockChain::make_block_type_3();
  void BlockChain::make_block_type_4();
  void BlockChain::make_block_type_5();
  void BlockChain::make_block_type_6();
  void BlockChain::make_block_type_7();
public:
  BlockChain(Board *aboard, int atype);

  void start(); 
  void update(unsigned long tick); 
  bool remove();

  void goto_xy(int ax, int ay);
  void move_left();
  void move_right();
  void rotate();
  void landing();

  bool move_down();

  void set_direction(int adirection) { _old_direction = adirection; }

  void set_type(int atype);
  int get_type() {  return _type; }
};

#endif // BLOCKCHAIN_H
