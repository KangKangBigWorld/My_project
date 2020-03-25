#include "My_view.h"
#include "Time_IRQ.h"
u8 Main_iFlag=0;


void Main_Background()
{
	if(Main_iFlag==0)
	{
		LCD_Clear(WHITE);
		LCD_Fill(0,0,239,23,CYAN);
		LCD_Fill(0,25,239,369,WHITE);
		LCD_Fill(0,370,239,399,BLACK);
		LCD_ShowFont12Char(0,0,"WF1905 何亚康",BLACK,CYAN);
		Main_Iocn();
		Main_iFlag=1;
		Free();
	}
}


void Iocn(u16 x, u16 y, u16 wide, u16 high,const u8 *pic, uint8_t *cn ,u16 fg_color,u16 bg_color)
{
	unsigned int lenth;
	lenth=strlen((char*) cn);
	LCD_ShowPicture(x,y,wide,high,pic);
	LCD_ShowFont16Char(x+((wide-lenth*10)/2),y+high+1,cn,fg_color,bg_color);
}


void Main_Iocn()
{
	Iocn(12,31,64,64,(const u8*)gImage_jishiben,"文本",BLACK,WHITE);
	Iocn(88,31,64,64,(const u8*)gImage_music,"音乐",BLACK,WHITE);
	Iocn(164,31,64,64,(const u8*)gImage_wendu,"温湿度",BLACK,WHITE);
	Iocn(12,128,64,64,(const u8*)gImage_shizhong,"时钟",BLACK,WHITE);
	Iocn(88,128,64,64,(const u8*)gImage_deng,"灯控",BLACK,WHITE);
}


void jishiben_BackGround()
{
		LCD_Fill(0,25,239,369,WHITE);
		LCD_ShowFont16Char(80,24,"小本本",BLACK,WHITE);
		LCD_ShowPicture(210,24,24,20,gImage_back);
		LCD_DrawLine_Color(0, 24+20,239 ,24+20,BLACK);
		Cursor_x=KEYCURSOR_X;
		Cursor_y=KEYCURSOR_Y;
		LCD_ShowKeyBG();
		KeyBorad_PriKeyBorad();

}

void temperature_BackGround()
{
		LCD_Fill(0,25,239,369,WHITE);
		LCD_ShowFont16Char(80,24,"温湿度",BLACK,WHITE);
		LCD_ShowPicture(210,24,24,20,gImage_back);
		LCD_DrawLine_Color(0, 24+20,239 ,24+20,BLACK);
}

void music_BackGround()
{
		LCD_Fill(0,25,239,369,WHITE);
		LCD_ShowFont16Char(80,24,"音乐库",BLACK,WHITE);
		LCD_ShowPicture(210,24,24,20,gImage_back);
		LCD_ShowPicture(5,24,24,20,gImage_add);
	
		LCD_DrawLine_Color(0, 24+20,239 ,24+20,BLACK);
		Show_Music_Library();
}


void colock_BackGround()
{
		
		LCD_Fill(0,25,239,369,WHITE);
		LCD_ShowFont16Char(80,24,"小闹钟",BLACK,WHITE);
		LCD_ShowPicture(210,24,24,20,gImage_back);
		LCD_ShowPicture(5,24,24,20,gImage_add);

		LCD_DrawLine_Color(0, 24+20,239 ,24+20,BLACK);
		My_Show_Clock();
}

void Show_NextNum(u16 x,u16 y,u8 num,u8 min,u8 max)
{
	char One[5]={'\0'};
	char Two[5]={'\0'};
	char Three[5]={'\0'};
	char temp[5]={'\0'};
		
	if(num==min)
	{	
		itoa(max,temp);
		strcat(One,temp);
	}
	else if((num-1< 10)&&(num!=min))
	{
		strcat(One,"0");	
		itoa(num-1,temp);
		strcat(One,temp);
	}
	else if(num!=min)
	{
		itoa(num-1,temp);
		strcat(One,temp);
	}
	if(num< 10)
	strcat(Two,"0");
	itoa(num,temp);
	strcat(Two,temp);
	
	if(num==max)
	{	
		itoa(min,temp);
		strcat(Three,temp);
	}
	else if((num+1< 10)&&(num!=max))
	{
		strcat(Three,"0");	
		itoa(num+1,temp);
		strcat(Three,temp);
	}	
	else if((num!=max))
	{
		itoa(num+1,temp);
		strcat(Three,temp);
	}
	
	LCD_ShowPicture(x,y,48,24,gImage_rise);
	LCD_ShowString(x+12,y+24*1,One,24,GRAY,WHITE);
	LCD_ShowString(x+12,y+24*2,Two,24,RED,WHITE);
	LCD_ShowString(x+12,y+24*3,Three,24,GRAY,WHITE);
	LCD_ShowPicture(x,y+24*4,48,24,gImage_down);
}


void Show_Delete(void)
{
	
}
