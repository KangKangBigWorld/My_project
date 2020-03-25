#include "My_Init.h"
#include "KeyBoard.h"
#include "Boot_test.h"
#include "My_view.h"
#include "picture.h"


int main(void)
{
	/*---------------------------------初始化---------------------------*/
 	My_Init();
	Main_Background();

	/*--------------------函数安装---------------------------*/
  
	TIMER_TS_Install(2,3000,DHT11_Show_T_H);//软中断2安装
	TIMER_TS_Install(3,2000,CLock_Manager);//软中断3安装
	TIMEx_Install(TIME2,1,TIMER_TS_Manager);
	
	while(1)
	{
	  //Txt_Event();
		 Main_Event();
		//KeyBoard_Touch();
	}
	
}
