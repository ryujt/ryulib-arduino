#include "Globals.h"


bool can_move_block_to(int ax, int ay)
{
    return 
      (ax >= 0) && 
      (ay >= 0) && 
      (ax < BOARD_WIDTH) && 
      (ay < BOARD_HEIGHT);
}
