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

//�����汳��
void Main_Background(void);
//������ͼ��
void Main_Iocn(void);
//���±�����
void jishiben_BackGround(void);
//��ʪ�ȱ���
void temperature_BackGround(void);
//���ֲ��ű���
void music_BackGround(void);
//���ӱ���
void colock_BackGround(void);
//�����Լ��ڽ����ֵ���ʾ
void Show_NextNum(u16 x,u16 y,u8 num,u8 min,u8 max);
//ѯ���Ƿ�ɾ��
void Show_Delete(void);
//ͼ��+���� 
void Iocn(u16 x, u16 y, u16 wide, u16 high,const u8 *pic, uint8_t *cn ,u16 fg_color,u16 bg_color);

#endif



