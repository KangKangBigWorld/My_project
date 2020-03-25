#include "Time_IRQ.h"

SOFTM_TS SoftTime_Events[MAX_TS];


/*-------------------------------��ʱ���ж�-----------------------------------------*/

void TIME_Init(void)
{
	//RCC->APB1ENR |=RCC_APB1Periph;//��ʱ��2ʱ��ʹ��APB1
	RCC->APB1ENR |=(0xF<<0);//��TIME2-5ʱ��ʹ�ܣ�����APB1������
	
	RCC->CFGR &=~(0x7<<8);//����APB1Ԥ��Ƶ����գ�
	RCC->CFGR |= (0x4<<8);//����APB1Ԥ��Ƶ
	//TIMEx_Install(TIME2,1,TIMER_TS_Manager);
	//TIMEx_Install(TIME3,1000,TIM3_IRQHandler);
	//TIMEx_Install(TIME4,1000,TIM4_IRQHandler);
	//TIMEx_Install(TIME5,1000,TIM5_IRQHandler);
}

void TIMEx_Install(MyTIMx TIMEx,int ms,IRQ_pHandle pHandle)
{
	//��ȡTIMx��Ӧ���׵�ַ
	TIM_TypeDef* TIMx =((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx)));
	//ѡ��ʱ��ʱ�ӣ�CK_INT�ڲ�ʱ�� ��TIMx_SMCR����
	//ֻҪ�رմ���ģʽ TIMx_CR��cenλ��1��Ĭ��Ϊ0����Ԥ��Ƶ����ʱ�Ӿ���CK_INT�ṩ
	//CK_INT 72MHZ
	//��ʱ��ʱ��ѡ��CK_INT �ڲ�ʱ�ӣ�TIMx_SMCR �رմ�ģʽĬ�ϼ��رգ� cen�����ڲ�ʱ��
	//Ĭ�ϼ����������� TIMx->CR1 &= ~(1<<1);
		//����Ԥ��Ƶ�� 7200
	TIMx->PSC=7200-1;
	//�������ؼĴ�����ֵ
	TIMx->ARR=(ms*10-1);
	//ʹ�ܶ�ʱ���ж�
	TIMx->DIER |=(1<<0);
	//������ʱ������ ���ϼ���
	TIMx->CR1 |=(1<<0);
	switch(TIMEx)
	{
		case TIME2:
		case TIME3:
		case TIME4:
		{
			IRQ_Install((TIM2_IRQn+(int)TIMEx),pHandle);
		}break;
		case TIME5:
		{
			IRQ_Install(TIM5_IRQn,pHandle);
		}break;
	}
}

void TIME_Unintall(MyTIMx TIMEx)
{
	//��ȡTIMx��Ӧ�׵�ַ
	TIM_TypeDef* TIMx=((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx))) ;
	//�رո����ж�ʹ�� UIE
	TIMx->DIER &=~(1<<0);
	//�رն�ʱ��
	TIMx->CR1 &=~(1<<0);
	/*TIMx->PSC=0;//���Ԥ��Ƶ
	TIMx->ARR=0;//�������ؼĴ���ֵ
	TIMx->DIER &=~(1<<0);//ʹ�ܶ�ʱ�ж�
	TIMx->CR1 &=~(1<<0);//������ʱ������
	*/
	}

void TIME_Open(MyTIMx TIMEx)
{
	//��ȡTIMx��Ӧ�׵�ַ
	TIM_TypeDef* TIMx=((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx)));
	TIMx->CR1 |=(1<<0);//������ʱ������
}

void TIME_Stop(MyTIMx TIMEx)
{
	//��ȡTIMx��Ӧ�׵�ַ
	TIM_TypeDef* TIMx=((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx))) ;
	TIMx->CR1 &=~(1<<0);//�رն�ʱ������
}


/*------------------------��ʱ��--------------------------------*/

	//���жϳ�ʼ��
void TIMER_TS_Init(void)
{
	u8 Count=0;
	for(Count=0;Count<MAX_TS;Count++)
	{
		SoftTime_Events[Count].iCount=0;
		SoftTime_Events[Count].iCurent=0;
		SoftTime_Events[Count].isEnable=TIME_IS_DISABLE;
		SoftTime_Events[Count].isOpen=TIME_IS_ClOSE;
		SoftTime_Events[Count].TmpHandle=0;
	}
}

//���ж����ִ�к���
void TIMER_TS_Install(int RTIMEx,int Count,IRQ_pHandle TmpHandle)
{
	if(SoftTime_Events[RTIMEx].isEnable==TIME_IS_DISABLE)//�ж������λ�����ж�û�д򿪼�û��ռ�õĻ������¸���ṹ��
	{
		SoftTime_Events[RTIMEx].iCount=Count;
		SoftTime_Events[RTIMEx].iCurent=0;
		SoftTime_Events[RTIMEx].isEnable=TIME_IS_ENABLE;
		SoftTime_Events[RTIMEx].isOpen=TIME_IS_OPEN;
		SoftTime_Events[RTIMEx].TmpHandle=TmpHandle;
	}
}
//���жϿ���
void TIMER_TS_Open(int RTIMEx)
{
	SoftTime_Events[RTIMEx].isOpen=TIME_IS_OPEN;
}

//���ж�ֹͣ
void TIMER_TS_Close(int RTIMEx)
{
	SoftTime_Events[RTIMEx].isOpen=TIME_IS_ClOSE;
}

//�ж���������
void TIMER_TS_Destory(int RTIMEx)
{
	SoftTime_Events[RTIMEx].isEnable=TIME_IS_DISABLE;
}	



//���ж��ܹ���
void TIMER_TS_Manager(void)
{
	u8 Count=0;
	for(Count=0;Count<MAX_TS;Count++)
	{
		if((SoftTime_Events[Count].isEnable==TIME_IS_ENABLE) && (SoftTime_Events[Count].isOpen==TIME_IS_OPEN))
		{
				if(SoftTime_Events[Count].iCurent==SoftTime_Events[Count].iCount)
			{
				SoftTime_Events[Count].TmpHandle();
				SoftTime_Events[Count].iCurent=0;
			}
			else 
			{
				SoftTime_Events[Count].iCurent++;
			}
		}
	}
}



