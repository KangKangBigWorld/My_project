#include "My_View.h"



void color(int iFore,int iBack)	//�Զ��庯���ݲ����ı���ɫ 
{
	if ((iFore<16)&&(iBack<16))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(WORD)(iFore+iBack*16));	//ֻ��һ���������ı�������ɫ
	}
}

void Draw_line(int x,int y,int len)
{
	int i=0;
	GoTo_XY(x,y);
	color(BLUE,BLACK);
	for(i=0;i<=len;i++)
	{
		printf("�x");
	}
	printf("\n");
};



void Draw_Button(int x,int y,int iSelect,int iSColor,int iNSColor)
{
	GoTo_XY(x,y);
	if (iSelect)
	{
		color(iSColor,BLACK);
		printf("�X�j�T�T�T�T�T�j�[");
		GoTo_XY(x,y+1);
		printf("�d�g          �d�g");
		GoTo_XY(x,y+2);
		printf("�^�m�T�T�T�T�T�m�a");
		GoTo_XY(x+4,y+1);
		
	}
	else
	{
		color(iNSColor,BLACK);
		printf("���Щ����������Щ�");
		GoTo_XY(x,y+1);
		printf("����          ����");
		GoTo_XY(x,y+2);
		printf("���ة����������ة�");
		GoTo_XY(x+4,y+1);
	}
}

void Draw_Warning(int x,int y,int iColor)
{
	    GoTo_XY(x,y);
		color(iColor,BLACK);
		printf("�X�j�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�j�[");//19
		GoTo_XY(x,y+1);
		printf("�d�g                              �d�g");
		GoTo_XY(x,y+2);
		printf("�^�m�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�m�a");
		GoTo_XY(x+4,y+1);
}

void Clear_Warning(int x,int y)
{
	GoTo_XY(x,y);
	printf("                                      ");
	GoTo_XY(x,y+1);
	printf("                                      ");
	GoTo_XY(x,y+2);
	printf("                                      ");
	GoTo_XY(x+4,y+1);
}

void Draw_Popup(int x,int y,int hight,int iColor,char* sTitle)
{
int i=0;
GoTo_XY(x,y);
color(iColor,BLACK);
printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");//44����
GoTo_XY(x,y+1);  
printf("�U��                                    ���U");
for (i=2;i<hight-2;i++)
{
GoTo_XY(x,y+i);
printf("�U                                        �U");
}
GoTo_XY(x,y+i);
printf("�U��                                    ���U");
GoTo_XY(x,y+i+1);
printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
GoTo_XY(x+12,y+1);//ʮ���ֵĳ��� 20����
printf("%s",sTitle);
}

void Draw_FormIO(int x,int y)
{
	x=x+2;
	GoTo_XY(x,y);
	color(BLUE,BLACK);
	printf("���Щ����������Щ��������������Щ�");
	GoTo_XY(x,y+1);
	printf("����          ��              ����");
	GoTo_XY(x,y+2);
	printf("���ة����������ة��������������ة�");
	GoTo_XY(x+4,y+1);
}

void Clear_FormIO(int x,int y,char* cStr)
{
  *cStr='\0';
  GoTo_XY(x+18,y+1);
  printf("         ");
}

void Draw_Background(int iWide,int iHight)//����һ���������ڣ�����iWideΪ���Ŀ�ȣ�����iHightΪ���ĸ߶� 
{
	int i=0;
	int j=0;
	GoTo_XY(0,0);
	for(j=0;j<=iHight;j++)
	{
		if(j==0)
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("��");
				}
				else if(i==2)
				{
					printf("��");
				}
				else if(i==iWide-2)
				{
					printf("��");
				}
				else if(i==iWide)
				{
					printf("��\n");
				}
				else
				{
					printf("��");
				}
			}
		}
		else if(j==iHight)
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("��");
				}
				else if(i==2)
				{
					printf("��");
				}
				else if(i==iWide-2)
				{
					printf("��");
				}
				else if(i==iWide)
				{
					printf("��\n");
				}
				else
				{
					printf("��");
				}
			}		
		}
		else if(j==2||j==iHight-1)
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("��");
				}
				else if(i==1)
				{
					printf("��");
				}
				else if(i==2)
				{
					printf("��");
				}
				else if(i==iWide-2)
				{
					printf("��");
				}
				else if(i==iWide-1)
				{
					printf("��");
				}
				else if(i==iWide)
				{
					printf("��\n");
				}
				else
				{
					printf("��");
				}
			}		
		}
		else
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("��");
				}
				else if(i==1)
				{
					printf("��");
				}
				else if(i==2)
				{
					printf("��");
				}
				else if(i==iWide-2)
				{
					printf("��");
				}
				else if(i==iWide-1)
				{
					printf("��");
				}
				else if(i==iWide)
				{
					printf("��\n");
				}
				else
				{
					printf("  ");
				}
			}
		}	
	}
	
}
void Pritf_Tile(int iWide,int iHight,char* sTitle,char* sLowLeft,char* sLowRight)
{
	GoTo_XY(6,1);
	My_WeekDay();
	GoTo_XY((iWide-8),1);
	printf("%s",sTitle);
	GoTo_XY(2*iWide-14,1);
	My_Date();
	GoTo_XY(6,iHight-2);
	printf("%s",sLowLeft);
	GoTo_XY(2*iWide-16,iHight-2);
	printf("%s",sLowRight);
}

void My_ClearBG()
{
	int x=0;
	int y=0;
	int iCount=0;
	GoTo_XY(x+35,y+1);
	printf("                    ");
	for(iCount=0;iCount<20;iCount++)
	{
		GoTo_XY(x+6,y+3+iCount);
		printf("                                                                                ");
	}
	
}



void Draw_Main()
{
	Pritf_Tile(45,25," ׿ԽATMϵͳ ","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
	GoTo_XY(23,6);
	printf("    ��         ������������        ��    ��\n");
	GoTo_XY(23,7);
	printf("   ����             ��            ����  ���� \n");
	GoTo_XY(23,8);
	printf("  ��  ��            ��           ��  ����  �� \n");
	GoTo_XY(23,9);
	printf(" ��������           ��          ��    ��    ��\n");
	GoTo_XY(23,10);
	printf("��      ��          ��          ��          ��   \n");
}

void Draw_Main_Button(int iFlag)
{
	Draw_Button(8,12,(iFlag%4)==0,LBLUE,BLUE);
	printf("   ����   ");
	Draw_Button(8,17,(iFlag%4)==1,LBLUE,BLUE);
	printf(" ˢ�½��� ");
    Draw_Button(66,12,(iFlag%4)==2,LBLUE,BLUE);
	printf("   ����   ");
	Draw_Button(66,17,(iFlag%4)==3,LBLUE,BLUE);
	printf(" �˳�ATM  ");
	color(BLUE,BLACK);
}


void Draw_SignOut(int iFlag)
{
    GoTo_XY(37,1);
	printf("   Good Bye!");
	GoTo_XY(38,7);
	printf("�Ƿ��˳�����?");
	Draw_Button(35,10,iFlag%2==0,LBLUE,BLUE);
	printf("****��****");
	Draw_Button(35,15,iFlag%2==1,LBLUE,BLUE);
	printf("****��****");
	color(BLUE,BLACK);
}


void Draw_UserWin()
{
  My_ClearBG();
  Pritf_Tile(45,25," ׿ԽATMϵͳ ","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
  GoTo_XY(7,5);
  printf("  �x�y�z�{�|�}����������������������������������������~�}�|�{�z�y�x");
  GoTo_XY(23,10);
  printf("       ��      ������������     ��    ��\n");
  GoTo_XY(23,11);
  printf("      ����          ��         ����  ���� \n");
  GoTo_XY(23,12);
  printf("     ��  ��         ��        ��  ����  �� \n");
  GoTo_XY(23,13);
  printf("    ��������        ��       ��    ��    ��\n");
  GoTo_XY(23,14);
  printf("   ��      ��       ��       ��          ��   \n");

}

void Draw_AdminWin()
{
	My_ClearBG();
	Pritf_Tile(45,25," ׿ԽATMϵͳ ","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
	GoTo_XY(7,5);
	printf("  �x�y�z�{�|�}����������������������������������������~�}�|�{�z�y�x");
	GoTo_XY(23,10);
	printf("       ��      ������������     ��    ��\n");
	GoTo_XY(23,11);
	printf("      ����          ��         ����  ���� \n");
	GoTo_XY(23,12);
	printf("     ��  ��         ��        ��  ����  �� \n");
	GoTo_XY(23,13);
	printf("    ��������        ��       ��    ��    ��\n");
	GoTo_XY(23,14);
	printf("   ��      ��       ��       ��          ��   \n");
	
}



void Draw_User_Button(int iFlag)
{
	Draw_Button(6,7,(iFlag%8)==0,LBLUE,BLUE);
	printf("   ���   ");
	Draw_Button(6,10,(iFlag%8)==1,LBLUE,BLUE);
	printf("   ȡ��   ");
	Draw_Button(6,13,(iFlag%8)==2,LBLUE,BLUE);
	printf("   ת��   ");
	Draw_Button(6,16,(iFlag%8)==3,LBLUE,BLUE);
	printf("   ע��   ");
    Draw_Button(68,7,(iFlag%8)==4,LBLUE,BLUE);
	printf(" ����ѯ ");
	Draw_Button(68,10,(iFlag%8)==5,LBLUE,BLUE);
	printf(" ���׼�¼ ");
	Draw_Button(68,13,(iFlag%8)==6,LBLUE,BLUE);
	printf(" �޸����� ");
	Draw_Button(68,16,(iFlag%8)==7,LBLUE,BLUE);
	printf(" �˳�ATM  ");
	color(BLUE,BLACK);
}

void Draw_Admin_Button(int iFlag)
{
	Draw_Button(6,7,(iFlag%8)==0,LBLUE,BLUE);
	printf(" �û���ѯ ");
	Draw_Button(6,11,(iFlag%8)==1,LBLUE,BLUE);
	printf(" �����û� ");
	Draw_Button(6,15,(iFlag%8)==2,LBLUE,BLUE);
	printf("   ע��   ");
    Draw_Button(68,7,(iFlag%8)==3,LBLUE,BLUE);
	printf(" ɾ���û� ");
	Draw_Button(68,11,(iFlag%8)==4,LBLUE,BLUE);
	printf(" �޸����� ");
	Draw_Button(68,15,(iFlag%8)==5,LBLUE,BLUE);
	printf(" �˳�ATM  ");
	color(BLUE,BLACK);
}

void Draw_Page(int x,int y)
{
	int i=0;
	x=x-6;
GoTo_XY(x,y);
printf("�X�T�T�T�j�T�T�T�T�T�j�T�T�T�T�T�j�T�T�T�T�T�j�T�T�T�T�j�T�T�[");
GoTo_XY(x,y+1);
printf("�U ��� �U   ID��   �U �û����� �U �û����� �U  ���  �U״̬�U");
GoTo_XY(x,y+2);
printf("�d�T�T�T�p�T�T�T�T�T�p�T�T�T�T�T�p�T�T�T�T�T�p�T�T�T�T�p�T�T�g");
for(i=1;i<7;i++)
{
GoTo_XY(x,y+2*i+1);
printf("�U      �U          �U          �U          �U        �U    �U");
GoTo_XY(x,y+2*i+2);
printf("�d�T�T�T�p�T�T�T�T�T�p�T�T�T�T�T�p�T�T�T�T�T�p�T�T�T�T�p�T�T�g");
}
GoTo_XY(x,y+2*i+1);
printf("�U      �U          �U          �U          �U        �U    �U");
GoTo_XY(x,y+2*i+2);
printf("�^�T�T�T�m�T�T�T�T�T�m�T�T�T�T�T�m�T�T�T�T�T�m�T�T�T�T�m�T�T�a");
}


void Draw_Transaction(int x,int y,char* FirstTitle,char* SecondTitle,char* ThirdTitle)
{
    My_ClearBG();
	color(BLUE,BLACK);
	Draw_FormIO(x,y);
	printf(" ��ǰ��� ");
	Draw_FormIO(x,y+3);
	printf("%s",FirstTitle);
	Draw_FormIO(x,y+6);
	printf("%s",SecondTitle);
	Draw_FormIO(x,y+9);
	printf("%s",ThirdTitle);
    GoTo_XY(x+26,y+9);
	printf("00��");
}


void Draw_RecordPage(int x,int y)
{
	int i=0;
	x=x-6;
	GoTo_XY(x,y);
	printf("�X�T�T�T�j�T�T�T�T�T�j�T�T�T�T�T�T�j�T�T�T�T�T�T�j�T�T�T�j�T�T�T�T�T�[");
	GoTo_XY(x,y+1);
	printf("�U ��� �U ����ʱ�� �U  ���׽��  �U  �˻����  �U ժҪ �U���׷���Դ�U");
	GoTo_XY(x,y+2);
	printf("�d�T�T�T�p�T�T�T�T�T�p�T�T�T�T�T�T�p�T�T�T�T�T�T�p�T�T�T�p�T�T�T�T�T�g");
	for(i=1;i<6;i++)
	{
		GoTo_XY(x,y+2*i+1);
		printf("�U      �U          �U            �U            �U      �U          �U");
		GoTo_XY(x,y+2*i+2);
		printf("�d�T�T�T�p�T�T�T�T�T�p�T�T�T�T�T�T�p�T�T�T�T�T�T�p�T�T�T�p�T�T�T�T�T�g");
	}
	GoTo_XY(x,y+2*i+1);
	printf("�U      �U          �U            �U            �U      �U          �U");
	GoTo_XY(x,y+2*i+2);
	printf("�^�T�T�T�m�T�T�T�T�T�m�T�T�T�T�T�T�m�T�T�T�T�T�T�m�T�T�T�m�T�T�T�T�T�a");
}