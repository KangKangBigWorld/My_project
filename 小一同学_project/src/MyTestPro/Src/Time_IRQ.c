#include "Time_IRQ.h"

SOFTM_TS SoftTime_Events[MAX_TS];


/*-------------------------------定时器中断-----------------------------------------*/

void TIME_Init(void)
{
	//RCC->APB1ENR |=RCC_APB1Periph;//定时器2时钟使能APB1
	RCC->APB1ENR |=(0xF<<0);//打开TIME2-5时钟使能，挂在APB1总线上
	
	RCC->CFGR &=~(0x7<<8);//配置APB1预分频（清空）
	RCC->CFGR |= (0x4<<8);//配置APB1预分频
	//TIMEx_Install(TIME2,1,TIMER_TS_Manager);
	//TIMEx_Install(TIME3,1000,TIM3_IRQHandler);
	//TIMEx_Install(TIME4,1000,TIM4_IRQHandler);
	//TIMEx_Install(TIME5,1000,TIM5_IRQHandler);
}

void TIMEx_Install(MyTIMx TIMEx,int ms,IRQ_pHandle pHandle)
{
	//获取TIMx对应的首地址
	TIM_TypeDef* TIMx =((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx)));
	//选择定时器时钟，CK_INT内部时钟 有TIMx_SMCR控制
	//只要关闭从事模式 TIMx_CR的cen位置1（默认为0），预分频器的时钟就由CK_INT提供
	//CK_INT 72MHZ
	//定时器时钟选择CK_INT 内部时钟，TIMx_SMCR 关闭从模式默认及关闭） cen就是内部时钟
	//默认计数方向向上 TIMx->CR1 &= ~(1<<1);
		//配置预分频器 7200
	TIMx->PSC=7200-1;
	//配置重载寄存器数值
	TIMx->ARR=(ms*10-1);
	//使能定时器中断
	TIMx->DIER |=(1<<0);
	//启动定时计数器 向上计数
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
	//获取TIMx对应首地址
	TIM_TypeDef* TIMx=((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx))) ;
	//关闭更新中断使能 UIE
	TIMx->DIER &=~(1<<0);
	//关闭定时器
	TIMx->CR1 &=~(1<<0);
	/*TIMx->PSC=0;//清除预分频
	TIMx->ARR=0;//配置重载寄存器值
	TIMx->DIER &=~(1<<0);//使能定时中断
	TIMx->CR1 &=~(1<<0);//启动定时计数器
	*/
	}

void TIME_Open(MyTIMx TIMEx)
{
	//获取TIMx对应首地址
	TIM_TypeDef* TIMx=((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx)));
	TIMx->CR1 |=(1<<0);//启动定时计数器
}

void TIME_Stop(MyTIMx TIMEx)
{
	//获取TIMx对应首地址
	TIM_TypeDef* TIMx=((TIM_TypeDef*)(TIM2_BASE+(0x400*TIMEx))) ;
	TIMx->CR1 &=~(1<<0);//关闭定时计数器
}


/*------------------------软定时器--------------------------------*/

	//软中断初始化
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

//软中断添加执行函数
void TIMER_TS_Install(int RTIMEx,int Count,IRQ_pHandle TmpHandle)
{
	if(SoftTime_Events[RTIMEx].isEnable==TIME_IS_DISABLE)//判断如果此位置软中断没有打开即没有占用的话，重新赋予结构体
	{
		SoftTime_Events[RTIMEx].iCount=Count;
		SoftTime_Events[RTIMEx].iCurent=0;
		SoftTime_Events[RTIMEx].isEnable=TIME_IS_ENABLE;
		SoftTime_Events[RTIMEx].isOpen=TIME_IS_OPEN;
		SoftTime_Events[RTIMEx].TmpHandle=TmpHandle;
	}
}
//软中断开启
void TIMER_TS_Open(int RTIMEx)
{
	SoftTime_Events[RTIMEx].isOpen=TIME_IS_OPEN;
}

//软中断停止
void TIMER_TS_Close(int RTIMEx)
{
	SoftTime_Events[RTIMEx].isOpen=TIME_IS_ClOSE;
}

//中断重新利用
void TIMER_TS_Destory(int RTIMEx)
{
	SoftTime_Events[RTIMEx].isEnable=TIME_IS_DISABLE;
}	



//软中断总管理
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



