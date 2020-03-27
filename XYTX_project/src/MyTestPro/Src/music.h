#ifndef _MUSIC_H_
#define _MUSIC_H_
#include "sd.h"
#include "ff.h" 
#include "fatfs_app.h"
#include "mp3player.h"
#include "tftlcd.h"

#define MUSIC_App_Num 12		 //�ֿ����BUTTON����
#define MUSIC_Display_Num 12 //���ֲ����Ž���BUTTON����
#define MUSIC_DATABASE 0x08062000 //�����ļ����ݻ���ַ


/*******************************************************************************
* ������         : Music_Init
* ����		   : ���ֳ�ʼ��
* ����         : ��
* ���         : ��
*******************************************************************************/
void Music_Init(void);
void Music_Display(uint8_t *addr);

#endif


