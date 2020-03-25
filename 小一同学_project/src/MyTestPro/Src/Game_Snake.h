#ifndef _GAME_SNAKE_H_
#define _GAME_SNAKE_H_
#include "tftlcd.h"

#define UP 0
#define LEFT 2
#define DOWN 3
#define RIGHT 4 
#define SIZE 10
#define SIDE_X_LEFT 10
#define SIDE_X_RIGHT 230
#define SIDE_Y_UP 10
#define SIDE_Y_DOWN 190

extern u8 Direction;


void Snake_Move(void);

void Snake_Draw(void);

#endif

