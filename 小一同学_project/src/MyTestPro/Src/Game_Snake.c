#include "Game_Snake.h"

u8 Direction=UP;

u8 Snake_x=(SIDE_X_RIGHT+SIDE_X_LEFT)/2+SIZE;
u8 Snake_y=(SIDE_Y_DOWN+SIDE_Y_UP)/2+SIZE;
u8 DrawFlag=0;

void Snake_Move()
{
	switch(Direction)
	{
		case UP:
		{
			if(Snake_y==SIDE_Y_UP)
			{
				Snake_y=SIDE_Y_DOWN;
			}
			else
			{
				Snake_y-=2*SIZE;
			}
		}break;
		case DOWN:
		{
			if(Snake_y==SIDE_Y_DOWN)
			{
				Snake_y=SIDE_Y_UP;
			}
			else
			{
				Snake_y+=2*SIZE;
			}
		}break;
		case LEFT:
		{
			if(Snake_x==SIDE_X_LEFT)
			{
				Snake_x=SIDE_X_RIGHT;
			}
			else
			{
				Snake_x-=2*SIZE;
			}
		}break;
		case RIGHT:
		{
			if(Snake_x==SIDE_X_RIGHT)
			{
				Snake_x=SIDE_X_LEFT;
			}
			else
			{
				Snake_x+=2*SIZE;
			}
		}break;
	}
	DrawFlag=1;
}

void Snake_Draw()
{
	while(DrawFlag)
	{
		switch(Direction)
		{
			case UP:
			{
				if(Snake_y==SIDE_Y_DOWN)
			{
				LCD_Fill(Snake_x-SIZE,SIDE_Y_UP-SIZE,Snake_x+SIZE-1,SIDE_Y_UP+SIZE-1,WHITE);;
			}
			else
			{
				LCD_Fill(Snake_x-SIZE,Snake_y-SIZE+2*SIZE,Snake_x+SIZE-1,Snake_y+SIZE-1+2*SIZE,WHITE);
			}			
			}break;
			case DOWN:
			{
				if(Snake_y==SIDE_Y_UP)
			{
				LCD_Fill(Snake_x-SIZE,SIDE_Y_DOWN-SIZE,Snake_x+SIZE-1,SIDE_Y_DOWN+SIZE-1,WHITE);;
			}
			else
			{
				LCD_Fill(Snake_x-SIZE,Snake_y-SIZE-2*SIZE,Snake_x+SIZE-1,Snake_y+SIZE-1-2*SIZE,WHITE);
			}
			}break;
			case LEFT:
			{
				if(Snake_x==SIDE_X_RIGHT)
			{
				LCD_Fill(SIDE_X_LEFT-SIZE,Snake_y-SIZE,SIDE_X_LEFT+SIZE-1,Snake_y+SIZE-1,WHITE);;
			}
			else
			{
				LCD_Fill(Snake_x-SIZE+2*SIZE,Snake_y-SIZE,Snake_x+SIZE-1+2*SIZE,Snake_y+SIZE-1,WHITE);
			}
			}break;
			case RIGHT:
			{
				if(Snake_x==SIDE_X_LEFT)
			{
				LCD_Fill(SIDE_X_RIGHT-SIZE,Snake_y-SIZE,SIDE_X_RIGHT+SIZE-1,Snake_y+SIZE-1,WHITE);;
			}
			else
			{
				LCD_Fill(Snake_x-SIZE-2*SIZE,Snake_y-SIZE,Snake_x+SIZE-1-2*SIZE,Snake_y+SIZE-1,WHITE);
			}
			}break;
		}
		LCD_Fill(Snake_x-SIZE,Snake_y-SIZE,Snake_x+SIZE-1,Snake_y+SIZE-1,RED);
		DrawFlag=0;
	}
	
}


