#ifndef _GET_KEYVALUE_H_
#define _GET_KEYVALUE_H_
#include <conio.h>

/******************************�궨��***************************************/
#define BACKSPACE  8  //BACKSPACE����ֵ
#define TAB        9  //���м���ֵ
#define ENTER     13  //�س�����ֵ
#define ESC       27  //ESC����ֵ
#define ZERO      48  //0����ֵ
#define ONE       49  //1����ֵ
#define TWO       50  //2����ֵ
#define THREE     51  //3����ֵ
#define FOUR      52  //4����ֵ
#define FIVE      53  //5����ֵ
#define SIX       54  //6����ֵ
#define SEVEN     55  //7����ֵ
#define EIGHT     56  //8����ֵ
#define NINE      57  //9����ֵ

#define KEY_UP    72  //������ֵ
#define KEY_LEFT  75  //������ֵ
#define KEY_RIGHT 77  //������ֵ
#define KEY_DOWN  80  //������ֵ
#define INSERT    82  //INSERT����ֵ
 


/*************************���ü�ֵ��*******************************************/
/*
  ����ֵ��
  BACKSPACE:8
  TAB:9
  ENTER:13
  ESC:27
  0-9:48-57
  Сдa-z:97-122
  ��дA-Z:65-90
  F1-F10:(0)(59-68)

  ˫��ֵ��
  KEY_UP:(int:224 char:-32)		72
  KEY_LEFT:(int:224 char:-32)	75
  KEY_RIGHT:(int:224 char:-32)	77
  KEY_DOWN:(int:224 char:-32)	80
  INSERT:(int:224 char:-32)     82
  DELETE:(int:224 char:-32)     83
  F11:(int:224 133)(char:-32 -123)
  F12:(int:224 134)(char:-32 -122)
 





                                                                       */
/*******************************����ԭ��**************************************/

/************************************************************************/
/* 
   *��������:int Get_KeyValue(void);
   *��������:��ȡ�����ļ�ֵ
   *����˵��:
   *        ��     
   *����ֵ  :
   *        �ɹ��򷵻أ�������ֵ(int)
   *		ʧ���򷵻أ�0        
   *�޸ļ�¼: ���ڣ�2019.8.11            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int Get_KeyValue(void);




#endif