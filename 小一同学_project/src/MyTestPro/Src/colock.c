#include "colock.h"

CLOCKS My_Colock[CLOCKNUM];
CLOCKS My_ColockSava[1];
u8 Clock_num=0;
u8 Clock_Sava=0;

void Colock_Init(CLOCKS My_Clock[CLOCKNUM])
{
	u8 Count=0;
	for(Count=0;Count<CLOCKNUM;Count++)
	{
		My_Clock[Count].hour=0;
		My_Clock[Count].min=0;
		My_Clock[Count].isRepeat=CLOCK_NOREPEAT;
		My_Clock[Count].isEnable=CLOCK_DISABLE;
		My_Clock[Count].isOpen=CLOCK_CLOSE;
		My_Clock[Count].Ring=0;
		My_Clock[Count].isRing=CLOCK_NORING;
		My_Clock[Count].Event_pHandle=0;
	}
}

void Clock_Install(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum,u8 hour,u8 min,u8 isRepeat,pHandle EvevtpHandle)
{
		My_Clock[ClockNum].hour=hour;
		My_Clock[ClockNum].min=min;
		My_Clock[ClockNum].isRepeat=CLOCK_NOREPEAT;
		My_Clock[ClockNum].isEnable=CLOCK_ENABLE;
		My_Clock[ClockNum].isOpen=CLOCK_CLOSE;
		My_Clock[ClockNum].Ring=0;
		My_Clock[ClockNum].isRing=CLOCK_NORING;
		My_Clock[ClockNum].Event_pHandle=EvevtpHandle;
}

void Clock_Open(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum)
{
		My_Clock[ClockNum].isOpen=CLOCK_OPEN;
		My_Clock[ClockNum].isRing=CLOCK_NORING;
}


void Clock_Close(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum)
{
		My_Clock[ClockNum].isOpen=CLOCK_CLOSE;
}


//闹钟重新利用
void Clock_Destory(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum)
{
	My_Clock[ClockNum].isEnable=CLOCK_DISABLE;
}


//闹钟管理
void CLock_Manager()
{
	u8 Count=0;
	for(Count=0;Count<CLOCKNUM;Count++)
	{
		if(( My_Colock[Count].isEnable==CLOCK_ENABLE) && (My_Colock[Count].isOpen==CLOCK_OPEN)&&(My_Colock[Count].isRing==CLOCK_NORING)&& (My_Colock[Count].hour==calendar.hour)&& (My_Colock[Count].min==calendar.min))
		{
				My_Colock[Count].Event_pHandle();
				My_Colock[Count].isRing=CLOCK_RING;
				if((My_Colock[Count].isRepeat==CLOCK_NOREPEAT)&&(My_Colock[Count].isRing==CLOCK_RING))
				{
					My_Colock[Count].isOpen=CLOCK_CLOSE;
				}
		}
	}
}


void Show_Clock(u16 x,u16 y,pCLOCKS My_Colock)
{
	char time[20]={'\0'};
	char hour[5]={'\0'};
	char min[5]={'\0'};
	
	itoa(My_Colock->hour,hour);
	itoa(My_Colock->min,min);
	
	if(My_Colock->hour< 10)
	strcat(time,"0");
	strcat(time,hour);
	strcat(time,":");
	
	if(My_Colock->min< 10)
	strcat(time ,"0");
	strcat(time,min);
	
	LCD_ShowString(x,y,time,24,BLACK,WHITE);
	LCD_ShowString(x+64,y,"|",24,BLACK,WHITE);
	if(My_Colock->isOpen==CLOCK_OPEN)
	{
		LCD_ShowFont16Char(x+80,y,"已开启",BLACK,WHITE);
	}
	else if(My_Colock->isOpen==CLOCK_CLOSE)
	{
		LCD_ShowFont16Char(x+80,y,"未开启",GRAY,WHITE);
	}
	LCD_ShowString(x+150,y,"|",24,BLACK,WHITE);
	if(My_Colock->isRepeat==CLOCK_REPEAT)
	{
		LCD_ShowFont16Char(x+6,y+24,"每天",BLACK,WHITE);
	}
	else if(My_Colock->isRepeat==CLOCK_NOREPEAT)
	{
		LCD_ShowFont16Char(x+6,y+24,"永不",BLACK,WHITE);
	} 
	if(My_Colock->isOpen==CLOCK_OPEN)
	{
		LCD_ShowPicture(x+90,y+24,48,24,gImage_ON);
	}
	else if(My_Colock->isOpen==CLOCK_CLOSE)
	{
		LCD_ShowPicture(x+90,y+24,48,24,gImage_OFF);
	}
	LCD_Fill(x+155,y,x+210,y+49,RED);
	LCD_ShowFont16Char(x+158,y+12,"删除",BLACK,RED);
	LCD_DrawLine_Color(x,y+50,x+210,y+50,BLACK);
}

void My_Show_Clock()
{
		u8 Count=0;
		for(Count=0;Count<CLOCKNUM;Count++)
		{
			if(My_Colock[Count].isEnable==CLOCK_ENABLE)
			{
				Show_Clock(15,64*(Count+1)-10,&My_Colock[Count]);
			}
		}
		delay_ms(300);
}

void Change_Clock_Background()
{		
		LCD_Fill(0,25,239,369,WHITE);
		LCD_ShowFont16Char(80,24,"设置闹钟",BLACK,WHITE);
		LCD_DrawLine_Color(0, 24+20,239 ,24+20,BLACK);
		Show_Clock(15,64-10,My_ColockSava);
		Show_NextNum(71,108,My_ColockSava->hour,0,23);
		LCD_ShowString(71+41,108+24*2-1,":",24,BLACK,WHITE);
		Show_NextNum(71+48,108,My_ColockSava->min,0,59);
		LCD_DrawLine_Color(15,230,225,230,BLACK);
		LCD_ShowFont16Char(24,231+6,"重复：",BLACK,WHITE);
		if(My_ColockSava->isRepeat==CLOCK_REPEAT)
		{
			LCD_ShowFont16Char(120,231+6,"每天",GREEN,WHITE);
			LCD_ShowFont16Char(175,231+6,"永不",GRAY,WHITE);
		}
		else if(My_ColockSava->isRepeat==CLOCK_NOREPEAT)
		{
			LCD_ShowFont16Char(120,231+6,"每天",GRAY,WHITE);
			LCD_ShowFont16Char(175,231+6,"永不",GREEN,WHITE);
		}
		LCD_DrawLine_Color(15,230+36,225,230+36,BLACK);
		LCD_ShowFont16Char(24,231+36+6,"铃声：",BLACK,WHITE);
		if(My_ColockSava->Ring==0)
		{
			LCD_ShowFont16Char(120,231+36+6,"开场",GREEN,WHITE);
			LCD_ShowFont16Char(175,231+36+6,"仲夏",GRAY,WHITE);
		}
		else if(My_ColockSava->Ring==1)
		{
			LCD_ShowFont16Char(120,231+36+6,"开场",GRAY,WHITE);
			LCD_ShowFont16Char(175,231+36+6,"仲夏",GREEN,WHITE);
		}
		LCD_DrawLine_Color(15,230+36*2,225,230+36*2,BLACK);
		LCD_ShowFont16Char(24,231+36*2+6,"【取消】",BLACK,WHITE);
		LCD_ShowFont16Char(127,231+36*2+6,"【保存】",BLACK,WHITE);
		LCD_DrawLine_Color(15,230+36*3,225,230+36*3,BLACK);
		delay_ms(300);
}
 

void Add_Clock()
{
	for(Clock_num=0;Clock_num<CLOCKNUM;Clock_num++)
	{
		if((My_Colock[Clock_num].isEnable==CLOCK_DISABLE))
		{
				break;
		}
	}
	if(Clock_num>=CLOCKNUM)
	{
		Busy("闹钟已满！请删除部分闹钟！");
	}
	else
	{
		Clock_Sava=0;
		Clock_Install(My_Colock,Clock_num,calendar.hour,calendar.min,CLOCK_REPEAT,Clock_Sound);
		Change_Clock(&My_Colock[Clock_num]);
			if(Clock_Sava==0)
		{
			My_DeleteClock2();
		}
		Exit_Flag=0;
		colock_BackGround();
	}
}

void Change_Clock(pCLOCKS My_Colock)
{
	memcpy(My_ColockSava,My_Colock,SIZEOFCLOCKS);
	Change_Clock_Background();
	Exit_Flag=0;
	while(!Exit_Flag)
	{
		TOUCH_Scan();
		Eevent_Touch(pChangeColock);
		Event_Manager(pChangeColock);
	}
}

void My_ChangeClock(void)
{
	Clock_num=(TouchData.lcdy+10)/64-1;
	if((My_Colock[Clock_num].isEnable==CLOCK_ENABLE))
	{
		Change_Clock(&My_Colock[Clock_num]);
		Exit_Flag=0;
		colock_BackGround();
	}
}

void My_OpenClock(void)
{
	Clock_num=(TouchData.lcdy+10)/64-1;
	if((My_Colock[Clock_num].isEnable==CLOCK_ENABLE)&&(My_Colock[Clock_num].isOpen==CLOCK_OPEN))
	{
		Clock_Close(My_Colock,Clock_num);
		colock_BackGround();
	}
	else if((My_Colock[Clock_num].isEnable==CLOCK_ENABLE)&&(My_Colock[Clock_num].isOpen==CLOCK_CLOSE))
	{
		Clock_Open(My_Colock,Clock_num);
		colock_BackGround();
	}	
}

void My_DeleteClock(void)
{
	Clock_num=(TouchData.lcdy+10)/64-1;
	if((My_Colock[Clock_num].isEnable==CLOCK_ENABLE))
	{
		Clock_Destory(My_Colock,Clock_num);
		LCD_Fill(0,45,239,369,WHITE);
		Clock_UpLine();
		colock_BackGround();
	}
}

void My_OpenClock2(void)
{
	if((My_ColockSava->isEnable==CLOCK_ENABLE)&&(My_ColockSava->isOpen==CLOCK_OPEN))
	{
		Clock_Close(My_ColockSava,1);
		LCD_ShowFont16Char(95,54,"未开启",GRAY,WHITE);
		LCD_ShowPicture(105,78,48,24,gImage_OFF);
	}
	else if((My_ColockSava->isEnable==CLOCK_ENABLE)&&(My_ColockSava->isOpen==CLOCK_CLOSE))
	{
		Clock_Open(My_ColockSava,1);
		LCD_ShowFont16Char(95,54,"已开启",BLACK,WHITE);
		LCD_ShowPicture(105,78,48,24,gImage_ON);
	}	
	delay_ms(200);
}

void My_DeleteClock2(void)
{
	if((My_Colock[Clock_num].isEnable==CLOCK_ENABLE))
	{
		Clock_Destory(My_Colock,Clock_num);
		Clock_UpLine();
		Exit();
	}
	colock_BackGround();
	delay_ms(100);
}

void My_ChangeHour_Up()
{
	if(My_ColockSava->hour==23)
	{
		My_ColockSava->hour=0;
	}
	else
	{
		My_ColockSava->hour++;
	}
	Show_NextNum(71,108,My_ColockSava->hour,0,23);
	delay_ms(100);
}

void My_ChangeHour_Down()
{
	if(My_ColockSava->hour==0)
	{
		My_ColockSava->hour=23;
	}
	else
	{
		My_ColockSava->hour--;
	}
	Show_NextNum(71,108,My_ColockSava->hour,0,23);
	delay_ms(100);
}

void My_ChangeMin_Up()
{
	if(My_ColockSava->min==59)
	{
		My_ColockSava->min=0;
	}
	else
	{
		My_ColockSava->min++;
	}
	Show_NextNum(71+48,108,My_ColockSava->min,0,59);
	delay_ms(100);
}

void My_ChangeMin_Down()
{
	if(My_ColockSava->min==0)
	{
		My_ColockSava->min=59;
	}
	else
	{
		My_ColockSava->min--;
	}
	Show_NextNum(71+48,108,My_ColockSava->min,0,59);
	delay_ms(100);
}


void My_ChangeRepeat_Daily()
{
	My_ColockSava->isRepeat=CLOCK_REPEAT;
	LCD_ShowFont16Char(120,231+6,"每天",GREEN,WHITE);
	LCD_ShowFont16Char(175,231+6,"永不",GRAY,WHITE);
	delay_ms(100);
}

void My_ChangeRepeat_OnlyOne()
{
	My_ColockSava->isRepeat=CLOCK_NOREPEAT;
	LCD_ShowFont16Char(120,231+6,"每天",GRAY,WHITE);
	LCD_ShowFont16Char(175,231+6,"永不",GREEN,WHITE);
	delay_ms(100);
}

void My_ChangeRing_KC()
{
	My_ColockSava->Ring=0;
	LCD_ShowFont16Char(120,231+36+6,"开场",GREEN,WHITE);
	LCD_ShowFont16Char(175,231+36+6,"仲夏",GRAY,WHITE);
	delay_ms(100);
}

void My_ChangeRing_ZX()
{
	My_ColockSava->Ring=1;
	LCD_ShowFont16Char(120,231+36+6,"开场",GRAY,WHITE);
	LCD_ShowFont16Char(175,231+36+6,"仲夏",GREEN,WHITE);
	delay_ms(100);
}

void My_Cancel()
{
	LCD_ShowFont16Char(24,231+36*2+6,"【取消】",YELLOW,WHITE);
	delay_ms(300);
	Exit();
}

void My_Save()
{
	LCD_ShowFont16Char(127,231+36*2+6,"【保存】",YELLOW,WHITE);
	delay_ms(300);
	memcpy(&My_Colock[Clock_num],My_ColockSava,SIZEOFCLOCKS);
	My_Colock[Clock_num].isRing=CLOCK_NORING;
	Clock_Sava=1;
	Exit();
}


void Clock_UpLine()
{
	u8 Count=0;
	for(Count=0;Count<CLOCKNUM;Count++)
	{
		if(My_Colock[Count].isEnable==CLOCK_DISABLE)
		{
			if(Count!=CLOCKNUM-1)
			{
				memcpy(&My_Colock[Count],&My_Colock[Count+1],SIZEOFCLOCKS);
				My_Colock[Count+1].isEnable=CLOCK_DISABLE;
			}
		}
	}
}


void Clock_Sound()
{
	Busy("主人，闹钟已经响起！！");
		if(My_Colock[Clock_num].Ring==0)
	{
		Buzzer_Lien();
		Buzzer_Lien();
		Buzzer_Lien();
	}
	else
	{
		Buzzer_Lien2();
		Buzzer_Lien2();
		Buzzer_Lien2();
	}
}
















