#ifndef _TIME_IRQ_H_
#define _TIME_IRQ_H_

#include "stm32f10x.h"
#include "Irq.h"

#define MAX_TS 5  //���ʱ��Ŀ
#define TIME_IS_ENABLE 1 //��ʱ������
#define TIME_IS_DISABLE 0 //��ʱ��������
#define TIME_IS_OPEN 1   //��ʱ������
#define TIME_IS_ClOSE 0   //��ʱ���ر�

typedef enum
{
	TIME2,
	TIME3,
	TIME4,
	TIME5,
}MyTIMx;

extern SOFTM_TS SoftTime_Events[MAX_TS];

/*-------------------------��ʱ���ж�-----------------------------*/
//Ӳ��ʱ��TIM2-5��ʼ��
void TIME_Init(void);
//Ӳ��ʱ����װ
void TIMEx_Install(MyTIMx TIMEx,int ms,IRQ_pHandle pHandle);


/*-------------------------��ʱ��-----------------------------*/


void TIMER_TS_Init(void);//���жϳ�ʼ��

void TIMER_TS_Install(int RTIMEx,int count,IRQ_pHandle TmpHandle);//���ж����ִ�к���

void TIMER_TS_Open(int RTIMEx);//���жϿ���

void TIMER_TS_Close(int RTIMEx);//���ж�ֹͣ
	


void TIMER_TS_Destory(int RTIMEx);//�ж���������

//TIM2�ж�ִ�к���
void TIMER_TS_Manager(void);//���ж��ܹ���

#endif

