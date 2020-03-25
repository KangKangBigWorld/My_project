#ifndef _IRQ_H_
#define _IRQ_H_
#include "stm32f10x.h"
#include "Game_Snake.h"
#define IRQMAX 60 //�ܵ��жϸ���

typedef void (*IRQ_pHandle)();
//�жϵ���һ���¼���һ���ṹ��ź���ָ�룬�жϱ��

typedef struct IRQ_Event
{
	//�жϱ�� ����һ���жϣ�����һ�����
	IRQn_Type IRQNum;
	IRQ_pHandle IRQ_Heandle;
}IRQ_EVENT;


typedef struct softm_ts
{
	int iCount;//�Զ�װ�ص���ֵ���涨����ʱ��ִ�к���
	int iCurent;//������
	u8 isEnable;//�Ƿ�ʹ��
	u8 isOpen;//�Ƿ��
	IRQ_pHandle TmpHandle;
}SOFTM_TS;


extern IRQ_EVENT IRQ_Events[IRQMAX];



void KEY_Gpio_Init(void);
void KEY_Exti_Init(void);
//void KEY_Nvic_Init(void);
void KEY_Irq_Init(void);

void IRQ_Init(void);//IRQ��ʼ��
void IRQ_Install(IRQn_Type IRQNum,IRQ_pHandle IRQHandle);//IRQ��װ
void IRQ_Unload(IRQn_Type IRQNum,IRQ_pHandle IRQHandle);//IRQж��
void IRQ_PriorityGroup(short Group_Num);//�������ȼ����
void IRQ_Priority(IRQn_Type IRQNum,short Num);//�������ȼ���numΪ��λ����������ǰ��λ������ռλ
void IRQ_Desacth(void);//IRQ�������ж�ִ��



/*-------------------------�ж�ִ�к���-----------------------------*/

void EXTI0_IRQHandler(void);//�ϼ��Ĳ���
void EXTI2_IRQHandler(void);//����Ĳ���
void EXTI3_IRQHandler(void);//�¼��Ĳ���
void EXTI4_IRQHandler(void);//�Ҽ��Ĳ���




//void TIM3_IRQHandler(void);

//void TIM4_IRQHandler(void);

//void TIM5_IRQHandler(void);



#endif
