#include "System_Init.h"

#define HSE_ON (1<<16)                  //����HSE�ⲿʱ�Ӹ���ʹ��
#define HSE_OFF ~(1<<16)                //�ر�HSE�ⲿʱ�Ӹ���ʹ��
#define HSE_BE_READY (1<<17)            //���HSE�ⲿʱ�Ӹ���ʹ���Ƿ����

void SystemInit()
{
	//��HSE�ⲿʱ�Ӹ���ʹ�� 
	RCC->CR |=HSE_ON;
	//���HSE�ⲿʱ�Ӹ���ʹ���Ƿ����
	while(!((RCC->CR&HSE_BE_READY)>>17)==1);
	//�����ڴ���ʿ��ƼĴ�����48~72HZҪ����010
	FLASH->ACR=0x32;
	//����PLLSRC��PLL����ʱ��Դ
	RCC->CFGR |=(1<<16);
	//���ñ�ƵΪ9��
	RCC->CFGR |=(7<<18);
	//��PLLʹ��
	RCC->CR |=(1<<24);
	//���PLLʹ���Ƿ�׼������
	while(!((RCC->CR&1<<24)>>24)==1);
	//�л�ϵͳʱ��
	RCC->CFGR |=2;
	//���ϵͳʱ�ӵ��л�״̬
	while(!((RCC->CFGR&2<<2)>>2)==2);
	
}





