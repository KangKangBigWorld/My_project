
#include "GoTo_XY.h"

void GoTo_XY(int x, int y)
{
    HANDLE hOut;
    COORD pos= {x,y};                          // 光标的起始位（第1列，第3行） 0是第1列 2是第3行
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);       //printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}
