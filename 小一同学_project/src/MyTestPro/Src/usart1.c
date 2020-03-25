#include "usart1.h"
#include "My_Function.h"
#include "Rrtc.h"
#include "stdio.h"

my_TIME Time_Set = {0};
char CmdStr[32] = {0};
void USART1_Init()
{
	//usart1 paʱ������ʹ��
	RCC->APB2ENR |=(1<<14)|(1<<2);
	
	//GPIOA PA9(TX ��� ���������������) PA10(RX ���� (��������ģʽ))
	GPIOA->CRH &=~(0xFF<<4);
	GPIOA->CRH |=(0x4B<<4);
	
	//�����ʣ�����λ��ֹͣλ����żУ�飨Ĭ�ϣ���Ӳ���������䣩
	//������:�����ֲ�25.3.4�Ĺ�ʽ��USARTDTV=468.75 ��λ����0.75*16=12���������9600 ��Ҫ�� 486 12��
	USART1->BRR |=(468<<4)|(12<<0);
	//����λ��8
	USART1->CR1 &=~(1<<12);
	//ֹͣλ1
	USART1->CR2 &=~(3<<12);
	//��ʹ����żУ��
	USART1->CR1 &=~(1<<10);
	//������Ӳ����
	USART1->CR3 &=~(1<<8);
	
	//�����ж�
	USART1->CR1 |=(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<13);
	
	NVIC->ISER[1] |=(1<<(USART1_IRQn-32));
	IRQ_Install(USART1_IRQn,USART1_pHandle);
}
char ch='0';
char string[MAX_STR]={'\0'};
char* pStr=string;
void USART1_pHandle()
{
	char clear;
	if(!(((USART1->SR &(1<<4))>>4)==1))
	{
		*pStr=USART1_GetChar();	
		pStr++;
	}
	else
	{
		*pStr='\0';
		if(strstr(string,"GetTime"))//��ȡʱ��
		{
			My_GetTime("��ȡʱ��");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"SetTime"))
		{
			sscanf(string, "<SetTime,%d-%d-%d,%d:%d:%d>", &Time_Set.w_year, &Time_Set.w_month, &Time_Set.w_date, &Time_Set.hour, &Time_Set.min, &Time_Set.sec);
			if(Time_Set.w_year<1970 || (Time_Set.w_month<=0 || Time_Set.w_month>12) || (Time_Set.w_date<1||Time_Set.w_date>31) || (Time_Set.hour<0 || Time_Set.hour>23) \
				|| (Time_Set.min<0) || (Time_Set.min>59) || (Time_Set.sec<0 || Time_Set.sec>59))
			{
				USART1_PutStr("������ĸ�ʽ��ʱ�������⣬����������\r\n");
			}
			else
			{
				RTC_Set(Time_Set.w_year, Time_Set.w_month, Time_Set.w_date, Time_Set.hour, Time_Set.min, Time_Set.sec);
				My_GetTime("����ʱ��");
				USART1_PutStr("\r\n");
			}
		}
		else if(strstr(string,"ReadMem"))
		{
			Read_Mem(string);
		}
		else if(strstr(string,"WriteMem"))
		{
			Write_Mem(string);
		}
		else if(strstr(string,"SendFile"))
		{
			Busy("����ɨ���ļ���");
			USART1_PutStr("����ɨ���ļ�\r\n");
			delay_ms(300);
			Busy("���ڵȴ������ļ���");
			USART1_PutStr("���ڵȴ������ļ�\r\n");
			delay_ms(300);
			Busy("���ڽ����ļ�");
			USART1_PutStr("���ڽ����ļ�\r\n");
			delay_ms(1000);
			Busy("�ɹ������ļ�");
			USART1_PutStr("�ɹ������ļ�\r\n");
			delay_ms(300);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Reset"))
		{
			Busy("ϵͳ�������������");
			USART1_PutStr("ϵͳ�������������\r\n");
			delay_ms(1000);
			Busy("ϵͳ�������������");
			USART1_PutStr("ϵͳ�������������\r\n");
			delay_ms(1000);
			Busy("ϵͳһ�����������");
			USART1_PutStr("ϵͳһ�����������\r\n");
			delay_ms(1000);
			Soft_Reset();//����
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Here"))
		{
			USART1_PutStr("I am here,waiting for you.\r\n");//����
			Busy("���������������");
		}
		else if(strstr(string,"LedOff"))
		{
			LED_CloseAll();//�ص�
			Busy("�ص�");
			USART1_PutStr("\r\n");	
			USART1_PutStr("�صƳɹ�");
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"LedOn"))
		{
			LED_OpenAll();//����
			Busy("����");
			USART1_PutStr("\r\n");	
			USART1_PutStr("���Ƴɹ�");
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"GiveTime"))//��ȡʱ��
		{
			My_GetTime("��ȡʱ��");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"AlarmAdd"))
		{
			Exit_Flag=1;
			Event_Open(pMainEvents,3);
			Event_Open(pColock,1);
			USART1_PutStr(string);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Music"))
		{
			Exit_Flag=1;
			Event_Open(pMainEvents,1);
			USART1_PutStr(string);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Clock"))
		{
			Exit_Flag=1;
			Event_Open(pMainEvents,3);
			USART1_PutStr(string);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Temperature And Humidity"))
		{
			Exit_Flag=1;
			Event_Open(pMainEvents,2);
			USART1_PutStr(string);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Txt"))
		{
			Exit_Flag=1;
			Event_Open(pMainEvents,0);
			USART1_PutStr(string);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		else if(strstr(string,"Hello"))
		{
			Busy("��ӭ��������ת��,ע�����");
			USART1_PutStr(string);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
			delay_ms(1000);
		}
		else
		{
			USART1_PutStr("�޷�ʶ���ָ��,���Ķ�ʹ���ֲ�.\r\n");
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			USART1_PutStr("\r\n");
		}
		//USART1_PutStr(string);
		//USART1_PutChar('\0');
		pStr=string;
		clear=USART1->SR;
		clear=USART1->DR;
	}
}

//��ȡ��������
u8 USART1_GetChar()
{
	return USART1->DR;
}

void USART1_GetStr(char* str)
{
	while(!(((USART1->SR &(1<<4))>>4)==1))
	{
		*str=USART1->DR;
		str++;
	}
	*str='\0';
}

void USART1_PutChar(char ch)
{
	while(!(USART1->SR & (1<<6)))
	{
		//�ж��Ƿ�ʼ��ȡ
	}
	USART1->DR=ch;
	
}
void USART1_PutStr(char* str)
{
	while(*str != '\0')
	{
		USART1_PutChar(*str);
		str++;
	}
}

void Soft_Reset(void)
{
	__set_FAULTMASK(1);//�ر������ж�
	NVIC_SystemReset();//��λ
}


void Read_Mem(char *CmdStr)
{
			u8 i = 0, cnt = 0;
	u32	address = 0;
	u16 length = 0;
	char dat;
	char dat_str[5] = {0};
	char addr_str[24];
	char tip[44];
	char re_time[32] = {0};
	sscanf(CmdStr,"%*9s%s",re_time);
	sscanf(re_time,"%x,%d", &address, &length);
	sprintf(tip,"��0x%x��ַ,��ȡ%d���ֽ�:\r\n",address,length);
	USART1_PutStr(tip);
	sprintf(addr_str, "0x%x: ", address);
	USART1_PutStr(addr_str);
	for(i = 0; i < length; i++)
	{
		cnt++;
		if(cnt>10)
		{
			cnt = 1;
			USART1_PutStr("\r\n");
			sprintf(addr_str, "0x%x: ", address);
			USART1_PutStr(addr_str);
		}
		dat = *((char *)address);
		sprintf(dat_str, "%02x ", dat);
		USART1_PutStr(dat_str);
		address++;
	}
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
	
}
void Write_Mem(char *CmdStr)
{
	u32 address;
	u8 i = 0;
	char tip[44];
	char dat[64] = {0};
	char re_time[32] = {0};
	sscanf(CmdStr,"%*10s%s",re_time);
	sscanf(re_time, "%x,%s>", &address, dat);
	sprintf(dat, "%s", &dat[1]);
	dat[strlen(dat)-2] = '\0';
	while(dat[i] != '\0')
	{
		*((char *)address) = dat[i];
		address++;
		i++;
	}
	sprintf(tip,"��0x%x��ַ,д��%d���ֽ�:\r\n",address,sizeof(dat));
	USART1_PutStr("\r\n");
	USART1_PutStr(tip);
	USART1_PutStr("\r\n");
	USART1_PutStr("д�����ݳɹ�");	
	USART1_PutStr("\r\n");	
	USART1_PutStr("OK");
}

void My_GetTime(char* Str)
{
			char my_year[20];
			char time2[20]={'\0'};
			char month[5];
			char data[5];
			char hour[5];
			char min[5];
			char sec[5];
			char MyPut[40]={'/0'};

			RTC_Get();//����ʱ��

			itoa(calendar.w_year,my_year);
			itoa(calendar.w_month,month);
			itoa(calendar.w_date,data);
			itoa(calendar.hour,hour);
			itoa(calendar.min,min);
			itoa(calendar.sec,sec);

			strcat(my_year,"-");
			strcat(my_year,month);
			strcat(my_year,"-");
			strcat(my_year,data);
			strcat(my_year," ");

			if(calendar.hour < 10)
				strcat(time2,"0");	
			strcat(time2,hour);
			strcat(time2,":");
			if(calendar.min < 10)
				strcat(time2,"0");	
			strcat(time2,min);
			strcat(time2,":");
			if(calendar.sec < 10)
				strcat(time2,"0");		
			 strcat(time2,sec);
			memcpy(MyPut,Str,strlen(Str));
			strcat(MyPut,my_year);
			strcat(MyPut,time2);
			USART1_PutStr(Str);
			USART1_PutStr(my_year);
			USART1_PutStr(time2);
			USART1_PutStr("\r\n");	
			USART1_PutStr("OK");
			Busy(MyPut);
}



