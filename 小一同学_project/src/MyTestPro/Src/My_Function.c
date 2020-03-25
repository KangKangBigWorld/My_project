#include "My_Function.h"


pEVENTS pMainEvents;
pEVENTS pTxt;
pEVENTS pTemperature;
pEVENTS pMusic;
pEVENTS pMusicRename;
pEVENTS pColock;
pEVENTS pChangeColock;

u8 Exit_Flag;
u8 Wendu_Flag=0;
//�¼���ʼ��

void Event_Init(pEVENTS* pEvent)
{
	u8 Count=0;
	pEVENTS pEventData=NULL;
	*pEvent=(pEVENTS)calloc(SIZEOF_EVENTS,MAX_EVENT);
	if(*pEvent==NULL)
	{
		return;
	}
	pEventData=*pEvent;
	for(Count=0;Count<MAX_EVENT;Count++)
	{
		pEventData->Key_X1=0;
		pEventData->Key_Y1=0;
		pEventData->Key_X2=0;
		pEventData->Key_Y2=0;
		pEventData->isEnable=EVENT_DISABLE;
		pEventData->isOpen=EVENT_ClOSE;
		pEventData->Event_pHandle=0;	
		pEventData++;
	}
}


//�¼����ִ�к���

void Event_Install(pEVENTS pEvent,u8 EventNum,u16 x1,u16 y1,u16 x2,u16 y2,pHandle EvevtpHandle)
{
	u8 Count=0;
	pEVENTS pEventData=pEvent;
	for(Count=0;Count<EventNum;Count++)
	{
		pEventData++;
	}
	if(pEventData->isEnable==DISABLE)
	{
		pEventData->Key_X1=x1;
		pEventData->Key_Y1=y1;
		pEventData->Key_X2=x2;
		pEventData->Key_Y2=y2;
		pEventData->isEnable=EVENT_ENABLE;
		pEventData->isOpen=EVENT_ClOSE;
		pEventData->Event_pHandle=EvevtpHandle;
	}
}
//�¼���
void Event_Open(pEVENTS pEvent,u8 EventNum)
{
	u8 Count=0;
	pEVENTS pEventData=pEvent;
	for(Count=0;Count<EventNum;Count++)
	{
		pEventData++;
	}
	pEventData->isOpen=EVENT_OPEN;
}
//�¼��ر�
void Event_Close(pEVENTS pEvent,u8 EventNum)
{
	u8 Count=0;
	pEVENTS pEventData=pEvent;
	for(Count=0;Count<EventNum;Count++)
	{
		pEventData++;
	}
	pEventData->isOpen=EVENT_ClOSE;
}


//�¼���������
void Event_Destory(pEVENTS pEvent,u8 EventNum)
{
	u8 Count=0;
	pEVENTS pEventData=pEvent;
	for(Count=0;Count<EventNum;Count++)
	{
		pEventData++;
	}
	pEventData->isEnable=EVENT_DISABLE;
}	


//�¼�����
void Event_Manager(pEVENTS pEvent)
{
	u8 Count=0;
	pEVENTS pEventData=pEvent;
	for(Count=0;Count<MAX_EVENT;Count++)
	{
		if((pEventData->isEnable==EVENT_ENABLE) && (pEventData->isOpen==EVENT_OPEN))
		{

				pEventData->Event_pHandle();
				Event_Close(pEvent,Count);
		}
		pEventData++;
	}
}


void Exit()
{
	Exit_Flag=1;
	delay_ms(300);
}
//�¼���ʼ��
void My_Event_Init()
{
	//�������¼�����
	Event_Init(&pMainEvents);
	Event_Install(pMainEvents,0,12,31,12+64,111,Txt_Event);
	Event_Install(pMainEvents,1,88,31,88+64,111,music_Event);
	Event_Install(pMainEvents,2,164,31,164+64,111,temperature_Event);
	Event_Install(pMainEvents,3,12,128,12+64,208,colock_Event);
	Event_Install(pMainEvents,4,88,128,88+64,208,My_LED);
	
	//���±��¼�����
	Event_Init(&pTxt);
	Event_Install(pTxt,0,190,0,239,53,Exit);
	
	//��ʪ���¼�����
	Event_Init(&pTemperature);
	Event_Install(pTemperature,0,190,0,239,53,Exit);
	
	//�����¼�����
	Event_Init(&pMusic);
	Event_Install(pMusic,0,190,0,239,53,Exit);
	Event_Install(pMusic,1,0,0,48,53,My_MusicAdd);
	Event_Install(pMusic,2,0,72,239,72+24*5,Select_MusicLine);
	Event_Install(pMusic,3,0,194,119,234,Music_Rename);
	Event_Install(pMusic,4,120,194,239,234,Music_Delete);
	Event_Install(pMusic,5,14,250,82,298,Music_Last);
	Event_Install(pMusic,6,86,250,152,298,Music_Play);
	Event_Install(pMusic,7,158,250,216,298,Music_Next);
	Event_Install(pMusic,8,0,331,239,370,Music_Volume);
	
	//�����������¼�����
	Event_Init(&pMusicRename);
	Event_Install(pMusicRename,0,190,0,239,53,Rename_Exit);
	
	
	
	//�����¼�����
	Event_Init(&pColock);
	Event_Install(pColock,0,190,0,239,53,Exit);
	Event_Install(pColock,1,0,0,48,53,Add_Clock);
	Event_Install(pColock,2,0,64*1-10,64,64*4-10-1,My_ChangeClock);
	Event_Install(pColock,3,64,64*1-10,154,64*4-10-1,My_OpenClock);
	Event_Install(pColock,4,154,64*1-10,239,64*4-10-1,My_DeleteClock);
	
	//�޸����Ӵ���
	Event_Init(&pChangeColock);
	Event_Install(pChangeColock,1,154,64*1-10,239,103,My_DeleteClock2);
	Event_Install(pChangeColock,2,0,104,119,167,My_ChangeHour_Down);
	Event_Install(pChangeColock,3,0,168,119,229,My_ChangeHour_Up);
	Event_Install(pChangeColock,4,120,104,239,167,My_ChangeMin_Down);
	Event_Install(pChangeColock,5,120,168,239,229,My_ChangeMin_Up);
	Event_Install(pChangeColock,6,115,230,170,266,My_ChangeRepeat_Daily);
	Event_Install(pChangeColock,7,171,230,225,266,My_ChangeRepeat_OnlyOne);
	Event_Install(pChangeColock,8,115,230+36,170,266+36,My_ChangeRing_KC);
	Event_Install(pChangeColock,9,171,230+36,225,266+36,My_ChangeRing_ZX);
	Event_Install(pChangeColock,10,0,230+36*2,123,266+36*2,My_Cancel);
	Event_Install(pChangeColock,11,124,230+36*2,239,266+36*2,My_Save);
	
	
}


//�жϴ����¼� ����ʹ��
void Eevent_Touch(pEVENTS pEvent)
{
	while(Touch_iFlag==1)
	{
		u8 iCount=0;
		pEVENTS pEventData=pEvent;
		for(iCount=0;iCount<MAX_EVENT;iCount++)
		{
			if(((TouchData.lcdx>=pEventData->Key_X1)&&(TouchData.lcdx<=pEventData->Key_X2))&&((TouchData.lcdy>=pEventData->Key_Y1)&&(TouchData.lcdy<=pEventData->Key_Y2)))
			{
				Event_Open(pEvent,iCount);
				Touch_iFlag=0;
				Main_iFlag=0;
				return ;
			}
			pEventData++;
		}
		Touch_iFlag=0;
	}	
}


void Main_Event()
{
	TOUCH_Scan();
	Eevent_Touch(pMainEvents);
	Event_Manager(pMainEvents);
	Main_Background();
}


void Txt_Event()
{
	HIDE_FLAG=0;
	Busy("С����:���ڽ���С����");
	jishiben_BackGround();
	TIMER_TS_Install(1,1000,LED_Cursor);//���ж�1��װ
	Exit_Flag=0;
	while(!Exit_Flag)
	{
		TOUCH_Scan();
		KeyBoard_Touch();
		Eevent_Touch(pTxt);
		Event_Manager(pTxt);
	}
	TIMER_TS_Destory(1);
	Free();
	HIDE_FLAG=1;
}

void temperature_Event()
{
	Busy("��ʪ��:���ڼ����ʪ��");
	temperature_BackGround();
	Wendu_Flag=1;
	Exit_Flag=0;
	while(!Exit_Flag)
	{
		TOUCH_Scan();
		Eevent_Touch(pTemperature);
		Event_Manager(pTemperature);
	}
	Wendu_Flag=0;
}

void music_Event()
{
	Busy("��������,�ر���ʪ�ȼ��");
	TIMER_TS_Destory(2);//�ж���������
	music_BackGround();
	Exit_Flag=0;
	while(!Exit_Flag)
	{
		TOUCH_Scan();
		Eevent_Touch(pMusic);
		Event_Manager(pMusic);
	}
	Busy("�˳�����,����ʪ�ȼ��");
	TIMER_TS_Install(2,3000,DHT11_Show_T_H);//���ж�2��װ
}

void Music_Rename()
{
	HIDE_FLAG=0;
	Keyboard_Music=1;
	Show_RenameBackground();
	TIMER_TS_Install(1,1000,LED_Cursor);//���ж�1��װ
	Exit_Flag=0;
	while(!Exit_Flag)
	{
		TOUCH_Scan();
		KeyBoard_Touch();
		Eevent_Touch(pMusicRename);
		Event_Manager(pMusicRename);
	}
	TIMER_TS_Destory(1);
	Free();
	Keyboard_Music=0;
	HIDE_FLAG=1;
	Exit_Flag=0;
	music_BackGround();
}





void colock_Event()
{
	Busy("����:���ڽ�������");
	colock_BackGround();
	Exit_Flag=0;
	while(!Exit_Flag)
	{
		TOUCH_Scan();
		Eevent_Touch(pColock);
		Event_Manager(pColock);
	}
}






