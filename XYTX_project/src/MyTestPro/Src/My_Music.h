#ifndef _MY_MUSIC_H_
#define _MY_MUSIC_H_
#include "My_view.h"
#include "tftlcd.h"
#include "font_show.h"
#include "picture.h"

#include "touch.h"
#include <stdlib.h>
#include "stm32f10x.h"
#include "SysTick.h"

#include "Time_IRQ.h"
#include "LED.h"
#include "Rrtc.h"

#include "My_Function.h"

#include "music.h"

typedef void (*pHandle)();

typedef struct Music
{
	u8 name[20];		   //·�����ļ�����100���ֽڣ�֧��25�����ִ�С���֣�
	u8 time[20]; 
	u8 path[30];
	u8 isEnable;//�Ƿ�ʹ��
	u8 isOpen;//�Ƿ��
	pHandle Event_pHandle;
}MUSIC;

typedef MUSIC* pMUSIC;


#define MUSICNUM 10

//�ṹ��Ĵ�С
#define SIZEOFMUSIC sizeof(MUSIC)
#define SIZEOFTIME sizeof(uint8_t)*20
#define SIZEOFNAME sizeof(uint8_t)*20
#define SIZEOFPATH sizeof(uint8_t)*30 
//�����Ƿ�ʹ��
#define MUSIC_ENABLE 1 //��������
#define MUSIC_DISABLE 0 //���ֲ�����
//�����Ƿ���
#define MUSIC_OPEN 1   //���ֿ���
#define MUSIC_CLOSE 0   //���ֹر�


//���ֳ�ʼ��
void My_Music_Init(MUSIC My_Music[MUSICNUM]);
//���ְ�װ
void Music_Install(MUSIC My_Music[MUSICNUM],u8 MusicNum,uint8_t* name,uint8_t* time,uint8_t* path,pHandle EvevtpHandle);
//���ִ�
void MUSIC_Open(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//���ֹر�
void MUSIC_Close(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//����ж��
void MUSIC_Destory(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//��������
void MUSIC_DownLoad(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//���ֹ���
void MUSIC_Manager(void);


//��ʾ�ֿ����
void Show_Music_Library(void);
//��ʾɾ�����������İ���
void Show_Music_Button(u16 x1,u16 y1,u16 x2,u16 y2,uint8_t *ch,u16 fg_color,u16 bg_color);

void Show_MusicLine(void);
void Select_MusicLine(void);
void Show_MusicLine2(void);
void Select_MusicLine2(void);
void Strcat_Music(u16 x,u16 y,u8 MusicNum,u16 fg_color,u16 bg_color);
void Strcat_Music2(u16 x,u16 y,u8 MusicNum,u16 fg_color,u16 bg_color);

void My_Music_init(void);

//�������
void My_MusicAdd(void);
//������ֵĽ���
void Show_MusicAdd(void);
//��������
void Show_Volume(u16 x,u16 y,u16 num,u16 fg_color,u16 bg_color);
//�������
void Music_Add(void);
//ɾ������
void Music_Delete(void);

//������ֽ���Ĺ���
void My_MusicAdd_Fun(u8* MusicExit);
//���ֶ��亯��
void Music_UpLine(MUSIC My_music[MUSICNUM]);
//��������
void Music_Play(void);
//��һ��
void Music_Last(void);
//��һ��
void Music_Next(void);
//��������
void Music_Volume(void);


//����������
void Show_RenameBackground(void);
//����
void ChangName(void);
//�˳�������
void Rename_Exit(void);
extern u8 MusicPlay;
extern u8 MusicExit;
extern u8 Keyboard_Music;
extern char MusicName[20];
extern u8 NameNum;
void Music_SetTime(MUSIC My_music[MUSICNUM]);
#endif




