#include "Rrtc.h"

MY_TIME calendar;

u8 table_week[12]={0,3,3,6,1,4,6,2,5,0,3,5};//星期表
u8 mon_table[12]={31,28,31,30,31,30,31,31,30,31,30,31};//月份表
//获得当前时间 0成功 其他 错误



void RTC_Init(void)
{
	int i=0;
	//1.使能电源接口，备份域接口
	RCC->APB1ENR |=(1<<27)|(1<<28);
	if(BKP->DR1 !=1)
	{
		//2.允许后备区域使能（使能备份域写入使能）
	PWR->CR  |=(1<<8);
	//3.选择时钟源LSE 32.678kHZ(复位备份域 (手动))，开启振荡器,选择时钟源）
	RCC->BDCR |=(1<<16);
	RCC->BDCR &=~(1<<16);
	
	RCC->BDCR |=(1<<0);
	for(i=0;i<20000;i++)
	{
		
	}
	//就绪振荡器就绪
	while(((RCC->BDCR & (1<<1))>>1)!=1)
	{
		
	}
	//选择LSE作为RTC的时钟源
	RCC->BDCR &=~(3<<8);
	RCC->BDCR |=(1<<8);
	
	RCC->BDCR |=(1<<15);
	
	//判断写入是否完成
	while(((RTC->CRL & (1<<5))>>5)!=1)
	{
		
	}
	//等待寄存器同步
	while(((RTC->CRL & (1<<3))>>3)!=1)
	{
		
	}
	//进入配置模式（配置分频值，开启秒中断）
	RTC->CRL |=(1<<4);
	
	RTC->PRLH=0;
	RTC->PRLL=32767;
	RTC->CRH |=(1<<0);
	//设置时间
	RTC_Set(2019,10,13,10,15,0);
	//更新时间
	RTC_Get();
	//设置BKP寄存器为配置完成
	BKP->DR1 |=1;

	}
	else
	{
		//进入配置模式（配置分频值，开启秒中断）
		RTC->CRL |=(1<<4);
		//开启秒中断
		RTC->CRH |=(1<<0);
		//判断写入是否完成
		
	}
	while(((RTC->CRL & (1<<5))>>5)!=1)
		{
			
		}
		//退出配置
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
	temp=timecount/86400; //获得天数
	if(daycnt!=temp)//超过一天
	{
		daycnt=temp;
		temp1=1970; //存储年份 1970开始
		while(temp>=365)
		{
			if(Is_Leap_Year(temp1))//是否闰年
			{
				if(temp>=366)
					temp-=366;//闰年的秒数
				else
				{
					temp1++;
					break;
				}
			}
			else 	
				temp-=365; //平年
			temp1++;
		}
		calendar.w_year=temp1;//获得年份
		temp1=0; //存储月份 1970开始
		while(temp>=28)//超过一个月
		{
			if(Is_Leap_Year(calendar.w_year)&&temp1==1)//是否为闰年二月
			{
				if(temp>=29)
					temp-=29;//闰年秒数
				else 
					break;
			}
			else
			{
				if(temp>=mon_table[temp1])
					temp-=mon_table[temp1];//平年月份
				else 
					break;
			}
			temp1++;
		}
		calendar.w_month=temp1+1; //月份
		calendar.w_date=temp+1; //日期
	}
	temp=timecount%86400; //获得秒数
	calendar.hour=temp/3600; //小时
	calendar.min=(temp%3600)/60; //分钟
	calendar.sec=(temp%3600)%60; //秒钟
	calendar.week=RTC_Get_Week(calendar.w_year,calendar.w_month,calendar.w_date);//获取星期
	return 0;
}

u8 RTC_Get_Week(u16 year,u8 month,u8 day)
{	
	u16 temp2;
	u8 yearH,yearL;

	yearH=year/100;	yearL=year%100; 
	// 如果为21世纪,年份数加100  
	if (yearH>19)yearL+=100;
	// 所过闰年数只算1900年之后的  
	temp2=yearL+yearL/4;
	temp2=temp2%7; 
	temp2=temp2+day+table_week[month-1];
	if (yearL%4==0&&month<3)temp2--;
	return(temp2%7);
}	
//闰年判断
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
	for(t=1970;t<syear;t++)	//把所有年份的秒钟相加
	{
		if(Is_Leap_Year(t))seccount+=31622400;//闰年的秒钟数
		else seccount+=31536000;			  //平年的秒钟数
	}
	smon-=1;
	for(t=0;t<smon;t++)	   //把前面月份的秒钟数相加
	{
		seccount+=(u32)mon_table[t]*86400;//月份秒钟数相加
		if(Is_Leap_Year(syear)&&t==1)seccount+=86400;//闰年2月份增加一天的秒钟数	   
	}
	seccount+=(u32)(sday-1)*86400;//把前面日期的秒钟数相加 
	seccount+=(u32)hour*3600;//小时秒钟数
	seccount+=(u32)min*60;	 //分钟秒钟数
	seccount+=sec;//最后的秒钟加上去 			    
	//设置时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);	//使能PWR和BKP外设时钟   
	//PWR_BackupAccessCmd(ENABLE);	//使能后备寄存器访问  
	PWR->CR |=(1<<8);
	//上面三步是必须的!

	RTC_SetAlarm(seccount);
	RTC_WaitForLastTask();	//等待最近一次对RTC寄存器的写操作完成  	

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
			seccount+=31622400;//闰年秒数
		else 
			seccount+=31536000; //平年秒数
	}
	smon-=1;
	for(t=0;t<smon;t++) 
	{
		seccount+=(u32)mon_table[t]*86400;
		if(Is_Leap_Year(syear)&&t==1)//闰年加一天秒数
			seccount+=86400;
	}
	seccount+=(u32)(sday-1)*86400;
	seccount+=(u32)hour*3600;
	seccount+=(u32)min*60; 
	seccount+=sec;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP,ENABLE); //使能PWR、BKP
	PWR->CR |=(1<<8);
	//PWR_BackupAccessCmd(ENABLE); //使能访问RTC
	RTC_SetCounter(seccount); //设置RTC计数器值
	RTC_WaitForLastTask(); //等待操作完成
	return 0;
}
void itoa(int i,char* str)
{
	int power=0,j=0;
	j=i;//j存放整型数据
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
void RTC_ShowTime(void)//RTC显示系统时间
{
	char year[20];
	char time2[20]={'\0'};
	char month[5];
	char data[5];
	char hour[5];
	char min[5];
	char sec[5];

	RTC_Get();//更新时间

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
