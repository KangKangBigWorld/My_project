#ifndef _MY_INIT_H_
#define _MY_INIT_H_

#include "System_Init.h"
#include "LED.h"
#include "Buzzer.h"
#include "touch.h"
#include "Rrtc.h"
#include "Boot_test.h"

#include "Time_IRQ.h"


#include "dht11.h"
#include "usart1.h"
#include "flash.h"
#include "malloc.h"
#include "font_show.h"
#include "music.h"
#include "mp3player.h"
#include "fatfs_app.h"
#include "My_Function.h"



/*自定义初始化*/
void My_Init(void);

/*基础初始化*/
void Basic_Init(void);

/*定时器初始化*/
void MyIRQ_Init(void);

/*其它初始化*/
void Other_Init(void);

#endif




