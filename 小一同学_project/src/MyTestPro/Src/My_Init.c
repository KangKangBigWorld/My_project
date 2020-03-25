#include "My_Init.h"



void My_Init()
{
	Basic_Init();//基础初始化
	Boot_test();//开机检测
	MyIRQ_Init();//定时器初始化
	Other_Init();//其它初始化
	
}

void Basic_Init()
{
		SysTick_Init(72);//时钟初始化
		LED_Init();//LED灯初始化
		TFTLCD_Init();//TFT屏幕初始化
		Buzzer_Init();//蜂鸣器初始化
		TOUCH_Init();//触屏初始化
		
}


void MyIRQ_Init()
{
	IRQ_Init();//中断初始化
	KEY_Irq_Init();//按键中断初始化
	TIME_Init();//硬定时器TIM2-5初始化
	TIMER_TS_Init();//软中断初始化
}

void Other_Init()
{
		DHT11_Init();//温度传感器初始化
		USART1_Init();//串口初始化
		RTC_Init();//RTC时钟初始化
		//外部Flash初始化
	EN25QXX_Init();     //在flash.c中
	my_mem_init(SRAMIN);  //在malloc.c中
	f_mount(fs[1],"1:",1);  //挂在FLASH
	FontUpdate(GUI_UPDATE_ALL); //在font_show.c中 把SD卡内的字库写入FLASH
	
	FATFS_Init();//扫描SD卡
	MP3_Init();//mp3初始化
	Music_Init();//音乐初始化
	My_Music_init();//我的音乐初始化
	KeyBorad_Init();//键盘初始化
	My_Event_Init();//事件初始化
}

