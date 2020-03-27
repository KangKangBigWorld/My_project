#include "KeyBoard.h"


pKEY_VALUE pKeyInit=NULL;
u8 CAPSLK_iFlag=CAPSLK_LOW;
u8 HIDE_FLAG=0;

u16 Cursor_x=KEYCURSOR_X;
u16 Cursor_y=KEYCURSOR_Y;
u8  Cursor_Flag=0;




void KeyBorad_Init()
{
	u16 x=0;
	u16 y=170;
	u16 x0=x;
	u16 y0=y;
	u8 iCount=0;
	pKEY_VALUE pKeyData=NULL;
	pKeyInit=(pKEY_VALUE)calloc(SIZEOF_KEY,KEY_NUM);
	if(pKeyInit==NULL)
	{
		return;
	}
	pKeyData=pKeyInit;
	
	//第一行背景
	x=x0+7;//第一行x偏移
	y=y0+63;//第一行y偏移
	for(iCount=0;iCount<10;iCount++)
	{
		pKeyData->Key_X1=x;
		pKeyData->Key_Y1=y;
		pKeyData->Key_X2=x+18;
		pKeyData->Key_Y2=y+30;
		x+=23;
		pKeyData++;
	}
	
	//第二行背景
	x=x0+17;//第二行x偏移
	y=y0+98;//第二行y偏移
	for(iCount=0;iCount<9;iCount++)
	{
		pKeyData->Key_X1=x;
		pKeyData->Key_Y1=y;
		pKeyData->Key_X2=x+18;
		pKeyData->Key_Y2=y+30;
		x+=23;
		pKeyData++;
	}
	
	//第三行背景
	x=x0+7+33;//第三行x偏移
	y=y0+133;//第三行y偏移
	for(iCount=0;iCount<7;iCount++)
	{
		pKeyData->Key_X1=x;
		pKeyData->Key_Y1=y;
		pKeyData->Key_X2=x+18;
		pKeyData->Key_Y2=y+30;
		x+=23;
		pKeyData++;
	}
	

	//up键 SHIFT 26
	//第三行背景
		x=x0+7;//第三行x偏移
		y=y0+133;//第三行y偏移
		pKeyData->Key_X1=x;
		pKeyData->Key_Y1=y;
		pKeyData->Key_X2=x+30;
		pKeyData->Key_Y2=y+30;
		pKeyData->Key_Name='u';
	  pKeyData++;
	
	//<-键  DELETE 27
	//第三行背景
		x=x0+7+33+23*7;//第三行x偏移
		y=y0+133;//第三行y偏移
		pKeyData->Key_X1=x;
		pKeyData->Key_Y1=y;
		pKeyData->Key_X2=x+30;
		pKeyData->Key_Y2=y+30;
		pKeyData->Key_Name='<';
		pKeyData++;
	
	//123  NUMKEY 28
	//第四行背景
	x=x0+7;//第四行x偏移
	y=y0+168;//第四行y偏移
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+42;
	pKeyData->Key_Y2=y+30;
	pKeyData->Key_Name='1';
	pKeyData++;
	

	//@ AITE 29
	x=x0+53;//第四行x偏移
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+44;
	pKeyData->Key_Y2=y+30;
	pKeyData->Key_Name='@';
	pKeyData++;
	
	// space   SPACE  30
	x=x0+101;//第四行x偏移
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+12*5;
	pKeyData->Key_Y2=y+30;
	pKeyData->Key_Name=' ';
	pKeyData++;
	
	//Enter  ENTER  31
	x=x0+171;//第四行x偏移
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+12*5;
	pKeyData->Key_Y2=y+30;
	pKeyData->Key_Name='E';
	pKeyData++;
	
	//F1键 F1 32
	//第0行背景
		x=x0+7;//第0行x偏移
		y=y0+31;//第0行y偏移
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+12*2;
	pKeyData->Key_Y2=y+25;
	pKeyData->Key_Name='1';
	pKeyData++;
	x+=21+12+5;
	
	//F2键 F2 33
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+12*2;
	pKeyData->Key_Y2=y+25;
	pKeyData->Key_Name='2';
	pKeyData++;
	x+=21+12+5;
	
	//F3键 F3 34
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+12*2;
	pKeyData->Key_Y2=y+25;
	pKeyData->Key_Name='3';
	pKeyData++;
	x+=21+12+5;
	
	//F4键 F4 35
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+12*2;
	pKeyData->Key_Y2=y+25;
	pKeyData->Key_Name='4';
	pKeyData++;
	x+=21+12+5;
	
	//HIDE键 HIDE 36
	pKeyData->Key_X1=x;
	pKeyData->Key_Y1=y;
	pKeyData->Key_X2=x+6+21*2+24;
	pKeyData->Key_Y2=y+25;
	pKeyData->Key_Name='4';  
}

void KeyBorad_PriKeyBorad()
{
	u16 x=0;
	u16 y=170;
	u16 x0=x;
	u16 y0=y;
	u8 iCount=0;
	pKEY_VALUE pKeyData=pKeyInit;
	u8 CAPSLK[3][27]={
										{'Q','W','E','R','T','Y','U','I','O','P',
											 'A','S','D','F','G','H','J','K','L',
													'Z','X','C','V','B','N','M'},
										{'q','w','e','r','t','y','u','i','o','p',
											 'a','s','d','f','g','h','j','k','l',
													'z','x','c','v','b','n','m'},
										{'1','2','3','4','5','6','7','8','9','0',
											'-','/',':',';','(',')','@','"','~',
												 '*','#','+','-','?','!','.'}
										};
	//第一行背景
	x=x0+7;//第一行x偏移
	y=y0+63;//第一行y偏移
	for(iCount=0;iCount<10;iCount++)
	{
		LCD_ShowCharColor(x+3,y,CAPSLK[CAPSLK_iFlag][iCount],24,BLACK,WHITE);
		pKeyData->Key_Name=CAPSLK[CAPSLK_iFlag][iCount];
		x+=23;
		pKeyData++;
	}
	
//第二行背景
	x=x0+17;//第二行x偏移
	y=y0+98;//第二行y偏移
	for(iCount=10;iCount<19;iCount++)
	{
		LCD_ShowCharColor(x+3,y,CAPSLK[CAPSLK_iFlag][iCount],24,BLACK,WHITE);
		pKeyData->Key_Name=CAPSLK[CAPSLK_iFlag][iCount];
		x+=23;
		pKeyData++;
	}
	
		//第三行背景
	x=x0+7+33;//第三行x偏移
	y=y0+133;//第三行y偏移
	for(iCount=19;iCount<26;iCount++)
	{
		LCD_ShowCharColor(x+3,y,CAPSLK[CAPSLK_iFlag][iCount],24,BLACK,WHITE);
		pKeyData->Key_Name=CAPSLK[CAPSLK_iFlag][iCount];
		x+=23;
		pKeyData++;
	}
}


void LCD_ShowKeyBG()
{

	if(HIDE_FLAG==0)
	{
		u16 x=0;
	u16 y=170;
	u16 x0=x;
	u16 y0=y;
	u16 x1=239;
	u16 y1=369;
	u8 iCount=0;
	LCD_Fill(x,y+30,x1,y1,GRAY);
	LCD_DrawLine(x,y+58,x1,y+58);
	
	//第0行背景
	x=x0+7;//第一行x偏移
	y=y0+31;//第一行y偏移
	LCD_Fill(x,y,x+18,y+24,WHITE);
	LCD_ShowKey(x,y,"F1",BLACK,WHITE);
	LCD_Fill(x+3+12*2,y,x+6+12*2,y+24,WHITE);
	LCD_Fill(x,y+24,x+6+12*2,y+24,WHITE);
	LCD_DrawLine_Color(x,y+25,x+6+12*2,y+25,BLACK);
	x+=21+12+5;
	
	LCD_Fill(x,y,x+18,y+24,WHITE);
	LCD_ShowKey(x,y,"F2",BLACK,WHITE);
	LCD_Fill(x+3+12*2,y,x+6+12*2,y+24,WHITE);
	LCD_Fill(x,y+24,x+6+12*2,y+24,WHITE);
	LCD_DrawLine_Color(x,y+25,x+6+12*2,y+25,BLACK);
	x+=21+12+5;
	
	LCD_Fill(x,y,x+18,y+24,WHITE);
	LCD_ShowKey(x,y,"F3",BLACK,WHITE);
	LCD_Fill(x+3+12*2,y,x+6+12*2,y+24,WHITE);
	LCD_Fill(x,y+24,x+6+12*2,y+24,WHITE);
	LCD_DrawLine_Color(x,y+25,x+6+12*2,y+25,BLACK);
	x+=21+12+5;
	
	LCD_Fill(x,y,x+18,y+24,WHITE);
	LCD_ShowKey(x,y,"F4",BLACK,WHITE);
	LCD_Fill(x+3+12*2,y,x+6+12*2,y+24,WHITE);
	LCD_Fill(x,y+24,x+6+12*2,y+24,WHITE);
	LCD_DrawLine_Color(x,y+25,x+6+12*2,y+25,BLACK);
	x+=21+12+5;


	LCD_Fill(x,y,x+72,y+24,WHITE);
	LCD_ShowFont16Char(x+24,y,"隐藏",BLACK,WHITE);
	LCD_ShowPicture(x,y,24,24,gImage_hide);
	LCD_DrawLine_Color(x,y+25,x+6+21*2+24,y+25,BLACK);
	
	
	//第一行背景
	x=x0+7;//第一行x偏移
	y=y0+63;//第一行y偏移
	for(iCount=0;iCount<10;iCount++)
	{
		LCD_Fill(x,y,x+18,y+29,WHITE);
		LCD_DrawLine_Color(x,y+30,x+6+12,y+30,BLACK);
		x+=23;
	}
	//第二行背景
	x=x0+17;//第二行x偏移
	y=y0+98;//第二行y偏移
	for(iCount=0;iCount<9;iCount++)
	{
		LCD_Fill(x,y,x+18,y+29,WHITE);
		LCD_DrawLine_Color(x,y+30,x+6+12,y+30,BLACK);
		x+=23;
	}
	//第三行背景
	x=x0+7;//第二行x偏移
	y=y0+133;//第二行y偏移
	for(iCount=0;iCount<9;iCount++)
	{
		if(iCount==0)
		{
			LCD_Fill(x,y,x+18,y+29,WHITE);
			LCD_ShowKey(x,y,"up",BLACK,WHITE);
			LCD_Fill(x+3+12*2,y,x+6+12*2,y+29,WHITE);
			LCD_Fill(x,y+24,x+6+12*2,y+29,WHITE);
			LCD_DrawLine_Color(x,y+30,x+6+12*2,y+30,BLACK);
			x+=21+12;
		}
		else if(iCount==8)
		{
			LCD_Fill(x,y,x+18,y+29,WHITE);
			LCD_ShowKey(x,y,"<-",BLACK,WHITE);
			LCD_Fill(x+3+12*2,y,x+6+12*2,y+29,WHITE);
			LCD_Fill(x,y+24,x+6+12*2,y+29,WHITE);
			LCD_DrawLine_Color(x,y+30,x+6+12*2,y+30,BLACK);
		}
		else
		{
			LCD_Fill(x,y,x+18,y+29,WHITE);
			LCD_DrawLine_Color(x,y+30,x+6+12,y+30,BLACK);
			x+=23;
		}
		
	}
	//第四行背景
	x=x0+7;//第四行x偏移
	y=y0+168;//第四行y偏移
	LCD_Fill(x,y,x+18,y+29,WHITE);
	LCD_ShowKey(x,y,"123",BLACK,WHITE);
	LCD_Fill(x+3+12*3,y,x+6+12*3,y+29,WHITE);
	LCD_Fill(x,y+24,x+6+12*3,y+29,WHITE);
	LCD_DrawLine_Color(x,y+30,x+6+12*3,y+30,BLACK);
	
	x=x0+53;//第四行x偏移
	LCD_Fill(x,y,x+44,y+29,WHITE);
	LCD_ShowFont16Char(x,y+3,"清屏",BLACK,WHITE);
	LCD_DrawLine_Color(x,y+30,x+6+19*2,y+30,BLACK);
	
	x=x0+101;//第四行x偏移
	LCD_Fill(x,y,x+18,y+29,WHITE);
	LCD_ShowKey(x,y,"space",BLACK,WHITE);
	LCD_Fill(x+3+12*5,y,x+6+12*5,y+29,WHITE);
	LCD_Fill(x,y+24,x+6+12*5,y+29,WHITE);
	LCD_DrawLine_Color(x,y+30,x+6+12*5,y+30,BLACK);
	
	x=x0+171;//第四行x偏移
	LCD_Fill(x,y,x+18,y+29,WHITE);
	LCD_ShowKey(x,y,"Enter",BLACK,WHITE);
	LCD_Fill(x+3+12*5,y,x+6+12*5,y+29,WHITE);
	LCD_Fill(x,y+24,x+6+12*5,y+29,WHITE);
	LCD_DrawLine_Color(x,y+30,x+6+12*5,y+30,BLACK);
	
	}
	else if(HIDE_FLAG==1)
	{
	u16 x=0;
	u16 y=339;
	u16 x0=x;
	u16 y0=y;
	u16 x1=239;
	u16 y1=369;
	LCD_Fill(x,y,x1,y1,GRAY);
	x=x0+159;
	y=y0+1;
	LCD_Fill(x,y,x+72,y+24,WHITE);
	LCD_ShowFont16Char(x+24,y,"隐藏",BLACK,WHITE);
	LCD_ShowPicture(x,y,24,24,gImage_hide);
	LCD_DrawLine_Color(x,y+25,x+6+21*2+24,y+25,BLACK);	
	}
	
}
											 
											 
void LCD_ShowKey(u16 x,u16 y,u8* ch,u16 FG_Color,u16 BG_Color)
{
	while(*ch!='\0')
	{
		LCD_ShowCharColor(x+3,y,*ch,24,FG_Color,BG_Color);
		x+=12;
		ch++;
	}
}


void KeyBoard_Touch()
{
	if(HIDE_FLAG==0)
	{
		if(Touch_iFlag==1)
	{
		u8 iCount=0;
		pKEY_VALUE pKeyData=pKeyInit;
		for(iCount=0;iCount<KEY_NUM;iCount++)
		{
			if(((TouchData.lcdx>=pKeyData->Key_X1)&&(TouchData.lcdx<=pKeyData->Key_X2))&&((TouchData.lcdy>=pKeyData->Key_Y1)&&(TouchData.lcdy<=pKeyData->Key_Y2)))
			{
				break;
			}
			else
			{
				pKeyData++;
			}
		}
		if((iCount<KEY_NUM))
		{
			if(iCount<26)
			{
					LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
					LCD_ShowCharColor(pKeyData->Key_X1+3,pKeyData->Key_Y1,pKeyData->Key_Name,24,BLACK,YELLOW);
					delay_ms(DELAY_TIME);
					LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
				  LCD_ShowCharColor(pKeyData->Key_X1+3,pKeyData->Key_Y1,pKeyData->Key_Name,24,BLACK,WHITE);
					if(Keyboard_Music==1)
					{
						if(NameNum<7)
						{
							LCD_ShowCharColor(Cursor_x,Cursor_y,pKeyData->Key_Name,24,BLACK,WHITE);
							Cursor_x+=12;
							memset(MusicName+NameNum,pKeyData->Key_Name,1);
							memset(MusicName+NameNum+1,'\0',1);
							NameNum++;
						}
					}
					else
					{
						LCD_ShowCharColor(Cursor_x,Cursor_y,pKeyData->Key_Name,24,BLACK,WHITE);
						Cursor_x+=12;
							if(Cursor_x>239)
						{
							Huanghang(KEYCURSOR_X,KEYCURSOR_Y,239,199,24,BLACK,WHITE);
						}
					}		
			}
			else
			{
				switch(iCount)
				{
					case SHIFT:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"up",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"up",BLACK,WHITE);
								if(CAPSLK_iFlag==CAPSLK_LOW)
								{
									CAPSLK_iFlag=CAPSLK_BIG;
								}
								else
								{
									CAPSLK_iFlag=CAPSLK_LOW;
								}
								KeyBorad_PriKeyBorad();
							}break;
					case DELETE:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"<-",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"<-",BLACK,WHITE);
							  if(Keyboard_Music==1)
									{
										if(NameNum>0)
										{
											Delect(KEYCURSOR_X,KEYCURSOR_Y,KEYCURSOR_X+12*8,KEYCURSOR_Y,24,BLACK,WHITE);
											memset(MusicName+NameNum,'\0',1);
											NameNum--;
										}
									}
								else
									{
										Delect(KEYCURSOR_X,KEYCURSOR_Y,239,199,24,BLACK,WHITE);
									}
							}break;
					case NUMKEY:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"123",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"123",BLACK,WHITE);
								if(CAPSLK_iFlag!=SIGN)
								{
									CAPSLK_iFlag=SIGN;
								}
								else
								{
									CAPSLK_iFlag=CAPSLK_LOW;
								}
								KeyBorad_PriKeyBorad();
							}break;
					case QINGPING:
							{	
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowFont16Char(pKeyData->Key_X1,pKeyData->Key_Y1+3,"清屏",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowFont16Char(pKeyData->Key_X1,pKeyData->Key_Y1+3,"清屏",BLACK,WHITE);
								 Qingping(KEYCURSOR_X,KEYCURSOR_Y,239,199,24,BLACK,WHITE);
							}break;
					case SPACE:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"space",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"space",BLACK,WHITE);
											if(Keyboard_Music==1)
								{
													if(NameNum<7)
									{
										LCD_ShowCharColor(Cursor_x,Cursor_y,pKeyData->Key_Name,24,BLACK,WHITE);
										Cursor_x+=12;
										memset(MusicName+NameNum,pKeyData->Key_Name,1);
										memset(MusicName+NameNum+1,'\0',1);
										NameNum++;
									}
								}
								else
								{
									LCD_ShowCharColor(Cursor_x,Cursor_y,pKeyData->Key_Name,24,BLACK,WHITE);
									Cursor_x+=12;
										if(Cursor_x>239)
									{
										Huanghang(KEYCURSOR_X,KEYCURSOR_Y,239,199,24,BLACK,WHITE);
									}
								}	
							}break;
					case ENTER:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"Enter",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"Enter",BLACK,WHITE);
											if(Keyboard_Music==1)
									{
										 ChangName();
									}
									else
									{
										Huanghang(KEYCURSOR_X,KEYCURSOR_Y,239,199,24,BLACK,WHITE);
									}	
							}break;
					case F1:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F1",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F1",BLACK,WHITE);
							}break;
					case F2:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F2",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1+1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F2",BLACK,WHITE);
							}break;
					case F3:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F3",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F3",BLACK,WHITE);
							}break;
					case F4:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,YELLOW);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F4",BLACK,YELLOW);
								delay_ms(DELAY_TIME);
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2-1,WHITE);
								LCD_ShowKey(pKeyData->Key_X1,pKeyData->Key_Y1,"F4",BLACK,WHITE);
							}break;
					case HIDE:
							{
								LCD_Fill(pKeyData->Key_X1,pKeyData->Key_Y1,pKeyData->Key_X2,pKeyData->Key_Y2,YELLOW);
								LCD_ShowFont16Char(183,201,"隐藏",BLACK,YELLOW);
								LCD_ShowPicture(159,201,24,24,gImage_hide);
								delay_ms(DELAY_TIME);
								LCD_Fill(0,200,239,370,WHITE);
								HIDE_FLAG=1;
								LCD_ShowKeyBG();
								
							}break;
				}
			}
		}
	}
	}
	else if(HIDE_FLAG==1)
	{
		if((Touch_iFlag==1)&&((TouchData.lcdx>=159)&&(TouchData.lcdx<=159+68))&&((TouchData.lcdy>=339)&&(TouchData.lcdy<=369)))
			{
				HIDE_FLAG=0;
				LCD_ShowKeyBG();
				KeyBorad_PriKeyBorad();
				delay_ms(DELAY_TIME);
			}
	}
}

void Qingping(u16 x1,u16 y1,u16 x2,u16 y2,u8 size,u16 FG_Color,u16 BG_Color)
{
	LCD_Fill(x1,y1,x2,y2,BG_Color);
	Cursor_x=x1;
	Cursor_y=y1;
}

void Huanghang(u16 x1,u16 y1,u16 x2,u16 y2,u8 size,u16 FG_Color,u16 BG_Color)
{
	LCD_ShowCharColor(Cursor_x,Cursor_y,' ',size,FG_Color,BG_Color);
	Cursor_x=x1;
	Cursor_y+=size;
	if(Cursor_y>y2-size)
	{
		Qingping(x1,y1,x2,y2,size,FG_Color,BG_Color);
	}
}

void Delect(u16 x1,u16 y1,u16 x2,u16 y2,u8 size,u16 FG_Color,u16 BG_Color)
{
	LCD_ShowCharColor(Cursor_x,Cursor_y,' ',size,FG_Color,BG_Color);
	if(Cursor_x==x1)
	{
		if(Cursor_y==y1)
		{
			
		}
		else
		{
			Cursor_x=x2-12;
			Cursor_y-=size;
		}
	}
	else
	{
		Cursor_x-=12;
	}
	LCD_ShowCharColor(Cursor_x,Cursor_y,' ',size,FG_Color,BG_Color);
}

void LED_Cursor()
{
	
	if(Cursor_Flag==0)
	{
		LCD_ShowCharColor(Cursor_x,Cursor_y,'|',24,BLACK,WHITE);
		Cursor_Flag=1;
	}
	else
	{
		LCD_ShowCharColor(Cursor_x,Cursor_y,'|',24,WHITE,WHITE);
		Cursor_Flag=0;
	}
}

