#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
#include "tftlcd.h"
#include "touch.h"
#include <stdlib.h>
#include "stm32f10x.h"
#include "SysTick.h"
#include "font_show.h"
#include "picture.h"
#include "My_Music.h"

#define KEYCURSOR_X 0
#define KEYCURSOR_Y 45


#define CAPSLK_BIG 0
#define CAPSLK_LOW 1
#define SIGN 2
#define KEY_NUM 37

#define SHIFT  26
#define DELETE 27 
#define NUMKEY 28
#define QINGPING   29
#define SPACE  30
#define ENTER  31
#define F1     32
#define F2     33
#define F3     34
#define F4     35
#define HIDE     36

#define DELAY_TIME 300

typedef void (*pHandle)();

typedef struct Key_Value
{
	u16 Key_Name;
	u16 Key_X1;
	u16 Key_Y1;
	u16 Key_X2;
	u16 Key_Y2;
	//pHandle Key_pHandle;
}KEY_VALUE;

typedef KEY_VALUE* pKEY_VALUE;
#define SIZEOF_KEY sizeof(KEY_VALUE)

//键盘初始化
void KeyBorad_Init(void);

//打印键盘
void KeyBorad_PriKeyBorad(void);
	
//绘制键盘背景
void LCD_ShowKeyBG(void);

//绘制按键内的内容
void LCD_ShowKey(u16 x,u16 y,u8* ch,u16 FG_Color,u16 BG_Color);


//void LCD_ShowKeyboard(u16 FG_Color,u16 BG_Color);

//光标呼吸函数
void LED_Cursor(void);

//键盘触屏功能
void KeyBoard_Touch(void);

void Qingping(u16 x1,u16 y1,u16 x2,u16 y2,u8 size,u16 FG_Color,u16 BG_Color);

void Huanghang(u16 x1,u16 y1,u16 x2,u16 y2,u8 size,u16 FG_Color,u16 BG_Color);

void Delect(u16 x1,u16 y1,u16 x2,u16 y2,u8 size,u16 FG_Color,u16 BG_Color);

extern pKEY_VALUE pKeyInit;
extern u16 Cursor_x;
extern u16 Cursor_y;
extern u8 HIDE_FLAG;

#endif

