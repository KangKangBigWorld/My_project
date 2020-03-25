#include "Boot_test.h"




void Boot_test()
	{
		Boot_BackGraound();
		My_test(0,26);
		delay_ms(1000);
	}
	
	
	
	void Boot_BackGraound()
{
	LCD_Clear(BLUE);
	LCD_Fill(0,25,239,399,GBLUE);
	LCD_ShowString(53,0,"Boot test",24,BLACK,BLUE);
	
}

void My_test(u16 x,u16 y)
{
	LCD_ShowString(x,y,"Starup machine:",24,BLACK,GBLUE);
	y+=24;
	delay_ms(300);
	LCD_ShowString(x,y,"SDRAM Test:",24,BLACK,GBLUE);
	y+=24;
	delay_ms(300);
	LCD_ShowString(x,y,"Writing 0x55 to memory",16,BLACK,GBLUE);
	Delay_point(x+178,y,16,3,300,BLACK,GBLUE);
	delay_ms(300);
	y+=16;
	LCD_ShowString(x,y,"Try to read data",16,BLACK,GBLUE);
	Delay_point(x+178,y,16,3,100,BLACK,GBLUE);
	delay_ms(300);
	y+=16;
	delay_ms(300);
	LCD_ShowString(x,y,"Writing 0xAA to memory",16,BLACK,GBLUE);
	Delay_point(x+178,y,16,3,300,BLACK,GBLUE);
	delay_ms(300);
	y+=16;
	LCD_ShowString(x,y,"Try to read data",16,BLACK,GBLUE);
	Delay_point(x+178,y,16,3,100,BLACK,GBLUE);
	delay_ms(300);
	y+=16;
	Delay_point(x+140,y-16*4-24,24,3,100,BLACK,GBLUE);
	//·äÃùÆ÷ÏìÓ¦Ò»´Î
	Buzzer_Lien();
	LCD_ShowString(x,y,"System info",24,BLACK,GBLUE);
	Delay_point(x+140,y,24,3,100,BLACK,GBLUE);
	delay_ms(200);
	y+=24;
	LCD_ShowString(x,y,"Chip type:STM32F103ZE",16,BLACK,GBLUE);
	delay_ms(200);
	y+=16;
	LCD_ShowString(x,y,"System main frequency:72MHz",16,BLACK,GBLUE);
	delay_ms(200);
	y+=16;
	LCD_ShowString(x,y,"R0 address:0x08000000 size:0x80000",12,BLACK,GBLUE);
	delay_ms(200);
	y+=12;
	LCD_ShowString(x,y,"RW address:0x20000000 size:0x10000",12,BLACK,GBLUE);
	delay_ms(200);
	y+=12;
	LCD_ShowString(x,y,"ZI address:0x00000000 size:0x05000",12,BLACK,GBLUE);
	delay_ms(200);
	y+=12;
	LCD_ShowString(x,y,"Character position",24,BLACK,GBLUE);
	delay_ms(200);
	y+=24;
	LCD_ShowString(x,y,"ASCII address:R0:..",16,BLACK,GBLUE);
	Delay_point(x+178,y,16,3,100,BLACK,GBLUE);
	delay_ms(200);
	y+=16;
	LCD_ShowString(x,y,"Chinese address:SD:01",16,BLACK,GBLUE);
	Delay_point(x+178,y,16,3,100,BLACK,GBLUE);
	delay_ms(200);
	y+=16;
	LCD_ShowString(x,y,"Ckecking NandFlash",24,BLACK,GBLUE);
	delay_ms(200);
	y+=24;
	NandFlash(x,y);
}

void Delay_point(u16 x,u16 y,u8 size,u16 iTime,u32 delay,u16 FG_Color,u16 BG_Color)
{
	u16 iCount=0;
	for(iCount=0;iCount<iTime;iCount++)
	{
		LCD_ShowCharColor(x,y,'.',size,FG_Color,BG_Color);
		delay_ms(delay);
		x+=size/2;
	}
	LCD_ShowString(x,y," OK",size,BLUE,GBLUE);

}

void NandFlash(u16 x,u16 y)
{
	u16 iCount=0;
	x+=5;
	y-=12;
	LCD_DrawRectangle_color(x, y+12,x+192,y+48,BLUE);
	for(iCount=0;iCount<16;iCount++)
	{
		LCD_Fill(x+2,y+14,x+11,y+46,GREEN);
		x+=12;
		delay_ms(100);
	}
	LCD_ShowString(199,y+12,"100%",16,BLUE,GBLUE);
	LCD_ShowString(199,y+29,"16/16",16,BLUE,GBLUE);
	x=0;
	y+=48;
	LCD_ShowString(x,y,"Total Block:16  Bad Block:0 ",16,BLACK,GBLUE);
	delay_ms(200);
	y+=16;
	LCD_ShowString(x,y,"Page size:4Kb   Block size:64Kb ",16,BLACK,GBLUE);
	delay_ms(200);
	y+=16;
	LCD_ShowString(x,y,"Total size:512Kb",16,BLACK,GBLUE);
}



