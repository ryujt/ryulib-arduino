#include <analog_keyboard.h>
#include "BlockChain.h"
#include "Board.h"


BlockChain::BlockChain(Board *aboard, int atype)
{
	_board = aboard;
	_block_count = 4;

	this->set_type(atype);
}

void BlockChain::make_block_type_1()
{
	_blocks[0] = {3, 0};
	_blocks[1] = {4, 0};
	_blocks[2] = {5, 0};
	_blocks[3] = {6, 0};
}

void BlockChain::make_block_type_2()
{
	_blocks[0] = {4, 0};
	_blocks[1] = {4, 1};
	_blocks[2] = {5, 1};
	_blocks[3] = {6, 1};
}

void BlockChain::make_block_type_3()
{
	_blocks[0] = {6, 0};
	_blocks[1] = {4, 1};
	_blocks[2] = {5, 1};
	_blocks[3] = {6, 1};
}

void BlockChain::make_block_type_4()
{
	_blocks[0] = {4, 0};
	_blocks[1] = {4, 1};
	_blocks[2] = {5, 1};
	_blocks[3] = {5, 0};
}

void BlockChain::make_block_type_5()
{
	_blocks[0] = {5, 0};
	_blocks[1] = {4, 1};
	_blocks[2] = {5, 1};
	_blocks[3] = {6, 0};
}

void BlockChain::make_block_type_6()
{
	_blocks[0] = {5, 0};
	_blocks[1] = {4, 1};
	_blocks[2] = {5, 1};
	_blocks[3] = {6, 1};
}

void BlockChain::make_block_type_7()
{
	_blocks[0] = {4, 0};
	_blocks[1] = {5, 0};
	_blocks[2] = {5, 1};
	_blocks[3] = {6, 1};
}

void BlockChain::start()
{
}

void BlockChain::set_type(int atype)
{
	_type = atype;

	switch(atype) {
		case 1: make_block_type_1(); break;
		case 2: make_block_type_2(); break;
		case 3: make_block_type_3(); break;
		case 4: make_block_type_4(); break;
		case 5: make_block_type_5(); break;
		case 6: make_block_type_6(); break;
		case 7: make_block_type_7(); break;
	}	
}

void BlockChain::update(unsigned long tick)
{
	if (_type == 0) return; 

	for (int i=0; i<_block_count; i++) {
		if (_blocks[i].can_draw())
			_LCD->drawBitmap(62 - _blocks[i].y*3 - 4, _blocks[i].x*3 + 1, block_image, 3, 3, BLACK);                
	}
}

bool BlockChain::remove()
{
	bool result = true;

	for (int i=0; i<_block_count; i++) {
		if (_board->setBlock(_blocks[i].x, _blocks[i].y) == false) result = false;
	}

	this->set_type(0);

	return result;
}

void BlockChain::goto_xy(int ax, int ay)
{
	for (int i=0; i<_block_count; i++) {
		_blocks[i].x = _blocks[i].x + ax;
		_blocks[i].y = _blocks[i].y + ay;
	}
}

void BlockChain::move_left()
{
	if (_old_direction == KEY_LEFT) return;

	_old_direction = KEY_LEFT;

	bool can_move = true;
	for (int i=0; i<_block_count; i++) {
		if (_board->can_move(_blocks[i].x-1, _blocks[i].y) == false) {
			can_move = false;
			break;
		}
	}

	if (can_move == false) return;

	for (int i=0; i<_block_count; i++) _blocks[i].x = _blocks[i].x - 1;
}

void BlockChain::move_right()
{
	if (_old_direction == KEY_RIGHT) return;

	_old_direction = KEY_RIGHT;

	bool can_move = true;
	for (int i=0; i<_block_count; i++) {
		if (_board->can_move(_blocks[i].x+1, _blocks[i].y) == false) {
			can_move = false;
			break;
		}
	}

	if (can_move == false) return;

	for (int i=0; i<_block_count; i++) _blocks[i].x = _blocks[i].x + 1;
}

void rotate_angle(Block ablocks[], int ablock_count)
{
	// 중심점 구하기
	int cx = 0;
	int cy = 0;
	for (int i=0; i<ablock_count; i++) {
		cx = cx + ablocks[i].x;
		cy = cy + ablocks[i].y;
	}
	cx = cx / ablock_count;
	cy = cy / ablock_count;

	for (int i=0; i<ablock_count; i++) {
		ablocks[i] = {
			cx + (ablocks[i].y - cy), 
			cy - (ablocks[i].x - cx)
		};
	}
}

void BlockChain::rotate()
{
	if (_old_direction == KEY_UP) return;

	_old_direction = KEY_UP;

	Block temp[4] = {_blocks[0], _blocks[1], _blocks[2], _blocks[3]};
	rotate_angle(temp, _block_count);


	bool can_move = true;
	for (int i=0; i<_block_count; i++) {
		if (_board->can_move(temp[i].x, temp[i].y) == false) {
			can_move = false;
			break;
		}
	}

	if (can_move == false) return;

	for (int i=0; i<_block_count; i++) _blocks[i] = temp[i];
}

void BlockChain::landing()
{
	if (_old_direction == KEY_DOWN) return;

	_old_direction = KEY_DOWN;

    while (this->move_down()) ;
}

bool BlockChain::move_down()
{
	bool can_move = true;
	for (int i=0; i<_block_count; i++) {
		if (_board->can_move(_blocks[i].x, _blocks[i].y+1) == false) {
			can_move = false;
			break;
		}
	}

	if (can_move) {
		for (int i=0; i<_block_count; i++) _blocks[i].y = _blocks[i].y + 1;
	}

	return can_move;
}

