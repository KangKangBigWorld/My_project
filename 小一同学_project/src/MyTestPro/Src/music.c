#include "music.h"

#include<stdio.h>
/*******************************************************************************
* 函数名         : Music_Init
* 功能		   : 音乐初始化
* 输入         : 无
* 输出         : 无
*******************************************************************************/

void Music_Init()//音乐初始化
{
	FATFS fs;
	uint32_t sdCapacity, free;
	while(SD_Init()!=0)
	{	
		LCD_ShowString(0,21,"SD Card Error!",16,RED,WHITE);
		//printf_All(0,21, "SD Card Error!",(u16)RED);   
	}			 
	f_mount(&fs,"0:",1); 					//挂载SD卡 
	while(FATFS_GetFree("0:", &sdCapacity, &free) != 0)
	{
		   LCD_ShowString(0,42,"FATfs Error!",16,RED,WHITE);
			//printf_All(0,42, "FATfs error!",(u16)RED);   
	}
	MP3_Volume = 150;
  MP3_AudioSetting(MP3_Volume);
}

/*******************************************************************************
* 函数名         : Music_Display
* 功能		   : /音乐播放界面
* 输入         : 无
* 输出         : 无
*******************************************************************************/


void Music_Display(uint8_t *addr)//音乐播放界面
{
	FATFS fs;
	uint32_t sdCapacity, free;
	//FATFS_Init();							//为fatfs相关变量申请内存		
 	f_mount(&fs,"0:",1); //挂载SD卡 
	while(FATFS_GetFree("0:", &sdCapacity, &free) != 0);
	MP3_PlaySong(addr);
}



