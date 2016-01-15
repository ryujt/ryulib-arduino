#ifndef GLOBALS_H
#define GLOBALS_H


#define Missile_ID 1
#define Enemy_ID 2


extern int score = 0;

// How offent do enemy appear.  Large number get low chance.
extern int chance_enemy = 20;

extern int enemy_speed = 100;

extern bool is_game_end = false;
extern bool is_right_down = false;
extern bool is_left_down = false;
extern bool is_fire_down = false;


#endif // GLOBALS_H
