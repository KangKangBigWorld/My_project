#ifndef _MY_VIEW_H_
#define _MY_VIEW_H_
#include "tftlcd.h"
#include "font_show.h"
#include "picture.h"
#include "KeyBoard.h"
#include "Rrtc.h"
#include "colock.h"
#include "My_Music.h"

extern u8 Main_iFlag;

//主界面背景
void Main_Background(void);
//主界面图标
void Main_Iocn(void);
//记事本背景
void jishiben_BackGround(void);
//温湿度背景
void temperature_BackGround(void);
//音乐播放背景
void music_BackGround(void);
//闹钟背景
void colock_BackGround(void);
//数字以及邻近数字的显示
void Show_NextNum(u16 x,u16 y,u8 num,u8 min,u8 max);
//询问是否删除
void Show_Delete(void);
//图标+文字 
void Iocn(u16 x, u16 y, u16 wide, u16 high,const u8 *pic, uint8_t *cn ,u16 fg_color,u16 bg_color);

#endif



