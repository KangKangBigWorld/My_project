#ifndef _MUSIC_H_
#define _MUSIC_H_
#include "sd.h"
#include "ff.h" 
#include "fatfs_app.h"
#include "mp3player.h"
#include "tftlcd.h"

#define MUSIC_App_Num 12		 //乐库界面BUTTON数量
#define MUSIC_Display_Num 12 //音乐播播放界面BUTTON数量
#define MUSIC_DATABASE 0x08062000 //音乐文件数据基地址


/*******************************************************************************
* 函数名         : Music_Init
* 功能		   : 音乐初始化
* 输入         : 无
* 输出         : 无
*******************************************************************************/
void Music_Init(void);
void Music_Display(uint8_t *addr);

#endif


