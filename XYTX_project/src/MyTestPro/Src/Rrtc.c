#include "Rrtc.h"

MY_TIME calendar;

u8 table_week[12]={0,3,3,6,1,4,6,2,5,0,3,5};//���ڱ�
u8 mon_table[12]={31,28,31,30,31,30,31,31,30,31,30,31};//�·ݱ�
//��õ�ǰʱ�� 0�ɹ� ���� ����



void RTC_Init(void)
{
	int i=0;
	//1.ʹ�ܵ�Դ�ӿڣ�������ӿ�
	RCC->APB1ENR |=(1<<27)|(1<<28);
	if(BKP->DR1 !=1)
	{
		//2.���������ʹ�ܣ�ʹ�ܱ�����д��ʹ�ܣ�
	PWR->CR  |=(1<<8);
	//3.ѡ��ʱ��ԴLSE 32.678kHZ(��λ������ (�ֶ�))����������,ѡ��ʱ��Դ��
	RCC->BDCR |=(1<<16);
	RCC->BDCR &=~(1<<16);
	
	RCC->BDCR |=(1<<0);
	for(i=0;i<20000;i++)
	{
		
	}
	//������������
	while(((RCC->BDCR & (1<<1))>>1)!=1)
	{
		
	}
	//ѡ��LSE��ΪRTC��ʱ��Դ
	RCC->BDCR &=~(3<<8);
	RCC->BDCR |=(1<<8);
	
	RCC->BDCR |=(1<<15);
	
	//�ж�д���Ƿ����
	while(((RTC->CRL & (1<<5))>>5)!=1)
	{
		
	}
	//�ȴ��Ĵ���ͬ��
	while(((RTC->CRL & (1<<3))>>3)!=1)
	{
		
	}
	//��������ģʽ�����÷�Ƶֵ���������жϣ�
	RTC->CRL |=(1<<4);
	
	RTC->PRLH=0;
	RTC->PRLL=32767;
	RTC->CRH |=(1<<0);
	//����ʱ��
	RTC_Set(2019,10,13,10,15,0);
	//����ʱ��
	RTC_Get();
	//����BKP�Ĵ���Ϊ�������
	BKP->DR1 |=1;

	}
	else
	{
		//��������ģʽ�����÷�Ƶֵ���������жϣ�
		RTC->CRL |=(1<<4);
		//�������ж�
		RTC->CRH |=(1<<0);
		//�ж�д���Ƿ����
		
	}
	while(((RTC->CRL & (1<<5))>>5)!=1)
		{
			
		}
		//�˳�����
		RTC->CRL &=~(1<<4);
	IRQ_Install(RTC_IRQn,RTC_pHandle);
}


void RTC_pHandle(void)
{
	RTC_ShowTime();
}


/*-------------------------------------------------------------------------------------------------------------*/

u8 RTC_Get(void)
{
	static u16 daycnt=0;
	u32 timecount=0;
	u32 temp=0;
	u16 temp1=0;

	timecount=RTC_GetCounter();
	temp=timecount/86400; //�������
	if(daycnt!=temp)//����һ��
	{
		daycnt=temp;
		temp1=1970; //�洢��� 1970��ʼ
		while(temp>=365)
		{
			if(Is_Leap_Year(temp1))//�Ƿ�����
			{
				if(temp>=366)
					temp-=366;//���������
				else
				{
					temp1++;
					break;
				}
			}
			else 	
				temp-=365; //ƽ��
			temp1++;
		}
		calendar.w_year=temp1;//������
		temp1=0; //�洢�·� 1970��ʼ
		while(temp>=28)//����һ����
		{
			if(Is_Leap_Year(calendar.w_year)&&temp1==1)//�Ƿ�Ϊ�������
			{
				if(temp>=29)
					temp-=29;//��������
				else 
					break;
			}
			else
			{
				if(temp>=mon_table[temp1])
					temp-=mon_table[temp1];//ƽ���·�
				else 
					break;
			}
			temp1++;
		}
		calendar.w_month=temp1+1; //�·�
		calendar.w_date=temp+1; //����
	}
	temp=timecount%86400; //�������
	calendar.hour=temp/3600; //Сʱ
	calendar.min=(temp%3600)/60; //����
	calendar.sec=(temp%3600)%60; //����
	calendar.week=RTC_Get_Week(calendar.w_year,calendar.w_month,calendar.w_date);//��ȡ����
	return 0;
}

u8 RTC_Get_Week(u16 year,u8 month,u8 day)
{	
	u16 temp2;
	u8 yearH,yearL;

	yearH=year/100;	yearL=year%100; 
	// ���Ϊ21����,�������100  
	if (yearH>19)yearL+=100;
	// ����������ֻ��1900��֮���  
	temp2=yearL+yearL/4;
	temp2=temp2%7; 
	temp2=temp2+day+table_week[month-1];
	if (yearL%4==0&&month<3)temp2--;
	return(temp2%7);
}	
//�����ж�
u8 Is_Leap_Year(u16 year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
u8 RTC_Alarm_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec)
{
	u16 t;
	u32 seccount=0;
	if(syear<1970||syear>2099)return 1;	   
	for(t=1970;t<syear;t++)	//��������ݵ��������
	{
		if(Is_Leap_Year(t))seccount+=31622400;//�����������
		else seccount+=31536000;			  //ƽ���������
	}
	smon-=1;
	for(t=0;t<smon;t++)	   //��ǰ���·ݵ����������
	{
		seccount+=(u32)mon_table[t]*86400;//�·����������
		if(Is_Leap_Year(syear)&&t==1)seccount+=86400;//����2�·�����һ���������	   
	}
	seccount+=(u32)(sday-1)*86400;//��ǰ�����ڵ���������� 
	seccount+=(u32)hour*3600;//Сʱ������
	seccount+=(u32)min*60;	 //����������
	seccount+=sec;//�������Ӽ���ȥ 			    
	//����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);	//ʹ��PWR��BKP����ʱ��   
	//PWR_BackupAccessCmd(ENABLE);	//ʹ�ܺ󱸼Ĵ�������  
	PWR->CR |=(1<<8);
	//���������Ǳ����!

	RTC_SetAlarm(seccount);
	RTC_WaitForLastTask();	//�ȴ����һ�ζ�RTC�Ĵ�����д�������  	

	return 0;	    
}
u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec)
{
	u16 t;
	u32 seccount=0;
	if(syear<1970||syear>2099)
		return 1;
	for(t=1970;t<syear;t++) 
	{
		if(Is_Leap_Year(t))
			seccount+=31622400;//��������
		else 
			seccount+=31536000; //ƽ������
	}
	smon-=1;
	for(t=0;t<smon;t++) 
	{
		seccount+=(u32)mon_table[t]*86400;
		if(Is_Leap_Year(syear)&&t==1)//�����һ������
			seccount+=86400;
	}
	seccount+=(u32)(sday-1)*86400;
	seccount+=(u32)hour*3600;
	seccount+=(u32)min*60; 
	seccount+=sec;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP,ENABLE); //ʹ��PWR��BKP
	PWR->CR |=(1<<8);
	//PWR_BackupAccessCmd(ENABLE); //ʹ�ܷ���RTC
	RTC_SetCounter(seccount); //����RTC������ֵ
	RTC_WaitForLastTask(); //�ȴ��������
	return 0;
}
void itoa(int i,char* str)
{
	int power=0,j=0;
	j=i;//j�����������
	for (power=1;j>=10;j/=10)
	{
		power *= 10;
	}
	for(;power>0;power/=10)
	{
		*str ++='0'+i/power;
		i%=power;
	}
	*str = '\0';
}
void RTC_ShowTime(void)//RTC��ʾϵͳʱ��
{
	char year[20];
	char time2[20]={'\0'};
	char month[5];
	char data[5];
	char hour[5];
	char min[5];
	char sec[5];

	RTC_Get();//����ʱ��

	itoa(calendar.w_year,year);
	itoa(calendar.w_month,month);
	itoa(calendar.w_date,data);
	itoa(calendar.hour,hour);
	itoa(calendar.min,min);
	itoa(calendar.sec,sec);

	strcat(year,"-");
	strcat(year,month);
	strcat(year,"-");
	strcat(year,data);
	strcat(year," ");

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

	LCD_ShowString(180,0,year,12,BLACK,CYAN);
	LCD_ShowString(185,12,time2,12,BLACK,CYAN);
}
