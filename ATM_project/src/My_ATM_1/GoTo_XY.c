
#include "GoTo_XY.h"

void GoTo_XY(int x, int y)
{
    HANDLE hOut;
    COORD pos= {x,y};                          // ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);       //printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}
