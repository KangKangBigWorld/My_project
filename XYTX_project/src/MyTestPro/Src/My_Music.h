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
	u8 name[20];		   //路径和文件名字100个字节（支持25个汉字大小名字）
	u8 time[20]; 
	u8 path[30];
	u8 isEnable;//是否使能
	u8 isOpen;//是否打开
	pHandle Event_pHandle;
}MUSIC;

typedef MUSIC* pMUSIC;


#define MUSICNUM 10

//结构体的大小
#define SIZEOFMUSIC sizeof(MUSIC)
#define SIZEOFTIME sizeof(uint8_t)*20
#define SIZEOFNAME sizeof(uint8_t)*20
#define SIZEOFPATH sizeof(uint8_t)*30 
//音乐是否使能
#define MUSIC_ENABLE 1 //音乐启动
#define MUSIC_DISABLE 0 //音乐不启动
//音乐是否开启
#define MUSIC_OPEN 1   //音乐开启
#define MUSIC_CLOSE 0   //音乐关闭


//音乐初始化
void My_Music_Init(MUSIC My_Music[MUSICNUM]);
//音乐安装
void Music_Install(MUSIC My_Music[MUSICNUM],u8 MusicNum,uint8_t* name,uint8_t* time,uint8_t* path,pHandle EvevtpHandle);
//音乐打开
void MUSIC_Open(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//音乐关闭
void MUSIC_Close(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//音乐卸载
void MUSIC_Destory(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//音乐下载
void MUSIC_DownLoad(MUSIC My_Music[MUSICNUM],u8 MusicNum);
//音乐管理
void MUSIC_Manager(void);


//显示乐库界面
void Show_Music_Library(void);
//显示删除和重命名的按键
void Show_Music_Button(u16 x1,u16 y1,u16 x2,u16 y2,uint8_t *ch,u16 fg_color,u16 bg_color);

void Show_MusicLine(void);
void Select_MusicLine(void);
void Show_MusicLine2(void);
void Select_MusicLine2(void);
void Strcat_Music(u16 x,u16 y,u8 MusicNum,u16 fg_color,u16 bg_color);
void Strcat_Music2(u16 x,u16 y,u8 MusicNum,u16 fg_color,u16 bg_color);

void My_Music_init(void);

//添加音乐
void My_MusicAdd(void);
//添加音乐的界面
void Show_MusicAdd(void);
//音量界面
void Show_Volume(u16 x,u16 y,u16 num,u16 fg_color,u16 bg_color);
//音乐添加
void Music_Add(void);
//删除音乐
void Music_Delete(void);

//添加音乐界面的功能
void My_MusicAdd_Fun(u8* MusicExit);
//音乐对其函数
void Music_UpLine(MUSIC My_music[MUSICNUM]);
//播放音乐
void Music_Play(void);
//上一曲
void Music_Last(void);
//下一曲
void Music_Next(void);
//设置音量
void Music_Volume(void);


//重命名界面
void Show_RenameBackground(void);
//更名
void ChangName(void);
//退出重命名
void Rename_Exit(void);
extern u8 MusicPlay;
extern u8 MusicExit;
extern u8 Keyboard_Music;
extern char MusicName[20];
extern u8 NameNum;
void Music_SetTime(MUSIC My_music[MUSICNUM]);
#endif




