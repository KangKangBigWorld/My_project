#include "Get_KeyValue.h"

/*************************常用键值表*******************************************/
/*
单键值：
BACKSPACE:8
TAB:9
ENTER:13
ESC:27
0-9:48-57
小写a-z:97-122
大写A-Z:65-90
F1-F10:(0)(59-68)

  双键值：
  KEY_UP:(int:224 char:-32)		72
  KEY_LEFT:(int:224 char:-32)	75
  KET_RIGHT:(int:224 char:-32)	77
  KEY_DOWN:(int:224 char:-32)	80
  INSERT:(int:224 char:-32)     82
  DELETE:(int:224 char:-32)     83
  F11:(int:224 133)(char:-32 -123)
  F12:(int:224 134)(char:-32 -122)
*/
/************************************************************************/
int Get_KeyValue()
{
	char ch='\0';
	ch=getch();
    switch(ch)
	{
		
	case BACKSPACE:
		{
			return BACKSPACE;
		}break;
	case TAB:
		{
			return TAB;
		}break;	
	case ENTER:
		{
			return ENTER;
		}break;	
	case ESC:
		{
			return ESC;
		}break;	
	case -32:
		{
			ch=getch();
			switch(ch)
			{
			case 72:
				{
					return KEY_UP;
				}break;
			case 75:
				{
					return KEY_LEFT;
				}break;
			case 77:
				{
					return KEY_RIGHT;
				}break;
			case 80:
				{
					return KEY_DOWN;
				}break;
			case 82:
				{
					return INSERT;
				}break;
			default:
				{
					return 0;
				}
			}
		}break;
	case 224:
		{
			ch=getch();
			switch(ch)
			{
			case 72:
				{
					return KEY_UP;
				}break;
			case 75:
				{
					return KEY_LEFT;
				}break;
			case 77:
				{
					return KEY_RIGHT;
				}break;
			case 80:
				{
					return KEY_DOWN;
				}break;
			case 82:
				{
					return INSERT;
				}break;
			default:
				{
					return 0;
				}
			}
		}break;
	default:
		{
			return 0;
		}
		return 0;
	}
}