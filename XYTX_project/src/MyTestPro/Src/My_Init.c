#include "My_Init.h"



void My_Init()
{
	Basic_Init();//������ʼ��
	Boot_test();//�������
	MyIRQ_Init();//��ʱ����ʼ��
	Other_Init();//������ʼ��
	
}

void Basic_Init()
{
		SysTick_Init(72);//ʱ�ӳ�ʼ��
		LED_Init();//LED�Ƴ�ʼ��
		TFTLCD_Init();//TFT��Ļ��ʼ��
		Buzzer_Init();//��������ʼ��
		TOUCH_Init();//������ʼ��
		
}


void MyIRQ_Init()
{
	IRQ_Init();//�жϳ�ʼ��
	KEY_Irq_Init();//�����жϳ�ʼ��
	TIME_Init();//Ӳ��ʱ��TIM2-5��ʼ��
	TIMER_TS_Init();//���жϳ�ʼ��
}

void Other_Init()
{
		DHT11_Init();//�¶ȴ�������ʼ��
		USART1_Init();//���ڳ�ʼ��
		RTC_Init();//RTCʱ�ӳ�ʼ��
		//�ⲿFlash��ʼ��
	EN25QXX_Init();     //��flash.c��
	my_mem_init(SRAMIN);  //��malloc.c��
	f_mount(fs[1],"1:",1);  //����FLASH
	FontUpdate(GUI_UPDATE_ALL); //��font_show.c�� ��SD���ڵ��ֿ�д��FLASH
	
	FATFS_Init();//ɨ��SD��
	MP3_Init();//mp3��ʼ��
	Music_Init();//���ֳ�ʼ��
	My_Music_init();//�ҵ����ֳ�ʼ��
	KeyBorad_Init();//���̳�ʼ��
	My_Event_Init();//�¼���ʼ��
}

