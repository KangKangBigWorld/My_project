#include "My_Init.h"
#include "KeyBoard.h"
#include "Boot_test.h"
#include "My_view.h"
#include "picture.h"


int main(void)
{
	/*---------------------------------��ʼ��---------------------------*/
 	My_Init();
	Main_Background();

	/*--------------------������װ---------------------------*/
  
	TIMER_TS_Install(2,3000,DHT11_Show_T_H);//���ж�2��װ
	TIMER_TS_Install(3,2000,CLock_Manager);//���ж�3��װ
	TIMEx_Install(TIME2,1,TIMER_TS_Manager);
	
	while(1)
	{
	  //Txt_Event();
		 Main_Event();
		//KeyBoard_Touch();
	}
	
}
