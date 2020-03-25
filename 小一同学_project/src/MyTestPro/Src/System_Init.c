#include "System_Init.h"

#define HSE_ON (1<<16)                  //开启HSE外部时钟高速使能
#define HSE_OFF ~(1<<16)                //关闭HSE外部时钟高速使能
#define HSE_BE_READY (1<<17)            //检测HSE外部时钟高速使能是否就绪

void SystemInit()
{
	//打开HSE外部时钟高速使能 
	RCC->CR |=HSE_ON;
	//检测HSE外部时钟高速使能是否就绪
	while(!((RCC->CR&HSE_BE_READY)>>17)==1);
	//配置内存访问控制寄存器，48~72HZ要配置010
	FLASH->ACR=0x32;
	//配置PLLSRC：PLL输入时钟源
	RCC->CFGR |=(1<<16);
	//配置倍频为9倍
	RCC->CFGR |=(7<<18);
	//打开PLL使能
	RCC->CR |=(1<<24);
	//检测PLL使能是否准备就绪
	while(!((RCC->CR&1<<24)>>24)==1);
	//切换系统时钟
	RCC->CFGR |=2;
	//检测系统时钟的切换状态
	while(!((RCC->CFGR&2<<2)>>2)==2);
	
}





