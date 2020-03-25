#include "My_Music.h"


MUSIC My_Music[MUSICNUM];
MUSIC My_Music2[MUSICNUM];
char MusicName[20];
u8 NameNum=0;
u8 Keyboard_Music=0;
u8 Musicnum=0;
u8 Musicnum2=0;
u8 MusicPlay=0;
u8 MusicExit=1;
u32 VolumeNum=150;

void kong()
{
	
}
void My_Music_Init(MUSIC My_Music[MUSICNUM])
{
	u8 Count=0;
	for(Count=0;Count<MUSICNUM;Count++)
	{
		memset(My_Music[Count].name,0,SIZEOFNAME);
		memset(My_Music[Count].time,0,SIZEOFTIME);
		memset(My_Music[Count].path,0,SIZEOFPATH);
		My_Music[Count].isEnable=MUSIC_DISABLE;
		My_Music[Count].isOpen=MUSIC_CLOSE;
		My_Music[Count].Event_pHandle=0;
	}
}


void Music_Install(MUSIC My_Music[MUSICNUM],u8 MusicNum,uint8_t* name,uint8_t* time,uint8_t* path,pHandle EvevtpHandle)
{
		memcpy(My_Music[MusicNum].name,name,SIZEOFNAME);
		memcpy(My_Music[MusicNum].time,time,SIZEOFTIME);
	  memcpy(My_Music[MusicNum].path,path,SIZEOFPATH);
		My_Music[MusicNum].isEnable=MUSIC_ENABLE;
		My_Music[MusicNum].isOpen=MUSIC_CLOSE;
		My_Music[MusicNum].Event_pHandle=EvevtpHandle;
}


void MUSIC_Open(MUSIC My_Music[MUSICNUM],u8 MusicNum)
{
		My_Music[MusicNum].isOpen=MUSIC_OPEN;
}


void MUSIC_Close(MUSIC My_Music[MUSICNUM],u8 MusicNum)
{
		My_Music[MusicNum].isOpen=MUSIC_CLOSE;
}


//音乐重新利用
void MUSIC_Destory(MUSIC My_Music[MUSICNUM],u8 MusicNum)
{
	My_Music[MusicNum].isEnable=MUSIC_DISABLE;
}

//音乐下载
void MUSIC_DownLoad(MUSIC My_Music[MUSICNUM],u8 MusicNum)
{
	My_Music[MusicNum].isEnable=MUSIC_ENABLE;
}



//音乐管理
void MUSIC_Manager()
{
	u8 Count=0;
	for(Count=0;Count<MUSICNUM;Count++)
	{
		if(( My_Music[Count].isEnable==MUSIC_ENABLE) && (My_Music[Count].isOpen==MUSIC_OPEN))
		{
				My_Music[Count].Event_pHandle();
		}
	}
}

void Show_Music_Button(u16 x1,u16 y1,u16 x2,u16 y2,uint8_t *ch,u16 fg_color,u16 bg_color)
{
	LCD_Fill(x1,y1,x2,y2,bg_color);
	LCD_DrawRectangle_color(x1,y1-1,x2,y2,BLACK);
	LCD_ShowFont12Char(x1+20,y1+14,ch,fg_color,bg_color);
}

void Show_Volume(u16 x,u16 y,u16 num,u16 fg_color,u16 bg_color)
{
	char Str[15]={"Volume:"};
	char Num[5]={'\0'};
	itoa(num,Num);
	strcat(Str,Num);
	strcat(Str," ");
	LCD_ShowFont12Char(x+2,y+12,Str,fg_color,bg_color);
	LCD_DrawRectangle_color(x+100-1,y+10-1,x+200+1,y+30+1,BLACK);
	LCD_ShowString(x+82,y+10,"-",24,RED,bg_color);
	LCD_Fill(x+100,y+10,x+200,y+30,bg_color);
	LCD_Fill(x+100,y+10,x+100+num,y+30,GREEN);
	LCD_ShowString(x+220,y+10,"+",24,RED,bg_color);
}

void Show_Music_Library()
{
	LCD_ShowFont12Char(6,50,"序号",BLACK,WHITE);
	LCD_ShowFont12Char(6+48,50,"音乐名称",BLACK,WHITE);
	LCD_ShowFont12Char(12+48+96,50,"修改时间",BLACK,WHITE);
	LCD_DrawLine_Color(0,70,239,70,BLACK);
	Show_MusicLine();
	LCD_DrawLine_Color(0,193,239,193,BLACK);
	Show_Music_Button(0,194,119,234,"【Rename】",BLACK,BLUE);
	Show_Music_Button(120,194,239,234,"【Delete】",BLACK,RED);
	Iocn(24,250,48,48,gImage_last,"上一首",BLACK,WHITE);
	Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
	Iocn(168,250,48,48,gImage_next,"下一首",BLACK,WHITE);
	LCD_DrawLine_Color(0,330,239,330,BLACK);
	Show_Volume(0,331,(VolumeNum*100)/254,BLACK,WHITE);
}


void Show_MusicLine()
{
	LCD_Fill(0,72,239,72+24*5,WHITE);
	if(((Musicnum-2)>=0)&&((Musicnum-2)<=MUSICNUM)&&(My_Music[(Musicnum-2)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music(12+6,72,Musicnum-2,GRAY,WHITE);
	}
	if(((Musicnum-1)>=0)&&((Musicnum-1)<=MUSICNUM)&&(My_Music[(Musicnum-1)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music(12+6,72+24*1,Musicnum-1,BLACK,WHITE);
	}
	if(((Musicnum)>=0)&&((Musicnum)<=MUSICNUM)&&(My_Music[Musicnum].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music(12+6,72+24*2,Musicnum,RED,WHITE);
	}
	if(((Musicnum+1)>=0)&&((Musicnum+1)<=MUSICNUM)&&(My_Music[(Musicnum+1)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music(12+6,72+24*3,Musicnum+1,BLACK,WHITE);
	}
	if(((Musicnum+2)>=0)&&((Musicnum+2)<=MUSICNUM)&&(My_Music[(Musicnum+2)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music(12+6,72+24*4,Musicnum+2,GRAY,WHITE);
	}
}

void Select_MusicLine()
{
	u8 touchnum=0;
	touchnum=(TouchData.lcdy-72)/24;
	switch(touchnum)
	{
		case 0:
				{
					if(((Musicnum-2)>=0)&&(My_Music[(Musicnum-2)].isEnable==MUSIC_ENABLE))	
						{
							My_Music[Musicnum].isOpen=MUSIC_CLOSE;
							Musicnum-=2;
							MusicExit=1;
							Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
							Show_MusicLine();
						}
				}break;
		case 1:
				{
					if(((Musicnum-1)>=0)&&(My_Music[(Musicnum-1)].isEnable==MUSIC_ENABLE))	
						{
							My_Music[Musicnum].isOpen=MUSIC_CLOSE;
							Musicnum-=1;
							MusicExit=1;
							Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
							Show_MusicLine();
						}
				}break;
		case 2:
				{
					if((Musicnum>=0)&&(My_Music[Musicnum].isEnable==MUSIC_ENABLE))	
						{
								Music_Play();
						}
				}break;
		case 3:
				{
					if(((Musicnum+1)>=0)&&(My_Music[(Musicnum+1)].isEnable==MUSIC_ENABLE))	
						{
							My_Music[Musicnum].isOpen=MUSIC_CLOSE;
							Musicnum+=1;
							MusicExit=1;
							Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
							Show_MusicLine();
						}
				}break;
		case 4:
				{
					if(((Musicnum+2)>=0)&&(My_Music[(Musicnum+2)].isEnable==MUSIC_ENABLE))	
						{
							My_Music[Musicnum].isOpen=MUSIC_CLOSE;
							Musicnum+=2;
							MusicExit=1;
							Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
							Show_MusicLine();
						}
				}break;
	}
	delay_ms(300);
}

void Show_MusicLine2()
{
	LCD_Fill(0,72,239,72+24*5,WHITE);
	if(((Musicnum2-2)>=0)&&((Musicnum2-2)<=MUSICNUM)&&(My_Music2[(Musicnum2-2)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music2(12+6,72,Musicnum2-2,GRAY,WHITE);
	}
	if(((Musicnum2-1)>=0)&&((Musicnum2-1)<=MUSICNUM)&&(My_Music2[(Musicnum2-1)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music2(12+6,72+24*1,Musicnum2-1,BLACK,WHITE);
	}
	if(((Musicnum2)>=0)&&((Musicnum2)<=MUSICNUM)&&(My_Music2[Musicnum2].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music2(12+6,72+24*2,Musicnum2,RED,WHITE);
	}
	if(((Musicnum2+1)>=0)&&((Musicnum2+1)<=MUSICNUM)&&(My_Music2[(Musicnum2+1)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music2(12+6,72+24*3,Musicnum2+1,BLACK,WHITE);
	}
	if(((Musicnum2+2)>=0)&&((Musicnum2+2)<=MUSICNUM)&&(My_Music2[(Musicnum2+2)].isEnable==MUSIC_ENABLE))
	{
		Strcat_Music2(12+6,72+24*4,Musicnum2+2,GRAY,WHITE);
	}
}

void Select_MusicLine2()
{
	u8 touchnum=0;
	touchnum=(TouchData.lcdy-72)/24;
	switch(touchnum)
	{
		case 0:
				{
					if(((Musicnum2-2)>=0)&&(My_Music2[(Musicnum2-2)].isEnable==MUSIC_ENABLE))	
						{
							Musicnum2-=2;
							Show_MusicLine2();
						}
				}break;
		case 1:
				{
					if(((Musicnum2-1)>=0)&&(My_Music2[(Musicnum2-1)].isEnable==MUSIC_ENABLE))	
						{
							Musicnum2-=1;
							Show_MusicLine2();
						}
				}break;
		case 2:
				{
					if((Musicnum2>=0)&&(My_Music2[Musicnum2].isEnable==MUSIC_ENABLE))	
						{
							Music_Add();
						}
				}break;
		case 3:
				{
					if(((Musicnum2+1)>=0)&&(My_Music2[(Musicnum2+1)].isEnable==MUSIC_ENABLE))	
						{
							Musicnum2+=1;
							Show_MusicLine2();
						}
				}break;
		case 4:
				{
					if(((Musicnum2+2)>=0)&&(My_Music2[(Musicnum2+2)].isEnable==MUSIC_ENABLE))	
						{
							Musicnum2+=2;
							Show_MusicLine2();
						}
				}break;
	}
	delay_ms(300);
}


void Strcat_Music(u16 x,u16 y,u8 MusicNum,u16 fg_color,u16 bg_color)
{
	char num[5]={'\0'};
	itoa(MusicNum+1,num);
	LCD_ShowFont12Char(x,y,(uint8_t*)num,fg_color,bg_color);
	LCD_ShowFont12Char(x+42,y,My_Music[MusicNum].name,fg_color,bg_color);
	LCD_ShowFont12Char(x+42+96,y,My_Music[MusicNum].time,fg_color,bg_color);	
}

void Strcat_Music2(u16 x,u16 y,u8 MusicNum,u16 fg_color,u16 bg_color)
{
	char num[5]={'\0'};
	itoa(MusicNum+1,num);
	LCD_ShowFont12Char(x,y,(uint8_t*)num,fg_color,bg_color);
	LCD_ShowFont12Char(x+42,y,My_Music2[MusicNum].name,fg_color,bg_color);
	LCD_ShowFont12Char(x+42+96,y,My_Music2[MusicNum].time,fg_color,bg_color);	
}

void My_Music_init()
{
	My_Music_Init(My_Music);
	My_Music_Init(My_Music2);
	Music_Install(My_Music,0,"巴比龙","2019/10/19","0:/01/(1).mp3",kong);
	Music_Install(My_Music,1,"戳爷你的","2019/10/9","0:/01/(2).mp3",kong);                                        
	Music_Install(My_Music,2,"高尚","2019/10/9","0:/01/(3).mp3",kong);
	Music_Install(My_Music,3,"欧克嘎嘎","2019/10/9","0:/01/(4).mp3",kong);
	Music_Install(My_Music,4,"中国徐","2019/10/9","0:/01/(5).mp3",kong);
	Music_Install(My_Music2,0,"吃鸡神曲","2019/10/9","0:/01/(6).mp3",kong);
	Music_Install(My_Music2,1,"动物世界","2019/10/9","0:/01/(7).mp3",kong);
	Music_Install(My_Music2,2,"黎明嘎嘎","2019/10/9","0:/01/(8).mp3",kong);
	Music_Install(My_Music2,3,"像风一样","2019/10/9","0:/01/(9).mp3",kong);
}



void My_MusicAdd()
{
	u8 MusicExit=0;
	Show_MusicAdd();
	while(!MusicExit)
	{
		TOUCH_Scan();
		My_MusicAdd_Fun(&MusicExit);
	}
	music_BackGround();
}

void My_MusicAdd_Fun(u8* MusicExit)
{
	while(Touch_iFlag==1)
	{
		if(((TouchData.lcdx>=190)&&(TouchData.lcdx<=239))&&((TouchData.lcdy>=0)&&(TouchData.lcdy<=70)))
			{
				*MusicExit=1;
				delay_ms(300);
			}
		else if(((TouchData.lcdx>=0)&&(TouchData.lcdx<=239))&&((TouchData.lcdy>=72)&&(TouchData.lcdy<=72+24*5)))
			{
				Select_MusicLine2();
			}
		else if(((TouchData.lcdx>=60)&&(TouchData.lcdx<=179))&&((TouchData.lcdy>=194+60)&&(TouchData.lcdy<=234+60)))
			{
				Music_Add();
			}
		Touch_iFlag=0;
	}	
}

void Music_Add()
{
	u8 Count=0;
	Busy("正在等待添加音乐！");
	while((My_Music[Count].isEnable==MUSIC_ENABLE)&&(Count<MUSICNUM))
	{
		Count++;
	}
	if(Count<MUSICNUM)
	{
		Music_SetTime(&My_Music2[Musicnum2]);
		memcpy(&My_Music[Count],&My_Music2[Musicnum2],SIZEOFMUSIC);
		My_Music2[Musicnum2].isEnable=MUSIC_DISABLE;
		Music_UpLine(My_Music2);
		Show_MusicLine2();
	}
	Busy("音乐已成功添加！");
	delay_ms(1000);
}

void Music_Delete()
{
	u8 Count=0;
	while((My_Music2[Count].isEnable==MUSIC_ENABLE)&&(Count<MUSICNUM))
	{
		Count++;
	}
	if(Count<MUSICNUM)
	{
		if(My_Music[Musicnum].isOpen==MUSIC_CLOSE)
		{
			Music_SetTime(&My_Music[Musicnum]);
			memcpy(&My_Music2[Count],&My_Music[Musicnum],SIZEOFMUSIC);
			My_Music[Musicnum].isEnable=MUSIC_DISABLE;
			Music_UpLine(My_Music);
			Show_MusicLine();
			Busy("音乐已成功删除！");
		}
		else
		{
			Busy("音乐正在播放，删除失败");
		}
		
	}
	delay_ms(1000);
}

void Show_MusicAdd()
{
	LCD_Fill(0,25,239,369,WHITE);
	LCD_ShowFont16Char(80,24,"云音乐库",BLACK,WHITE);
	LCD_ShowPicture(210,24,24,20,gImage_back);
	LCD_DrawLine_Color(0, 24+20,239 ,24+20,BLACK);
	LCD_ShowFont12Char(6,50,"序号",BLACK,WHITE);
	LCD_ShowFont12Char(6+48,50,"音乐名称",BLACK,WHITE);
	LCD_ShowFont12Char(12+48+96,50,"修改时间",BLACK,WHITE);
	LCD_DrawLine_Color(0,70,239,70,BLACK);
	Show_MusicLine2();
	LCD_DrawLine_Color(0,193,239,193,BLACK);
	Show_Music_Button(0+60,194+60,119+60,234+60,"Add music ",BLACK,BLUE);
}


void Music_UpLine(MUSIC My_music[MUSICNUM])
{
	u8 Count=0;
	for(Count=0;Count<MUSICNUM;Count++)
	{
		if(My_music[Count].isEnable==MUSIC_DISABLE)
		{
			if(Count!=MUSICNUM-1)
			{
				memcpy(&My_music[Count],&My_music[Count+1],SIZEOFMUSIC);
				My_music[Count+1].isEnable=MUSIC_DISABLE;
			}
		}
	}
}




void Music_Play()
{
	if(My_Music[Musicnum].isOpen==MUSIC_CLOSE)
	{
		My_Music[Musicnum].isOpen=MUSIC_OPEN;
		Iocn(96,250,48,48,gImage_stop,"暂停",BLACK,WHITE);
		if(MusicExit==1)
		{
			MusicExit=0;
			MusicPlay=1;
			delay_ms(500);
			Music_Display(My_Music[Musicnum].path);
		}	
		MusicPlay=1;
	}
	else if (My_Music[Musicnum].isOpen==MUSIC_OPEN)
	{
		My_Music[Musicnum].isOpen=MUSIC_CLOSE;
		Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
		MusicPlay=0;
	}
	delay_ms(500);
}


void Music_Last()
{
		if((Musicnum-1)>=0)
		{
			My_Music[Musicnum].isOpen=MUSIC_CLOSE;
			Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
			MusicExit=1;
			Musicnum-=1;
			Show_MusicLine();
		}
		else
		{
			Busy("前面已经没用歌曲了！");
		}
		delay_ms(300);
}


void Music_Next()
{
		if(((Musicnum+1)<MUSICNUM)&&(My_Music[Musicnum+1].isEnable==MUSIC_ENABLE))
		{
			My_Music[Musicnum].isOpen=MUSIC_CLOSE;
			Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
			MusicExit=1;
			Musicnum+=1;
			Show_MusicLine();
		}
		else
		{
			Busy("后面已经没用歌曲了！");
		}
		delay_ms(300);
}

void Music_Volume()
{
	if(TouchData.lcdx<100)
	{
		if(VolumeNum>0)
		{
					VolumeNum--;
		}
	}
	else if(TouchData.lcdx>200)
	{
		if(VolumeNum<254)
		{
					VolumeNum++;
		}
	}
	else if((TouchData.lcdx>=100)&&(TouchData.lcdx<=200))
	{
		VolumeNum=((TouchData.lcdx-100)*254)/100;
	}
  MP3_AudioSetting(VolumeNum);
	Show_Volume(0,331,(VolumeNum*100)/254,BLACK,WHITE);
	delay_ms(11);//  3000/254
}




void Show_RenameBackground()
{
		Cursor_x=60;
		Cursor_y=115;
		LCD_Fill(0,194,239,234,WHITE);
		LCD_Fill(60,120,140,144,WHITE);
		LCD_ShowKeyBG();
		KeyBorad_PriKeyBorad();
}


void ChangName()
{
	memcpy(My_Music[Musicnum].name,MusicName,SIZEOFNAME);
	Music_SetTime(&My_Music[Musicnum]);
	Rename_Exit();
}

 
void Rename_Exit()
{
	memset(MusicName,'\0',SIZEOFNAME);
	Exit();
	NameNum=0;
	delay_ms(300);
}


void Music_SetTime(MUSIC My_music[MUSICNUM] )
{

			char month[5];
			char data[5];

			char MyPut[20];

			RTC_Get();//更新时间

			itoa(calendar.w_year,MyPut);
			itoa(calendar.w_month,month);
			itoa(calendar.w_date,data);

			strcat(MyPut,"-");
			strcat(MyPut,month);
			strcat(MyPut,"-");
			strcat(MyPut,data);
			strcat(MyPut," ");

			
			memcpy(My_music->time,MyPut,SIZEOFTIME);
}









