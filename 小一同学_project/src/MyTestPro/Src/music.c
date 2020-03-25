#include "music.h"

#include<stdio.h>
/*******************************************************************************
* ������         : Music_Init
* ����		   : ���ֳ�ʼ��
* ����         : ��
* ���         : ��
*******************************************************************************/

void Music_Init()//���ֳ�ʼ��
{
	FATFS fs;
	uint32_t sdCapacity, free;
	while(SD_Init()!=0)
	{	
		LCD_ShowString(0,21,"SD Card Error!",16,RED,WHITE);
		//printf_All(0,21, "SD Card Error!",(u16)RED);   
	}			 
	f_mount(&fs,"0:",1); 					//����SD�� 
	while(FATFS_GetFree("0:", &sdCapacity, &free) != 0)
	{
		   LCD_ShowString(0,42,"FATfs Error!",16,RED,WHITE);
			//printf_All(0,42, "FATfs error!",(u16)RED);   
	}
	MP3_Volume = 150;
  MP3_AudioSetting(MP3_Volume);
}

/*******************************************************************************
* ������         : Music_Display
* ����		   : /���ֲ��Ž���
* ����         : ��
* ���         : ��
*******************************************************************************/


void Music_Display(uint8_t *addr)//���ֲ��Ž���
{
	FATFS fs;
	uint32_t sdCapacity, free;
	//FATFS_Init();							//Ϊfatfs��ر��������ڴ�		
 	f_mount(&fs,"0:",1); //����SD�� 
	while(FATFS_GetFree("0:", &sdCapacity, &free) != 0);
	MP3_PlaySong(addr);
}



