#include "My_View.h"



void color(int iFore,int iBack)	//自定义函根据参数改变颜色 
{
	if ((iFore<16)&&(iBack<16))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(WORD)(iFore+iBack*16));	//只有一个参数，改变字体颜色
	}
}

void Draw_line(int x,int y,int len)
{
	int i=0;
	GoTo_XY(x,y);
	color(BLUE,BLACK);
	for(i=0;i<=len;i++)
	{
		printf("▁");
	}
	printf("\n");
};



void Draw_Button(int x,int y,int iSelect,int iSColor,int iNSColor)
{
	GoTo_XY(x,y);
	if (iSelect)
	{
		color(iSColor,BLACK);
		printf("╔╦═════╦╗");
		GoTo_XY(x,y+1);
		printf("╠╣          ╠╣");
		GoTo_XY(x,y+2);
		printf("╚╩═════╩╝");
		GoTo_XY(x+4,y+1);
		
	}
	else
	{
		color(iNSColor,BLACK);
		printf("┌┬─────┬┐");
		GoTo_XY(x,y+1);
		printf("├┤          ├┤");
		GoTo_XY(x,y+2);
		printf("└┴─────┴┘");
		GoTo_XY(x+4,y+1);
	}
}

void Draw_Warning(int x,int y,int iColor)
{
	    GoTo_XY(x,y);
		color(iColor,BLACK);
		printf("╔╦═══════════════╦╗");//19
		GoTo_XY(x,y+1);
		printf("╠╣                              ╠╣");
		GoTo_XY(x,y+2);
		printf("╚╩═══════════════╩╝");
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
printf("╔════════════════════╗");//44长度
GoTo_XY(x,y+1);  
printf("║■                                    ■║");
for (i=2;i<hight-2;i++)
{
GoTo_XY(x,y+i);
printf("║                                        ║");
}
GoTo_XY(x,y+i);
printf("║■                                    ■║");
GoTo_XY(x,y+i+1);
printf("╚════════════════════╝");
GoTo_XY(x+12,y+1);//十个字的长度 20长度
printf("%s",sTitle);
}

void Draw_FormIO(int x,int y)
{
	x=x+2;
	GoTo_XY(x,y);
	color(BLUE,BLACK);
	printf("┌┬─────┬───────┬┐");
	GoTo_XY(x,y+1);
	printf("├┤          │              ├┤");
	GoTo_XY(x,y+2);
	printf("└┴─────┴───────┴┘");
	GoTo_XY(x+4,y+1);
}

void Clear_FormIO(int x,int y,char* cStr)
{
  *cStr='\0';
  GoTo_XY(x+18,y+1);
  printf("         ");
}

void Draw_Background(int iWide,int iHight)//绘制一个背景窗口，参数iWide为表格的宽度，参数iHight为表格的高度 
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
					printf("┏");
				}
				else if(i==2)
				{
					printf("┳");
				}
				else if(i==iWide-2)
				{
					printf("┳");
				}
				else if(i==iWide)
				{
					printf("┓\n");
				}
				else
				{
					printf("━");
				}
			}
		}
		else if(j==iHight)
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("┗");
				}
				else if(i==2)
				{
					printf("┻");
				}
				else if(i==iWide-2)
				{
					printf("┻");
				}
				else if(i==iWide)
				{
					printf("┛\n");
				}
				else
				{
					printf("━");
				}
			}		
		}
		else if(j==2||j==iHight-1)
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("┣");
				}
				else if(i==1)
				{
					printf("━");
				}
				else if(i==2)
				{
					printf("╋");
				}
				else if(i==iWide-2)
				{
					printf("╋");
				}
				else if(i==iWide-1)
				{
					printf("━");
				}
				else if(i==iWide)
				{
					printf("┫\n");
				}
				else
				{
					printf("━");
				}
			}		
		}
		else
		{
			for(i=0;i<=iWide;i++)
			{
				if(i==0)
				{
					printf("┣");
				}
				else if(i==1)
				{
					printf("━");
				}
				else if(i==2)
				{
					printf("┫");
				}
				else if(i==iWide-2)
				{
					printf("┣");
				}
				else if(i==iWide-1)
				{
					printf("━");
				}
				else if(i==iWide)
				{
					printf("┫\n");
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
	Pritf_Tile(45,25," 卓越ATM系统 ","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
	GoTo_XY(23,6);
	printf("    ■         ■■■■■■        ■    ■\n");
	GoTo_XY(23,7);
	printf("   ■■             ■            ■■  ■■ \n");
	GoTo_XY(23,8);
	printf("  ■  ■            ■           ■  ■■  ■ \n");
	GoTo_XY(23,9);
	printf(" ■■■■           ■          ■    ■    ■\n");
	GoTo_XY(23,10);
	printf("■      ■          ■          ■          ■   \n");
}

void Draw_Main_Button(int iFlag)
{
	Draw_Button(8,12,(iFlag%4)==0,LBLUE,BLUE);
	printf("   开户   ");
	Draw_Button(8,17,(iFlag%4)==1,LBLUE,BLUE);
	printf(" 刷新界面 ");
    Draw_Button(66,12,(iFlag%4)==2,LBLUE,BLUE);
	printf("   登入   ");
	Draw_Button(66,17,(iFlag%4)==3,LBLUE,BLUE);
	printf(" 退出ATM  ");
	color(BLUE,BLACK);
}


void Draw_SignOut(int iFlag)
{
    GoTo_XY(37,1);
	printf("   Good Bye!");
	GoTo_XY(38,7);
	printf("是否退出程序?");
	Draw_Button(35,10,iFlag%2==0,LBLUE,BLUE);
	printf("****是****");
	Draw_Button(35,15,iFlag%2==1,LBLUE,BLUE);
	printf("****否****");
	color(BLUE,BLACK);
}


void Draw_UserWin()
{
  My_ClearBG();
  Pritf_Tile(45,25," 卓越ATM系统 ","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
  GoTo_XY(7,5);
  printf("  ▁▂▃▄▅▆█◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆█▇▆▅▄▃▂▁");
  GoTo_XY(23,10);
  printf("       ■      ■■■■■■     ■    ■\n");
  GoTo_XY(23,11);
  printf("      ■■          ■         ■■  ■■ \n");
  GoTo_XY(23,12);
  printf("     ■  ■         ■        ■  ■■  ■ \n");
  GoTo_XY(23,13);
  printf("    ■■■■        ■       ■    ■    ■\n");
  GoTo_XY(23,14);
  printf("   ■      ■       ■       ■          ■   \n");

}

void Draw_AdminWin()
{
	My_ClearBG();
	Pritf_Tile(45,25," 卓越ATM系统 ","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
	GoTo_XY(7,5);
	printf("  ▁▂▃▄▅▆█◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆█▇▆▅▄▃▂▁");
	GoTo_XY(23,10);
	printf("       ■      ■■■■■■     ■    ■\n");
	GoTo_XY(23,11);
	printf("      ■■          ■         ■■  ■■ \n");
	GoTo_XY(23,12);
	printf("     ■  ■         ■        ■  ■■  ■ \n");
	GoTo_XY(23,13);
	printf("    ■■■■        ■       ■    ■    ■\n");
	GoTo_XY(23,14);
	printf("   ■      ■       ■       ■          ■   \n");
	
}



void Draw_User_Button(int iFlag)
{
	Draw_Button(6,7,(iFlag%8)==0,LBLUE,BLUE);
	printf("   存款   ");
	Draw_Button(6,10,(iFlag%8)==1,LBLUE,BLUE);
	printf("   取款   ");
	Draw_Button(6,13,(iFlag%8)==2,LBLUE,BLUE);
	printf("   转账   ");
	Draw_Button(6,16,(iFlag%8)==3,LBLUE,BLUE);
	printf("   注销   ");
    Draw_Button(68,7,(iFlag%8)==4,LBLUE,BLUE);
	printf(" 余额查询 ");
	Draw_Button(68,10,(iFlag%8)==5,LBLUE,BLUE);
	printf(" 交易记录 ");
	Draw_Button(68,13,(iFlag%8)==6,LBLUE,BLUE);
	printf(" 修改密码 ");
	Draw_Button(68,16,(iFlag%8)==7,LBLUE,BLUE);
	printf(" 退出ATM  ");
	color(BLUE,BLACK);
}

void Draw_Admin_Button(int iFlag)
{
	Draw_Button(6,7,(iFlag%8)==0,LBLUE,BLUE);
	printf(" 用户查询 ");
	Draw_Button(6,11,(iFlag%8)==1,LBLUE,BLUE);
	printf(" 新增用户 ");
	Draw_Button(6,15,(iFlag%8)==2,LBLUE,BLUE);
	printf("   注销   ");
    Draw_Button(68,7,(iFlag%8)==3,LBLUE,BLUE);
	printf(" 删除用户 ");
	Draw_Button(68,11,(iFlag%8)==4,LBLUE,BLUE);
	printf(" 修改密码 ");
	Draw_Button(68,15,(iFlag%8)==5,LBLUE,BLUE);
	printf(" 退出ATM  ");
	color(BLUE,BLACK);
}

void Draw_Page(int x,int y)
{
	int i=0;
	x=x-6;
GoTo_XY(x,y);
printf("╔═══╦═════╦═════╦═════╦════╦══╗");
GoTo_XY(x,y+1);
printf("║ 序号 ║   ID号   ║ 用户类型 ║ 用户姓名 ║  余额  ║状态║");
GoTo_XY(x,y+2);
printf("╠═══╬═════╬═════╬═════╬════╬══╣");
for(i=1;i<7;i++)
{
GoTo_XY(x,y+2*i+1);
printf("║      ║          ║          ║          ║        ║    ║");
GoTo_XY(x,y+2*i+2);
printf("╠═══╬═════╬═════╬═════╬════╬══╣");
}
GoTo_XY(x,y+2*i+1);
printf("║      ║          ║          ║          ║        ║    ║");
GoTo_XY(x,y+2*i+2);
printf("╚═══╩═════╩═════╩═════╩════╩══╝");
}


void Draw_Transaction(int x,int y,char* FirstTitle,char* SecondTitle,char* ThirdTitle)
{
    My_ClearBG();
	color(BLUE,BLACK);
	Draw_FormIO(x,y);
	printf(" 当前余额 ");
	Draw_FormIO(x,y+3);
	printf("%s",FirstTitle);
	Draw_FormIO(x,y+6);
	printf("%s",SecondTitle);
	Draw_FormIO(x,y+9);
	printf("%s",ThirdTitle);
    GoTo_XY(x+26,y+9);
	printf("00￥");
}


void Draw_RecordPage(int x,int y)
{
	int i=0;
	x=x-6;
	GoTo_XY(x,y);
	printf("╔═══╦═════╦══════╦══════╦═══╦═════╗");
	GoTo_XY(x,y+1);
	printf("║ 序号 ║ 交易时间 ║  交易金额  ║  账户余额  ║ 摘要 ║交易发生源║");
	GoTo_XY(x,y+2);
	printf("╠═══╬═════╬══════╬══════╬═══╬═════╣");
	for(i=1;i<6;i++)
	{
		GoTo_XY(x,y+2*i+1);
		printf("║      ║          ║            ║            ║      ║          ║");
		GoTo_XY(x,y+2*i+2);
		printf("╠═══╬═════╬══════╬══════╬═══╬═════╣");
	}
	GoTo_XY(x,y+2*i+1);
	printf("║      ║          ║            ║            ║      ║          ║");
	GoTo_XY(x,y+2*i+2);
	printf("╚═══╩═════╩══════╩══════╩═══╩═════╝");
}