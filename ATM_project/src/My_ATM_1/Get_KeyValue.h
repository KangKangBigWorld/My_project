#ifndef _GET_KEYVALUE_H_
#define _GET_KEYVALUE_H_
#include <conio.h>

/******************************宏定义***************************************/
#define BACKSPACE  8  //BACKSPACE键键值
#define TAB        9  //换行键键值
#define ENTER     13  //回车键键值
#define ESC       27  //ESC键键值
#define ZERO      48  //0键键值
#define ONE       49  //1键键值
#define TWO       50  //2键键值
#define THREE     51  //3键键值
#define FOUR      52  //4键键值
#define FIVE      53  //5键键值
#define SIX       54  //6键键值
#define SEVEN     55  //7键键值
#define EIGHT     56  //8键键值
#define NINE      57  //9键键值

#define KEY_UP    72  //↑键键值
#define KEY_LEFT  75  //←键键值
#define KEY_RIGHT 77  //→键键值
#define KEY_DOWN  80  //↓键键值
#define INSERT    82  //INSERT键键值
 


/*************************常用键值表*******************************************/
/*
  单键值：
  BACKSPACE:8
  TAB:9
  ENTER:13
  ESC:27
  0-9:48-57
  小写a-z:97-122
  大写A-Z:65-90
  F1-F10:(0)(59-68)

  双键值：
  KEY_UP:(int:224 char:-32)		72
  KEY_LEFT:(int:224 char:-32)	75
  KEY_RIGHT:(int:224 char:-32)	77
  KEY_DOWN:(int:224 char:-32)	80
  INSERT:(int:224 char:-32)     82
  DELETE:(int:224 char:-32)     83
  F11:(int:224 133)(char:-32 -123)
  F12:(int:224 134)(char:-32 -122)
 





                                                                       */
/*******************************函数原型**************************************/

/************************************************************************/
/* 
   *函数名称:int Get_KeyValue(void);
   *功能描述:获取按键的键值
   *参数说明:
   *        无     
   *返回值  :
   *        成功则返回：按键键值(int)
   *		失败则返回：0        
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
int Get_KeyValue(void);




#endif