#ifndef _IRQ_H_
#define _IRQ_H_
#include "stm32f10x.h"
#include "Game_Snake.h"
#define IRQMAX 60 //总的中断个数

typedef void (*IRQ_pHandle)();
//中断当做一个事件，一个结构体放函数指针，中断编号

typedef struct IRQ_Event
{
	//中断编号 生成一个中断，生成一个编号
	IRQn_Type IRQNum;
	IRQ_pHandle IRQ_Heandle;
}IRQ_EVENT;


typedef struct softm_ts
{
	int iCount;//自动装载的数值，规定多少时间执行函数
	int iCurent;//计数器
	u8 isEnable;//是否使能
	u8 isOpen;//是否打开
	IRQ_pHandle TmpHandle;
}SOFTM_TS;


extern IRQ_EVENT IRQ_Events[IRQMAX];



void KEY_Gpio_Init(void);
void KEY_Exti_Init(void);
//void KEY_Nvic_Init(void);
void KEY_Irq_Init(void);

void IRQ_Init(void);//IRQ初始化
void IRQ_Install(IRQn_Type IRQNum,IRQ_pHandle IRQHandle);//IRQ安装
void IRQ_Unload(IRQn_Type IRQNum,IRQ_pHandle IRQHandle);//IRQ卸载
void IRQ_PriorityGroup(short Group_Num);//设置优先级组别
void IRQ_Priority(IRQn_Type IRQNum,short Num);//设置优先级，num为四位二进制数，前两位分配抢占位
void IRQ_Desacth(void);//IRQ搜索，中断执行



/*-------------------------中断执行函数-----------------------------*/

void EXTI0_IRQHandler(void);//上键的操作
void EXTI2_IRQHandler(void);//左键的操作
void EXTI3_IRQHandler(void);//下键的操作
void EXTI4_IRQHandler(void);//右键的操作




//void TIM3_IRQHandler(void);

//void TIM4_IRQHandler(void);

//void TIM5_IRQHandler(void);



#endif
