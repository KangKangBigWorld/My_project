#include "My_Control.h"

void MainWIN_Control()
{
	FILE* fp=NULL;//创建用户文件的指针变量
	FILE* Rfp=NULL;//创建记录文件的指针变量
	FILE** pFp=&fp;//创建存放用户记录文件的指针变量
	FILE** pRFp=&Rfp;//创建存放记录记录文件的指针变量
	int iFlag=0;
	PULink pHead=NULL;//创建用户通用链表首地址
	PULink pRHead=NULL;//创建记录通用链表首地址
    char* Name_Date_User="User.txt";//用户的文件名字符数组指针变量
	char* Name_Date_Record="Record.txt";//记录的文件名字符数组指针变量
	Draw_Main();//绘制主界面图画
	Draw_Background(45,25);//绘背景框
	pHead=ULink_Init(User_Init());//初始化用户通用链表
	pRHead=ULink_Init(RLink_Init());//初始化记录通用链表
	User_SetAll(((PUser)pHead->pDate),19050001,SUPERADMIN,ACTIVE,"admin","123456",0);//初始化超级管理员放在头结点
    fp=File_Open(Name_Date_User);//打开用户文件
	Rfp=File_Open(Name_Date_Record);//打开记录文件
    pHead->pNext=(File_Read(fp,sizeof(User)))->pNext;//读取用户文件
	pRHead->pNext=(File_Read(Rfp,sizeof(Record)))->pNext;//读取记录文件
	while(1)
	{
		Draw_Main_Button(iFlag);
		Draw_Main();
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if(iFlag==0||iFlag==2)
				{
					iFlag++;
				}
				else
				{
					iFlag--;
				}
				
			}break;
		case KEY_DOWN:
			{
				if(iFlag==1||iFlag==3)
				{
					iFlag--;
				}
				else
				{
					iFlag++;
				}
			}break;
		case KEY_LEFT:
			{
				if(iFlag==0||iFlag==1)
				{
					iFlag+=2;
				}
				else
				{
					iFlag-=2;
				}
			}break;
		case KEY_RIGHT:
			{
				if(iFlag%4==2||iFlag%4==3)
				{
					iFlag-=2;
				}
				else
				{
					iFlag+=2;
				}
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0:
					{
						Register_Control(25,5,pHead,pFp,Name_Date_User,USER);//注册功能
					}break;
				case 1:
					{
						
					}break;
				case 2:
					{
						Login_Control(25,5,pHead,pFp,Name_Date_User,pRHead,pRFp,Name_Date_Record);//登录功能
						My_ClearBG();//清屏
					}break;
				case 3:
					{
						SignOut_Control();//退出
						Draw_Main();
					}break;
				}
			}break;
		case ESC:
			{
				SignOut_Control();
				Draw_Main();
			}
		}		
	}
}



void Login_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record)
{
	char sAccount[12]={'\0'};//账号数组
	char sPassword[8]={'\0'};//密码数组
	char sRePassword[8]={'\0'};//再次输入密码
	PULink pLoginUser=NULL;
	PUser pDate=NULL;
	int ifOver=0;
	int iFlag=0;//判断选项框的标志位
	// 	int iFlagAccount=0;//判断账号的标志位
	// 	int iFlagPassword=0;//判断密码的标志位
	// 	int iFlagRePassword=0;//判断账号的标志位
	My_ClearBG();
	GoTo_XY(41,1);
	printf("◆登录◆");
	Draw_Popup(x-2,y-2,20,LGREEN," ");
	Draw_Warning(x+1,y,LGREEN);
	printf(" 亲! 请选择账号或密码登录哦^-^");
	Draw_Button(x+11,y+5,iFlag%2==0,LBLUE,BLUE);
	printf("   账号   ");
	Draw_Button(x+11,y+10,iFlag%2==1,LBLUE,BLUE);
	printf("  用户名  ");
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iFlag==0)
				{
					iFlag=1;
				}
				else if(iFlag==1)
				{
					iFlag=0;
				}
			}break;
		case KEY_DOWN:
			{
				if (iFlag==0)
				{
					iFlag=1;
				}
				else if(iFlag==1)
				{
					iFlag=0;
				}
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0:
					{
						Draw_Popup(x-2,y-2,20,LGREEN," ");
						Draw_Warning(x+1,y,LGREEN);
						printf(" 亲! 注意周围环境是否安全哦^-^");
						Draw_FormIO(x,y+3);
						printf("  账号");
						Draw_FormIO(x,y+6);
						printf("  密码");
						iFlag=0;
						while(1)
						{
							switch(iFlag)
							{
							case 0:
								{
									switch(FormIO_Control(x,y+3,"",sAccount,8,NUMBER,PLAINTEXT))
									{
									case KEY_UP:
										{
											iFlag=1;
										}break;
									case KEY_DOWN:
										{
											iFlag=1; 
										}break;	
									case ESC:
										{
											My_ClearBG();
											return;
										}break;
									case ENTER:
										{
											Clear_Warning(x+1,y+12);
											if (strlen(sAccount)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 小卓发现您没有填写账号哟 ^-^");
												color(BLUE,BLACK);
											}
											else if(strlen(sAccount)<8)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("小卓分配给您账号是八位的呀^-^");
												}
												else
												{
													printf("再数数看账号是不是八位数字^-^");
												}
												Clear_FormIO(x,y+6,sAccount);
												color(BLUE,BLACK);
											}
											else if(!(ULink_Cmp(pHead,sAccount,User_IDcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 抱歉! 小卓没有找到该账号*-* ");
												Clear_FormIO(x,y+3,sAccount);
												color(BLUE,BLACK);
											}
											else
											{
												iFlag++;
											}
										}break;
									}	
								}break;
							case 1:
								{
									switch(FormIO_Control(x,y+6,"",sPassword,6,NUMBER,DARKTEXT))
									{
									case KEY_UP:
										{
											iFlag--;
										}break;
									case KEY_DOWN:
										{
											iFlag--; 
										}break;
									case ESC:
										{
											My_ClearBG();
											return;
										}break;
									case ENTER:
										{
											Clear_Warning(x+1,y+12);
											if (strlen(sPassword)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf(" 你这么美,没有密码可不行哦^-^");
												}
												else
												{
													printf(" 我写下代码,只为你写下密码^-^");
												}
												color(BLUE,BLACK);
											}
											else if(strlen(sPassword)<6)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("不足六位数字可不叫做密码哦^-^");
												}
												else
												{
													printf(" 密码不足六位,不能召唤小卓^-^");
												}
												Clear_FormIO(x,y+6,sPassword);
												color(BLUE,BLACK);
											}
											else if (strlen(sAccount)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 小卓发现您没有填写账号哟 ^-^");
												color(BLUE,BLACK);
											}
											else if(strlen(sAccount)<8)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("小卓分配给您账号是八位的呀^-^");
												}
												else
												{
													printf("再仔细数数看是不是八位数字^-^");
												}
												Clear_FormIO(x,y+6,sAccount);
												color(BLUE,BLACK);
											}
											else if(!(pLoginUser=ULink_Cmp(pHead,sAccount,User_IDcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 抱歉! 小卓没有找到该账号*-* ");
												Clear_FormIO(x,y+3,sAccount);
												color(BLUE,BLACK);
											}
											else if(User_Passwordcmp((pDate=(PUser)pLoginUser->pDate),sPassword))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 登录成功!按ENTER召唤小卓^-^ ");
												color(BLUE,BLACK);
                                                while(1)
												{
													if (Get_KeyValue()==ENTER)
													{
														break;
													}
												}
												switch(pDate->iIdentity)
												{
												case 0:
													{
														User_Control(pHead,pDate,pFp,Name_Date_User,pRHead,pRFp,Name_Date_Record);
														return;
													}break;
												case 1:
													{
														Admin_Control(pHead,pDate,pFp,Name_Date_User);
														return;
													}break;
												case 2:
													{
														Admin_Control(pHead,pDate,pFp,Name_Date_User);
														return;
													}break;
												}
												
											}
											else
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 阿喔! 您输入的密码有错呦*-* ");
												Clear_FormIO(x,y+6,sPassword);
												color(BLUE,BLACK);
											}
										}break;
									}	
								}break;
							}
						}
					}break;
				case 1:
					{
						Draw_Popup(x-2,y-2,20,LGREEN," ");
						Draw_Warning(x+1,y,LGREEN);
						printf(" 亲! 注意周围环境是否安全哦^-^");
						Draw_FormIO(x,y+3);
						printf(" 用户名");
						Draw_FormIO(x,y+6);
						printf("  密码");
						iFlag=0;
						while(1)
						{
							switch(iFlag)
							{
							case 0:
								{
									switch(FormIO_Control(x,y+3,"",sAccount,8,LETTER,PLAINTEXT))
									{
									case KEY_UP:
										{
											iFlag=1;
										}break;
									case KEY_DOWN:
										{
											iFlag=1; 
										}break;	
									case ESC:
										{
											My_ClearBG();
											return;
										}break;
									case ENTER:
										{
											Clear_Warning(x+1,y+12);
											if (strlen(sAccount)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf("小卓发现您没有填写用户名哟^-^");
												color(BLUE,BLACK);
											}
											else if(!(ULink_Cmp(pHead,sAccount,User_Accountcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 抱歉! 小卓没有找到该用户*-* ");
												Clear_FormIO(x,y+3,sAccount);
												color(BLUE,BLACK);
											}
											else
											{
												iFlag++;
											}
										}break;
									}	
								}break;
							case 1:
								{
									switch(FormIO_Control(x,y+6,"",sPassword,6,NUMBER,DARKTEXT))
									{
									case KEY_UP:
										{
											iFlag--;
										}break;
									case KEY_DOWN:
										{
											iFlag--; 
										}break;
									case ESC:
										{
											My_ClearBG();
											return;
										}break;
									case ENTER:
										{
											Clear_Warning(x+1,y+12);
											if (strlen(sPassword)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf(" 你这么美,没有密码可不行哦^-^");
												}
												else
												{
													printf(" 我写下代码,只为你写下密码^-^");
												}
												color(BLUE,BLACK);
											}
											else if(strlen(sPassword)<6)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("不足六位数字可不叫做密码哦^-^");
												}
												else
												{
													printf(" 密码不足六位,不能召唤小卓^-^");
												}
												Clear_FormIO(x,y+6,sPassword);
												color(BLUE,BLACK);
											}
											else if (strlen(sAccount)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf("小卓发现您没有填写用户名哟^-^");
												color(BLUE,BLACK);
											}
											else if(!(pLoginUser=ULink_Cmp(pHead,sAccount,User_Accountcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 抱歉! 小卓没有找到该用户*-* ");
												Clear_FormIO(x,y+3,sAccount);
												color(BLUE,BLACK);
											}
											else if(User_Passwordcmp((pDate=(PUser)pLoginUser->pDate),sPassword))
											{
												
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 登录成功!按ENTER召唤小卓^-^ ");
												color(BLUE,BLACK);
												while(1)
												{
													if (Get_KeyValue()==ENTER)
													{
														break;
													}
												}
												switch(pDate->iIdentity)
												{
												case 0:
													{
														User_Control(pHead,pDate,pFp,Name_Date_User,pRHead,pRFp,Name_Date_Record);
														return;
													}break;
												case 1:
													{
														Admin_Control(pHead,pDate,pFp,Name_Date_User);
														return;
													}break;
												case 2:
													{
														Admin_Control(pHead,pDate,pFp,Name_Date_User);
														return;
													}break;
												}
											}
											else
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" 阿喔! 您输入的密码有错呦*-* ");
												Clear_FormIO(x,y+6,sPassword);
												color(BLUE,BLACK);
											}
											
										}break;
										
									}	
								}break;
							}
						}
					}break;	
				}	  
			}break;	
		case ESC:
			{
				return;
			}break;
		}
		Draw_Button(x+11,y+5,iFlag%2==0,LBLUE,BLUE);
		printf("   账号   ");
		Draw_Button(x+11,y+10,iFlag%2==1,LBLUE,BLUE);
		printf("  用户名  ");
	}		
}


void SignOut_Control()
{
	int iFlag=0;
	My_ClearBG();
	while(1)
	{
		Draw_SignOut(iFlag);
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				iFlag++;
			}break;
		case KEY_DOWN:
			{
				iFlag++;
			}break;
		case ENTER:
			{
				switch(iFlag%2)
				{
				case 0:
					{
						exit(0);
					}break;
				case 1:
					{
						My_ClearBG();
						return;
					}
				}	
			}break;
		case ESC:
			{
				My_ClearBG();
				return;
			}
		}
	} 	
}


int FormIO_Control(int x,int y,char* pTips,char* cStr,int iMaxLen,int iPutType,int isPlaintext)
{
	x+=14;//光标横向偏移
	y+=1;//光标纵向偏移
	show_cursor();//显示光标
	GoTo_XY(x+22,y);
	printf("%s",pTips);
	switch(My_ConIO(cStr,iMaxLen,iPutType,isPlaintext,x+4,y))
	{
	case KEY_UP:
		{
			hide_cursor();//隐藏光标
			return KEY_UP;
		}break;
	case KEY_DOWN:
		{
			hide_cursor();//隐藏光标
			return KEY_DOWN;
		}break;
	case ENTER:
		{
			hide_cursor();//隐藏光标
			return ENTER;	
		}break;
	case ESC:
		{
			hide_cursor();//隐藏光标
			return ESC;
		}break;
	}		//警告是十八
	return 0;
}


void Register_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,int iIDentity)
{
	
	char sAccount[12]={'\0'};
	char sPassword[8]={'\0'};
	char sRePassword[8]={'\0'};
	PUser pDate=NULL;
	int ifOver=0;
	int iFlag=0;//判断选项框的标志位
	PULink pLast=ULink_GetNode(pHead,ULink_Count(pHead)-1);//找到为节点赋值给pLast
	int iNewId=User_GetID((PUser)(pLast->pDate))+(rand()%100)+1;//为节点id+1
	My_ClearBG();
	GoTo_XY(41,1);
	printf("◆注册◆");
	Draw_FormIO(x,y);
	printf("   账号");
	GoTo_XY(x+18,y+1);
	printf("%d",iNewId);
	Draw_FormIO(x,y+3);
	printf(" 英文姓名");
	Draw_FormIO(x,y+6);
	printf("  密码");
	Draw_FormIO(x,y+9);
	printf(" 确认密码");
	while(1)
	{     
		switch (iFlag)
		{
		case 0:
			{
				switch(FormIO_Control(x,y+3,"账号只属于您",sAccount,8,LETTER,PLAINTEXT))
				{
				case KEY_UP:
					{
						iFlag=2;
					}break;
				case KEY_DOWN:
					{
						iFlag++; 
					}break;	
				case ESC:
					{
						My_ClearBG();
						return;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						if (strlen(sAccount)==0)
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("别放空呀~小卓想知道您的名字^-^");
							color(BLUE,BLACK);
						}
						else if(ULink_Strmp(pHead,sAccount,User_Accountcmp))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("哎呀!这个名字已经被注册了*-*");
							Clear_FormIO(x,y+3,sAccount);
							color(BLUE,BLACK);
						}
						else
						{
							iFlag++;
						}
					}break;
				}
				GoTo_XY(x+36,y+4);
				printf("            ");	
			}break;
		case 1:
			{
				
				switch(FormIO_Control(x,y+6,"使用六位数字",sPassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag--;
					}break;
				case KEY_DOWN:
					{
						iFlag++; 
					}break;
				case ESC:
					{
						My_ClearBG();
						return;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						if (strlen(sPassword)==0)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 你这么美,没有密码可不行哦^-^");
							}
							else
							{
								printf(" 我写下代码,只为你写下密码^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(sPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 密码不足六位,这样不安全哦^-^");
							}
							else
							{
								printf(" 密码小于六位,请重新输入哦^-^");
							}
							Clear_FormIO(x,y+6,sPassword);
							color(BLUE,BLACK);
						}
						else
						{
							iFlag++;
						}
					}break;
				}
				GoTo_XY(x+36,y+7);
				printf("            ");
			}break;
		case 2:
			{
				
				switch(FormIO_Control(x,y+9,"使用六位数字",sRePassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag--;
					}break;
				case KEY_DOWN:
					{
						iFlag=0; 
					}break;
				case ESC:
					{ 
						My_ClearBG();
						return;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						GoTo_XY(x+36,y+10);
						printf("           ");
						if (strlen(sRePassword)==0)
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 你这么美,没有密码可不行哦^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(sRePassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 密码不足六位,这样不安全哦^-^");
							}
							else 
							{
								printf(" 密码小于六位,请重新输入哦^-^");
							}
							Clear_FormIO(x,y+9,sRePassword);
							color(BLUE,BLACK);
						}
						else if (!(strcmp(sPassword,sRePassword)))
						{
							if (strlen(sAccount)==0)
							{
								Draw_Warning(x,y+12,LGREEN);
								printf("别放空呀~小卓想知道您的名字^-^");
								color(BLUE,BLACK);
							}
							else if(ULink_Strmp(pHead,sAccount,User_Accountcmp))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" 哎呀!这个名字已经被注册了*-*");
								Clear_FormIO(x,y+3,sAccount);
								color(BLUE,BLACK);
							}
							else
							{
								iFlag=0;
								pDate=User_Init();
								User_SetAll(pDate,iNewId,iIDentity,ACTIVE,sAccount,sPassword,0);
								ULink_AddNode(pHead,pDate);
								Draw_Popup(x-2,y-2,20,LGREEN,"请牢记您的用户信息哦~");
								Draw_FormIO(x,y+1);
								printf(" 账户类型");
								GoTo_XY(x+18,y+2);
								User_PrtIdentity(((PUser)pLast->pNext->pDate));
								Draw_FormIO(x,y+4);
								printf(" ★账号★");
								GoTo_XY(x+18,y+5);
								User_PrtID(((PUser)pLast->pNext->pDate));
								Draw_FormIO(x,y+7);
								printf(" 英文姓名");
								GoTo_XY(x+18,y+8);
								User_PrtAccount(((PUser)pLast->pNext->pDate));
								Draw_FormIO(x,y+10);
								printf(" ★密码★");
								GoTo_XY(x+18,y+11);
								User_PrtPassword(((PUser)pLast->pNext->pDate));
								Draw_Button(x+2,y+14,iFlag%2==0,LGREEN,BLUE);
								printf("确认:ENTER");
								Draw_Button(x+20,y+14,iFlag%2==1,LGREEN,BLUE);
								printf(" 修改:ESC ");
								color(BLUE,BLACK);
								ifOver=1;
								while(ifOver)
								{
									switch(Get_KeyValue())
									{
									case KEY_LEFT:
										{
											if (iFlag==0)
											{
												iFlag=1;
											}
											else if(iFlag==1)
											{
												iFlag=0;
											}
										}break;
									case KEY_RIGHT:
										{
											if (iFlag==1)
											{
												iFlag=0;
											}
											else if (iFlag==0)
											{
												iFlag=1;
											}
										}break;
									case ENTER:
										{
											if (iFlag==0)
											{
                                               	*pFp=File_Write(pHead,Name_Date_User,sizeof(User));
												My_ClearBG();
												return;
											}
											else if(iFlag==1)
											{
												ULink_Del(pHead,ULink_Count(pHead)-1);
                                                ifOver=0;
											}
										}break;
									case ESC:
										{
											ULink_Del(pHead,ULink_Count(pHead)-1);
											ifOver=0;
										}break;
									}
									if (ifOver==0)
									{
										My_ClearBG();
										GoTo_XY(41,1);
										printf("◆注册◆");
										Draw_FormIO(x,y);
										printf("   账号");
										GoTo_XY(x+18,y+1);
										printf("%d",iNewId);
										Draw_FormIO(x,y+3);
										printf(" 英文姓名");
										GoTo_XY(x+18,y+4);
										printf("%s",sAccount);
										Draw_FormIO(x,y+6);
										printf("  密码");
										GoTo_XY(x+18,y+7);
										printf("%s",sPassword);
										Draw_FormIO(x,y+9);
										printf(" 确认密码");
										GoTo_XY(x+18,y+10);
										printf("%s",sRePassword);
										Draw_Warning(x,y+12,LGREEN);
										printf("亲! 已经为您显示密码,请修改^-^");
										iFlag=0;
										color(BLUE,BLACK);
									}
									else
									{
										Draw_Button(x+2,y+14,iFlag%2==0,LGREEN,BLUE);
										printf("确认:ENTER");
										Draw_Button(x+20,y+14,iFlag%2==1,LGREEN,BLUE);
										printf(" 修改:ESC ");
										color(BLUE,BLACK);
									}	
								}
							}
						}
						else
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 哦吼~两次输入密码不一致哦^-^");
							Clear_FormIO(x,y+9,sRePassword);
							color(BLUE,BLACK);
						}
					}break;
				}
				GoTo_XY(x+36,y+10);
				printf("           ");
			}break;
		}
	}
	getch();	
}


void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record)
{
	int iFlag=0;
	Draw_Background(45,25);
	My_ClearBG(); //清理屏幕
    Draw_UserWin();//用户界面
	Draw_User_Button(iFlag);//用户按钮
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iFlag==0||iFlag==4)
				{
					iFlag+=3;
				}
				else
				{
					iFlag--;
				}
			}break;
		case KEY_DOWN:
			{
				if (iFlag==3||iFlag==7)
				{
					iFlag-=3;
				}
				else
				{
					iFlag++;
				}	
			}break;
		case KEY_LEFT:
			{
				if (iFlag==0||iFlag==1||iFlag==2||iFlag==3)
				{
					iFlag+=4;
				}
				else
				{
					iFlag-=4;
				}
				
			}break;
		case KEY_RIGHT:
			{
				if (iFlag==0||iFlag==1||iFlag==2||iFlag==3)
				{
					iFlag+=4;
				}
				else
				{
					iFlag-=4;
				}	
			}break;
		case ESC:
			{
                if (Control_Cancell(21,4))
				{
					return;
				}//注销用户
				My_ClearBG(); //清理屏幕
                Draw_UserWin();//管理员界面
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0://存款功能
					{
						My_DepositControl(20,6,pHead,pFp,Name_Date_User,pDate,pRHead,pRFp,Name_Date_Record);
					}break;
				case 1://取款功能
					{
						My_WithdrawControl(20,6,pHead,pFp,Name_Date_User,pDate,pRHead,pRFp,Name_Date_Record);	
					}break;
				case 2://转账功能
					{
						My_TransferControl(20,6,pHead,pFp,Name_Date_User,pDate,pRHead,pRFp,Name_Date_Record);
					}break;
				case 3://注销功能
					{
						if (Control_Cancell(21,4))
						{
							return;
						}
					}break;
				case 4://余额查询
					{
						My_BalanceQueryControl(20,6,pDate);
					}break;
				case 5://交易记录
					{
						User_RecordControl(pRHead,pDate);
					}break;
				case 6://修改密码
					{
						if ((My_ChangePasswordControl(25,6,pHead,pDate,pFp,Name_Date_User))==ESC)
						{
							return;
						}
						
					}break;
				case 7://退出
					{
						SignOut_Control();
						Draw_UserWin();
						
					}break;	
				}
				My_ClearBG(); //清理屏幕
                Draw_UserWin();//管理员界面
				
			}break;	
		}
		
		Draw_User_Button(iFlag);
	}	
}

void User_Deposit()
{
	
	
}





void Admin_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User)
{
	int iFlag=0;
	Draw_Background(45,25);
	My_ClearBG(); //清理屏幕
    Draw_AdminWin();//管理员界面
	Draw_Admin_Button(iFlag);//用户按钮
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iFlag==0||iFlag==3)
				{
					iFlag+=2;
				}
				else
				{
					iFlag--;
				}
			}break;
		case KEY_DOWN:
			{
				if (iFlag==2||iFlag==5)
				{
					iFlag-=2;
				}
				else
				{
					iFlag++;
				}	
			}break;
		case KEY_LEFT:
			{
				if (iFlag==0||iFlag==1||iFlag==2)
				{
					iFlag+=3;
				}
				else
				{
					iFlag-=3;
				}
				
			}break;
		case KEY_RIGHT:
			{
				if (iFlag==0||iFlag==1||iFlag==2)
				{
					iFlag+=3;
				}
				else
				{
					iFlag-=3;
				}	
			}break;
		case ESC:
			{
                if (Control_Cancell(21,4))
				{
					return;
				}
				My_ClearBG(); //清理屏幕
                Draw_AdminWin();//管理员界面
				//注销用户
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0:
					{  
						Admin_Search_Control(pHead);	
						color(BLUE,BLACK);
					}break;
				case 1:
					{
						Admin_Register(pHead,pFp,Name_Date_User);  
					}break;
				case 2:
					{
						if (Control_Cancell(21,4))
						{
							return;
						}
					}break;
				case 3:
					{
						User_Delect(pHead,pDate,pFp,Name_Date_User);
						color(BLUE,BLACK);	
					}break;
				case 4:
					{
						User_ChangePassword(pHead,pDate,pFp,Name_Date_User);
						color(BLUE,BLACK);
					}break;
				case 5:
					{
						SignOut_Control();
						Draw_UserWin();
					}break;
					
				}
				My_ClearBG(); //清理屏幕
				Draw_AdminWin();//管理员界面
				
			}break;	
			
		}
		
		Draw_Admin_Button(iFlag);
	}	
}

void Admin_Search_Control(PULink pHead)
{
	PULink pTemp=NULL;
	int iFlag=0;
	My_ClearBG();
	GoTo_XY(36,1);
	printf("★管理员查询界面★");
	Draw_Button(36,6,iFlag%4==0,LBLUE,BLUE);
	printf(" 全部查询 ");
	Draw_Button(36,9,iFlag%4==1,LBLUE,BLUE);
	printf(" 分类查询 ");
	Draw_Button(36,12,iFlag%4==2,LBLUE,BLUE);
	printf(" 条件查询 ");
	Draw_Button(36,15,iFlag%4==3,LBLUE,BLUE);
	printf("   返回   ");
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iFlag==0)
				{
					iFlag=3;
				}
				else
				{
					iFlag--;
				}
			}break;
		case KEY_DOWN:
			{
				if (iFlag==3)
				{
					iFlag=0;
				}
				else
				{
					iFlag++;
				}   
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0:
					{
						My_ClearBG();
						GoTo_XY(39,1);
						printf("★全部查询★");
						Page_Turning(20,4,pHead,Page_Print,Draw_Page);
						My_ClearBG();
						GoTo_XY(36,1);
						printf("★管理员查询界面★");
					}break;
				case 1:
					{
						iFlag=0;
						My_ClearBG();
						GoTo_XY(36,1);
						printf("★管理员查询界面★");
						Draw_Button(36,6,iFlag%3==0,LBLUE,BLUE);
						printf("  管理员  ");
						Draw_Button(36,10,iFlag%3==1,LBLUE,BLUE);
						printf(" 普通用户 ");
						Draw_Button(36,14,iFlag%3==2,LBLUE,BLUE);
						printf("   返回   ");
						while(1)
						{
							switch(Get_KeyValue())
							{
							case KEY_UP:
								{
									if (iFlag==0)
									{
										iFlag=2;
									}
									else
									{
										iFlag--;
									}
								}break;
							case KEY_DOWN:
								{
									if (iFlag==2)
									{
										iFlag=0;
									}
									else
									{
										iFlag++;
									}	
								}break;
							case ENTER:
								{
									switch(iFlag)
									{
									case 0:
										{
											My_ClearBG();
											GoTo_XY(38,1);
											printf("★管理员查询★");
											Page_Turning(20,4,(pTemp=Select_Identity(pHead,1)),Page_Print,Draw_Page);
											ULink_Free(pTemp,1);
											My_ClearBG();
											GoTo_XY(36,1);
											printf("★管理员查询界面★");
										}break;
									case 1:
										{
											My_ClearBG();
											GoTo_XY(39,1);
											printf("★用户查询★  ");
											Page_Turning(20,4,(pTemp=Select_Identity(pHead,0)),Page_Print,Draw_Page);
											ULink_Free(pTemp,1);
											My_ClearBG();
											GoTo_XY(36,1);
											printf("★管理员查询界面★"); 
										}break;
									case 2:
										{ 
											return;
										}break;
									}
								}break;
							case ESC:
								{
									return;	
								}break;
							}
							Draw_Button(36,6,iFlag%3==0,LBLUE,BLUE);
							printf("  管理员  ");
							Draw_Button(36,10,iFlag%3==1,LBLUE,BLUE);
							printf(" 普通用户 ");
							Draw_Button(36,14,iFlag%3==2,LBLUE,BLUE);
							printf("   返回   ");
						}
					}break;
				case 2:
					{
						Fuzzy_Search(pHead);
						My_ClearBG();
						Pritf_Tile(45,25,"★管理员查询界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
					}break;
				case 3:
					{
						return;
					}break;
									}
								}break;
							case ESC:
								{
									return;   
								}break;
							}
							Draw_Button(36,6,iFlag%4==0,LBLUE,BLUE);
							printf(" 全部查询 ");
							Draw_Button(36,9,iFlag%4==1,LBLUE,BLUE);
							printf(" 分类查询 ");
							Draw_Button(36,12,iFlag%4==2,LBLUE,BLUE);
							printf(" 条件查询 ");
							Draw_Button(36,15,iFlag%4==3,LBLUE,BLUE);
							printf("   返回   ");
						}
}


void Page_Print(int x,int y,PULink pHead,int iPage,int iFlag)
{
	int i=0;
	x=x-6;
	y=y+3;
	for (i=0;i<7;i++)
	{
		GoTo_XY(x+46,y+2*i);
	    printf("        ");
	}
	for (i=0;i<7;i++)
	{
		if(pHead==NULL)
		{
			GoTo_XY(x+2,y+2*i);
			printf("      ");
			GoTo_XY(x+10,y+2*i);
			printf("          ");
			GoTo_XY(x+22,y+2*i);
			printf("          ");
			GoTo_XY(x+34,y+2*i);
			printf("          ");
			GoTo_XY(x+46,y+2*i);
			printf("        ");
			GoTo_XY(x+56,y+2*i);
			printf("    ");
			
		}
		else
		{
			if (i==iFlag)
			{
				color(LBLUE,BLACK);
			}
			GoTo_XY(x+2,y+2*i);
			printf("%-6d",iPage*7+i+1);
            GoTo_XY(x+10,y+2*i);
			printf("%8d",((PUser)pHead->pDate)->iID);
			GoTo_XY(x+22,y+2*i);
			if (((PUser)pHead->pDate)->iIdentity==USER)
			{
				printf(" 普通用户 ");
			}
			else
			{
				printf("  管理员  ");
			}
			GoTo_XY(x+34,y+2*i);
			printf("%-10s",((PUser)pHead->pDate)->cAccount);
			GoTo_XY(x+46,y+2*i);
			printf("%8d",((PUser)pHead->pDate)->iBalance);
			GoTo_XY(x+56,y+2*i);
			if (((PUser)pHead->pDate)->iCondition=ACTIVE)
			{
				printf("活跃");
			}
			else
			{
				printf("冻结");
			}
			pHead=pHead->pNext;
			if (i==iFlag)
			{
				color(BLUE,BLACK);
			}
		}
		
	}
}

void Page_Turning(int x,int y,PULink pHead,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int))
{
	int iCount=0;
	int iPageNum=0;
	int iLastNum=0;//总页数
	int iPage=0;//页数
	int iFlag=0;//被选择的选项
	PULink pTemp=NULL;
	PULink pPriHead=pHead;//开始打印的头节点地址
    iCount=ULink_Count(pHead);
	iLastNum=iCount%7;
	if (iLastNum)
	{
		iPageNum=iCount/7;
	}
	else
	{
		iPageNum=iCount/7-1;
	}
    pPriHead=ULink_GetNode(pHead,iPage*7);
	Page(x,y);
	My_Print(x,y,pPriHead,iPage,iFlag);
	GoTo_XY(x+22,y+17);
	printf("第%d/%d页",iPage+1,iPageNum+1);
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iPage==iPageNum&&iLastNum)
				{
					if (iFlag==0)
					{
						iFlag=iLastNum-1;
					}
					else
					{
						iFlag--;
					}
				}
				else
				{
					if (iFlag==0)
					{
						iFlag=6;
					}
					else
					{
						iFlag--;
					}
				}
				
			}break;
		case KEY_DOWN:
			{
				if (iPage==iPageNum&&iLastNum)
				{
					if (iFlag==iLastNum-1)
					{
						iFlag=0;
					}
					else
					{
						iFlag++;
					}
				}
				else
				{
					if (iFlag==6)
					{
						iFlag=0;
					}
					else
					{
						iFlag++;
					}
				}
				
			}break;
		case KEY_LEFT:
			{
				iFlag=0;
				iPage--;
				if (iPage<0)
				{
					Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("◇☆◆★已经是第一页了★◆☆◇");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
                    iPage++;
				}
				pPriHead=ULink_GetNode(pHead,iPage*7);
			}break;
		case KEY_RIGHT:
			{	
				iFlag=0;
				iPage++;
				if (iPage>iPageNum)
				{
					Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("◇☆◆★没有再下一页了★◆☆◇");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
                    iPage--;
				}
				pPriHead=ULink_GetNode(pHead,iPage*7);
			}break;
		case ENTER:
			{
				pTemp=ULink_GetNode(pHead,iPage*7+iFlag);
				
			}break;
		case ESC:
			{
				return;	
			}break;
		}
		My_Print(x,y,pPriHead,iPage,iFlag);
		GoTo_XY(x+22,y+17);
		printf("第%d/%d页",iPage+1,iPageNum+1);
	}
	
}

PULink Select_Identity(PULink pHead,int iIdentity)
{
	PULink pTemp=NULL;
	PUser pDate=NULL;
	if(!(pTemp=ULink_Init(NULL)))
	{
		return NULL;
	}
	pHead=pHead->pNext;
	pDate=User_Init();
	while(pHead!=NULL)
	{
		if (((PUser)pHead->pDate)->iIdentity==iIdentity)
		{
			memcpy(pDate,pHead->pDate,sizeof(User));
			ULink_AddNode(pTemp,pDate);
			pDate=User_Init();
		}
		pHead=pHead->pNext;
	}
	free(pDate);
	return pTemp;
}

PULink Select_UserName(PULink pHead,char* SearchName)
{
	PULink pTemp=NULL;
	PUser pDate=NULL;
	if(!(pTemp=ULink_Init(NULL)))
	{
		return NULL;
	}
	pHead=pHead->pNext;
	pDate=User_Init();
	while(pHead!=NULL)
	{
		if (strstr(((PUser)pHead->pDate)->cAccount,SearchName))
		{
			memcpy(pDate,pHead->pDate,sizeof(User));
			ULink_AddNode(pTemp,pDate);
			pDate=User_Init();
		}
		pHead=pHead->pNext;
	}
	free(pDate);
	return pTemp;
}


void Fuzzy_Search(PULink pHead)
{
	char cAccount[9]={'\0'};
	PULink pTemp=NULL;
	My_ClearBG();
	GoTo_XY(36,1);
	printf("★模糊/精确 查询★  ");
	Pritf_Tile(45,25,"★模糊/精确 查询★","确定:ENTER  方向键选择←↑↓→             查询成功后按ESC可再次查询","  退出:ESC");
	Draw_FormIO(25,3);
	printf("查询用户名");
	Draw_Page(20,6);
	while(1)
	{
		switch(FormIO_Control(25,3,"",cAccount,8,LETTER,PLAINTEXT))
		{
		case ESC:
			{
				return;
			}break;
		case ENTER:
			{
				if (strlen(cAccount)==0)
				{
					Draw_Popup(23,9,10,LGREEN,"        提示     ");
					Draw_Warning(26,11,LGREEN);
					printf("◇◆★抱歉,账号不能为空!★◆◇");
					Draw_Button(36,14,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					Draw_Page(20,6);		
				}
				pTemp=Select_UserName(pHead,cAccount);
				if (!(ULink_Count(pTemp)))
				{
					Draw_Popup(23,9,10,LGREEN,"        提示     ");
					Draw_Warning(26,11,LGREEN);
					printf("◇☆◆★抱歉,查无此人!★◆☆◇");
					Draw_Button(36,14,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					Draw_Page(20,6);
				}
				else
				{
              Page_Turning(20,6,pTemp,Page_Print,Draw_Page);
				}
				
				ULink_Free(pTemp,1);
			}break;
		}
	}
	
	My_ClearBG();
	GoTo_XY(36,1);
	printf("★管理员查询界面★");	
}

void Admin_Register(PULink pHead,FILE** pFp,char* Name_Date_User)
{
	int iFlag=0;
	My_ClearBG();
	Pritf_Tile(45,25,"★用户注册界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf(" ★★请选择注册用户的类型★★");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf("  管理员  ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf(" 普通用户 ");
		  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
		  printf("   返回   ");
		  while(1)
		  {
			  switch(Get_KeyValue())
			  {
			  case KEY_UP:
				  {
					  if (iFlag==0)
					  {
						  iFlag=2;
					  }
					  else
					  {
						  iFlag--;
					  }
					  
				  }break;
			  case KEY_DOWN:
				  {
					  if (iFlag==2)
					  {
						  iFlag=0;
					  }
					  else
					  {
						  iFlag++;
					  }
				  }break;
			  case ENTER:
				  {
					  switch(iFlag)
					  {
					  case 0:
						  {
							  Register_Control(25,5,pHead,pFp,Name_Date_User,ADMIN);
						  }break;
					  case 1:
						  {
							  Register_Control(25,5,pHead,pFp,Name_Date_User,USER);
						  }break;
					  case 2:
						  {
							  color(BLUE,BLACK);
							  return;
						  }break;
					  }
					  
				  }break;
			  case ESC:
				  {
					  color(BLUE,BLACK);
					  return;
				  }break;
			  }
			  Pritf_Tile(45,25,"★用户注册界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf(" ★★请选择注册用户的类型★★");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf("  管理员  ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf(" 普通用户 ");
			  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
			  printf("   返回   ");
		  }
		  
		  
		  
}

void User_Delect(PULink pHead,PUser pDate,FILE** pFp,char* pFilename)
{
	int iFlag=0;
	My_ClearBG();
	Pritf_Tile(45,25,"★用户删除界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf("  ★★请选择你的操作类型★★");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf(" 显示所有 ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf("   返回   ");
		  while(1)
		  {
			  switch(Get_KeyValue())
			  {
			  case KEY_UP:
				  {
					  if (iFlag==0)
					  {
						  iFlag=1;
					  }
					  else
					  {
						  iFlag--;
					  }
					  
				  }break;
			  case KEY_DOWN:
				  {
					  if (iFlag==1)
					  {
						  iFlag=0;
					  }
					  else
					  {
						  iFlag++;
					  }
				  }break;
			  case ENTER:
				  {
					  switch(iFlag)
					  {
					  case 0:
						  {
							  User_DelectControl(20,6,pFp,pFilename,pHead,pDate,Page_Print,Draw_Page);
							  My_ClearBG();
						  }break;
					  case 1:
						  {
							  return;
						  }break;
					  }
					  
				  }break;
			  case ESC:
				  {
					  return;
				  }break;
			  }
			  Pritf_Tile(45,25,"★用户注册界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf("  ★★请选择你的操作类型★★");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf(" 显示所有 ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf("   返回   ");
			  color(BLUE,BLACK);
		  }
		  
		  
}

void User_DelectControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int))
{
	int iCount=0;
	int iPageNum=0;
	int iLastNum=0;
	int temp1=0;
	int temp2=0;
	int iPage=0;//页数
	int iFlag=0;//被选择的选项
	int iMyFlag=0;
	PULink pTemp=NULL;
	PULink pPriHead=pHead;//开始打印的头节点地址
	y=y-2;
    iCount=ULink_Count(pHead);
	iLastNum=iCount%7;
	if (iLastNum)
	{
		iPageNum=iCount/7;
	}
	else
	{
		iPageNum=iCount/7-1;
	}
    pPriHead=ULink_GetNode(pHead,iPage*7);
	Page(x,y);
	My_Print(x,y,pPriHead,iPage,iFlag);
	GoTo_XY(x+22,y+17);
	printf("第%d/%d页",iPage+1,iPageNum+1);
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iPage==iPageNum&&iLastNum)
				{
					if (iFlag==0)
					{
						iFlag=iLastNum-1;
					}
					else
					{
						iFlag--;
					}
				}
				else
				{
					if (iFlag==0)
					{
						iFlag=6;
					}
					else
					{
						iFlag--;
					}
				}
				
			}break;
		case KEY_DOWN:
			{
				if (iPage==iPageNum&&iLastNum)
				{
					if (iFlag==iLastNum-1)
					{
						iFlag=0;
					}
					else
					{
						iFlag++;
					}
				}
				else
				{
					if (iFlag==6)
					{
						iFlag=0;
					}
					else
					{
						iFlag++;
					}
				}
				
			}break;
		case KEY_LEFT:
			{
				iFlag=0;
				iPage--;
				if (iPage<0)
				{
					Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("◇☆◆★已经是第一页了★◆☆◇");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
                    iPage++;
				}
				pPriHead=ULink_GetNode(pHead,iPage*7);
			}break;
		case KEY_RIGHT:
			{	
				iFlag=0;
				iPage++;
				if (iPage>iPageNum)
				{
					Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("◇☆◆★没有再下一页了★◆☆◇");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
                    iPage--;
				}
				pPriHead=ULink_GetNode(pHead,iPage*7);
			}break;
		case ENTER:
			{
				
				pTemp=ULink_GetNode(pHead,iPage*7+iFlag);
                temp1=((PUser)pTemp->pDate)->iIdentity;
				temp2=((PUser)pTemp->pDate)->iBalance;
				if (temp1>=(((PUser)pDate)->iIdentity))
				{
					Draw_Popup(x+3,y+3,10,RED,"      非法操作   ");
					Draw_Warning(x+6,y+5,RED);
					printf(" ◇☆◆★★权限不足★★◆☆◇");
					Draw_Button(x+16,y+8,1,RED,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
				}
				else if((temp2!=0))
				{
					Draw_Popup(x+3,y+3,10,RED,"      非法操作   ");
					Draw_Warning(x+6,y+5,RED);
					printf(" ◇☆◆★账户余额非零★◆☆◇");
					Draw_Button(x+16,y+8,1,RED,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
				}
				else
				{
					iMyFlag=0;
					Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("◇☆◆★请确认您的操作★◆☆◇");
					Draw_Button(x+6,y+8,iMyFlag%2==0,RED,LGREEN);
					printf("确定:ENTER");
					Draw_Button(x+26,y+8,iMyFlag%2==1,RED,LGREEN);
					printf(" 取消:ESC ");
					color(BLUE,BLACK);
					while(1)
					{
						switch(Get_KeyValue())
						{
						case KEY_LEFT:
							{
								if (iMyFlag==0)
								{
									iMyFlag=1;
								}
								else
								{
									iMyFlag--;
								}
								
							}break;
						case KEY_RIGHT:
							{
								if (iMyFlag==1)
								{
									iMyFlag=0;
								}
								else
								{
									iMyFlag++;
								}
							}break;
						case ENTER:
							{
								switch(iMyFlag)
								{
								case 0:
									{
										ULink_Del(pHead,(iPage*7+iFlag));
										*pFp=File_Write(pHead,pFilename,sizeof(User));
										Draw_Popup(x+3,y+3,10,LGREEN,"        警告     ");
										Draw_Warning(x+6,y+5,LGREEN);
										printf(" ◇☆◆★★删除成功★★◆☆◇");
										Draw_Button(x+16,y+8,1,LGREEN,GREEN);
										printf("确定:ENTER");
										color(BLUE,BLACK);
										while(Get_KeyValue()!=ENTER)
										{
											
										}
										return;
									}break;
								case 1:
									{
										My_ClearBG();
										color(BLUE,BLACK);
										return;
									}break;
								}
							}break;
						case ESC:
							{
								My_ClearBG();
								color(BLUE,BLACK);
								return;
							}break;
						}
						Draw_Button(x+6,y+8,iMyFlag%2==0,RED,LGREEN);
						printf("确定:ENTER");
						Draw_Button(x+26,y+8,iMyFlag%2==1,RED,LGREEN);
						printf(" 取消:ESC ");		
						
					}
					
				}
				Page(x,y);
				
			}break;
		case ESC:
			{
				return;	
			}break;
		}
		
		My_Print(x,y,pPriHead,iPage,iFlag);
		GoTo_XY(x+22,y+17);
		printf("第%d/%d页",iPage+1,iPageNum+1);
	}
	
}

void User_ChangePassword(PULink pHead,PUser pDate,FILE** pFp,char* pFilename)
{
	int iFlag=0;
	My_ClearBG();
	Pritf_Tile(45,25,"★修改密码界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf("  ★★请选择你的操作类型★★");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf(" 显示所有 ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf("   返回   ");
		  while(1)
		  {
			  switch(Get_KeyValue())
			  {
			  case KEY_UP:
				  {
					  if (iFlag==0)
					  {
						  iFlag=1;
					  }
					  else
					  {
						  iFlag--;
					  }
					  
				  }break;
			  case KEY_DOWN:
				  {
					  if (iFlag==1)
					  {
						  iFlag=0;
					  }
					  else
					  {
						  iFlag++;
					  }
				  }break;
			  case ENTER:
				  {
					  switch(iFlag)
					  {
					  case 0:
						  {
							  User_ChangePasswordControl(20,6,pFp,pFilename,pHead,pDate,Page_Print,Draw_Page);
							  My_ClearBG();
						  }break;
					  case 1:
						  {
							  return;
						  }break;
					  }
					  
				  }break;
			  case ESC:
				  {
					  return;
				  }break;
			  }
			  Pritf_Tile(45,25,"★修改密码界面★","确认:ENTER\t\t      按方向键选择","退出:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf("  ★★请选择你的操作类型★★");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf(" 显示所有 ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf("   返回   ");
		  }
		  
		  
}

int My_ChangePassword(int x,int y,PUser pDate)
{
	char cNewPassword[8]={'\0'};
	char cReNewPassword[8]={'\0'};
	int iFlag=0;
    My_ClearBG();
	GoTo_XY(39,1);
	printf("◆修改密码◆");
    Draw_FormIO(x,y);
	printf("   账号");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf(" 英文姓名");
	GoTo_XY(x+18,y+4);
	printf("%s",pDate->cAccount);
    Draw_FormIO(x,y+6);
	printf("  新密码");
	Draw_FormIO(x,y+9);
	printf(" 确认密码");
	while(1)
	{
		switch (iFlag)
		{			
		case 0:
			{
				
				switch(FormIO_Control(x,y+6,"使用六位数字",cNewPassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag=1;
					}break;
				case KEY_DOWN:
					{
						iFlag=1; 
					}break;
				case ESC:
					{
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						if (strlen(cNewPassword)==0)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 你这么美,没有密码可不行哦^-^");
							}
							else
							{
								printf(" 我写下代码,只为你写下密码^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(cNewPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 密码不足六位,这样不安全哦^-^");
							}
							else
							{
								printf(" 密码小于六位,请重新输入哦^-^");
							}
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						else if(!(strcmp(cNewPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 新密码不能与旧密码一样哦!^-^");
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						else
						{
							iFlag++;
						}
					}break;
				}
				GoTo_XY(x+36,y+7);
				printf("            ");
			}break;
		case 1:
			{
				
				switch(FormIO_Control(x,y+9,"使用六位数字",cReNewPassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag=0;
					}break;
				case KEY_DOWN:
					{
						iFlag=0; 
					}break;
				case ESC:
					{ 
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						GoTo_XY(x+36,y+10);
						printf("           ");
						if (strlen(cReNewPassword)==0)
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 你这么美,没有密码可不行哦^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(cReNewPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 密码不足六位,这样不安全哦^-^");
							}
							else 
							{
								printf(" 密码小于六位,请重新输入哦^-^");
							}
							Clear_FormIO(x,y+9,cReNewPassword);
							color(BLUE,BLACK);
						}
						else if (!(strcmp(cReNewPassword,cNewPassword)))
						{
							if (strlen(cNewPassword)==0)
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" 你这么美,没有密码可不行哦^-^");
								color(BLUE,BLACK);
							}
							else if(!(strcmp(pDate->cPasswod,cNewPassword)))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" 新密码不能与旧密码一样哦!^-^");
								Clear_FormIO(x,y+6,cNewPassword);
								color(BLUE,BLACK);
							}
							else
							{
								iFlag=0;
								memcpy(pDate->cPasswod,cNewPassword,8);
								Draw_Popup(x-2,y-2,19,LGREEN,"请牢记您的用户信息哦~");
								Draw_FormIO(x,y+1);
								printf(" 账户类型");
								GoTo_XY(x+18,y+2);
								User_PrtIdentity(pDate);
								Draw_FormIO(x,y+4);
								printf(" ★账号★");
								GoTo_XY(x+18,y+5);
								User_PrtID(pDate);
								Draw_FormIO(x,y+7);
								printf(" 英文姓名");
								GoTo_XY(x+18,y+8);
								User_PrtAccount(pDate);
								Draw_FormIO(x,y+10);
								printf(" ★密码★");
								GoTo_XY(x+18,y+11);
								User_PrtPassword(pDate);
								Draw_Button(x+11,y+13,iFlag%2==0,LGREEN,BLUE);
								printf("确认:ENTER");
								while(Get_KeyValue()!=ENTER)
								{
									
								};
								return 1;
							}
						}
						else
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 哦吼~两次输入密码不一致哦^-^");
							Clear_FormIO(x,y+9,cReNewPassword);
							color(BLUE,BLACK);
						}
					}break;
				}
				GoTo_XY(x+36,y+10);
				printf("           ");
			}break;
		}
	}	
	}
    
	
	
	
	
	void User_ChangePasswordControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int))
	{
		int iCount=0;
		int iPageNum=0;
		int iLastNum=0;
		char cNewPassword[8]={'\0'};
		char cReNewPassword[8]={'\0'};
		int iPage=0;//页数
		int iFlag=0;//被选择的选项
		PULink pTemp=NULL;
		PULink pPriHead=pHead;//开始打印的头节点地址
		y=y-2;
		iCount=ULink_Count(pHead);
		iLastNum=iCount%7;
		if (iLastNum)
		{
			iPageNum=iCount/7;
		}
		else
		{
			iPageNum=iCount/7-1;
		}
		pPriHead=ULink_GetNode(pHead,iPage*7);
		Page(x,y);
		My_Print(x,y,pPriHead,iPage,iFlag);
		GoTo_XY(x+22,y+17);
		printf("第%d/%d页",iPage+1,iPageNum+1);
		while(1)
		{
			switch(Get_KeyValue())
			{
			case KEY_UP:
				{
					if (iPage==iPageNum&&iLastNum)
					{
						if (iFlag==0)
						{
							iFlag=iLastNum-1;
						}
						else
						{
							iFlag--;
						}
					}
					else
					{
						if (iFlag==0)
						{
							iFlag=6;
						}
						else
						{
							iFlag--;
						}
					}
					
				}break;
			case KEY_DOWN:
				{
					if (iPage==iPageNum&&iLastNum)
					{
						if (iFlag==iLastNum-1)
						{
							iFlag=0;
						}
						else
						{
							iFlag++;
						}
					}
					else
					{
						if (iFlag==6)
						{
							iFlag=0;
						}
						else
						{
							iFlag++;
						}
					}
					
				}break;
			case KEY_LEFT:
				{
					iFlag=0;
					iPage--;
					if (iPage<0)
					{
						Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf("◇☆◆★已经是第一页了★◆☆◇");
						Draw_Button(x+16,y+8,1,LGREEN,GREEN);
						printf("确定:ENTER");
						color(BLUE,BLACK);
						while(Get_KeyValue()!=ENTER)
						{
							
						}
						Page(x,y);
						iPage++;
					}
					pPriHead=ULink_GetNode(pHead,iPage*7);
				}break;
			case KEY_RIGHT:
				{	
					iFlag=0;
					iPage++;
					if (iPage>iPageNum)
					{
						Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf("◇☆◆★没有再下一页了★◆☆◇");
						Draw_Button(x+16,y+8,1,LGREEN,GREEN);
						printf("确定:ENTER");
						color(BLUE,BLACK);
						while(Get_KeyValue()!=ENTER)
						{
							
						}
						Page(x,y);
						iPage--;
					}
					pPriHead=ULink_GetNode(pHead,iPage*7);
				}break;
			case ENTER:
				{
					
					pTemp=ULink_GetNode(pHead,iPage*7+iFlag);
					if ((((PUser)pTemp->pDate)->iIdentity)>=(((PUser)pDate)->iIdentity))
					{
						Draw_Popup(x+3,y+3,10,RED,"      非法操作   ");
						Draw_Warning(x+6,y+5,RED);
						printf(" ◇☆◆★★权限不足★★◆☆◇");
						Draw_Button(x+16,y+8,1,RED,GREEN);
						printf("确定:ENTER");
						color(BLUE,BLACK);
						while(Get_KeyValue()!=ENTER)
						{
							
						}
                        Page(x,y);
					}
					else
					{
						iFlag=0;
						Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf("◇☆◆★请确认您的操作★◆☆◇");
						Draw_Button(x+6,y+8,iFlag%2==0,RED,LGREEN);
						printf("确定:ENTER");
						Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
						printf(" 取消:ESC ");
						color(BLUE,BLACK);
						while(1)
						{
							switch(Get_KeyValue())
							{
							case KEY_LEFT:
								{
									if (iFlag==0)
									{
										iFlag=1;
									}
									else
									{
										iFlag--;
									}
									
								}break;
							case KEY_RIGHT:
								{
									if (iFlag==1)
									{
										iFlag=0;
									}
									else
									{
										iFlag++;
									}
								}break;
							case ENTER:
								{
									
									switch(iFlag)
									{
									case 0:
										{
											
											if(My_ChangePassword(x+5,y+2,((PUser)(pTemp->pDate))))
											{
												*pFp=File_Write(pHead,pFilename,sizeof(User));
												Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
												Draw_Warning(x+6,y+5,LGREEN);
												printf(" ◇☆◆★★修改成功★★◆☆◇");
												Draw_Button(x+16,y+8,1,LGREEN,GREEN);
											}
											else
											{
												Draw_Popup(x+3,y+3,10,LGREEN,"        提示     ");
												Draw_Warning(x+6,y+5,LGREEN);
												printf(" ◇☆◆★★修改失败★★◆☆◇");
												Draw_Button(x+16,y+8,1,LGREEN,GREEN);
											}
											
											printf("确定:ENTER");
											color(BLUE,BLACK);
											while(Get_KeyValue()!=ENTER)
											{
												
											}
											return;
										}break;
									case 1:
										{
											My_ClearBG();
											color(BLUE,BLACK);
											return;
										}break;
									}
								}break;
							case ESC:
								{
									My_ClearBG();
									color(BLUE,BLACK);
									return;
								}break;
							}
							Draw_Button(x+6,y+8,iFlag%2==0,RED,LGREEN);
							printf("确定:ENTER");
							Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
							printf(" 取消:ESC ");		
							
						}
						
					}
					Page(x,y);
					
				}break;
			case ESC:
				{
					return;	
				}break;
		}
		
		My_Print(x,y,pPriHead,iPage,iFlag);
		GoTo_XY(x+22,y+17);
		printf("第%d/%d页",iPage+1,iPageNum+1);
	}	
}

int Control_Cancell(int x,int y)
{
	int iFlag=0;
	Draw_Popup(x+3,y+3,10,LGREEN,"        注销     ");
	Draw_Warning(x+6,y+5,LGREEN);
	printf("◇☆◆★是否注销用户? ★◆☆◇");
	Draw_Button(x+6,y+8,iFlag%2==0,RED,LGREEN);
	printf("确定:ENTER");
	Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
	printf(" 取消:ESC ");
	color(BLUE,BLACK);
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_LEFT:
			{
				if (iFlag==0)
				{
					iFlag=1;
				}
				else
				{
					iFlag--;
				}
				
			}break;
		case KEY_RIGHT:
			{
				if (iFlag==1)
				{
					iFlag=0;
				}
				else
				{
					iFlag++;
				}
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0:
					{
						Draw_Popup(x+3,y+3,10,LGREEN,"        注销     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf(" ◇☆◆★★注销成功★★◆☆◇");
						Draw_Button(x+16,y+8,1,LGREEN,GREEN);
						printf("确定:ENTER");
						color(BLUE,BLACK);
						while(Get_KeyValue()!=ENTER)
						{
							
						}
						return 1;
					}break;
				case 1:
					{
						My_ClearBG();
						color(BLUE,BLACK);
						return 0;
					}break;
				}
			}break;
		case ESC:
			{
				My_ClearBG();
				color(BLUE,BLACK);
				return 0;
			}break;
		}
		Draw_Button(x+6,y+8,iFlag%2==0,RED,LGREEN);
		printf("确定:ENTER");
		Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
		printf(" 取消:ESC ");		
		
	}
	
}


int My_DepositControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record)
{
	int iFlag=0;
	char cDealMoney[4]={'\0'};
	int iDealMoney=0;
	PRecord pRDate=NULL;
	x=x+5;
	My_ClearBG();
	GoTo_XY(39,1);
	printf("◆存款界面◆");
    Draw_FormIO(x,y);
	printf("   账号");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf(" 英文姓名");
	GoTo_XY(x+18,y+4);
	printf("%s",pDate->cAccount);
    Draw_FormIO(x,y+6);
	printf("当前余额");
	GoTo_XY(x+18,y+7);
	printf("%d￥",pDate->iBalance);
	Draw_FormIO(x,y+9);
	printf("存款100/张");
	GoTo_XY(x,y+12);
	printf("Tip:单笔存款不可以超过一百张(百元面值)");
	while (1)
	{
		switch(FormIO_Control(x,y+9,"人民币",cDealMoney,3,NUMBER,PLAINTEXT))
		{
		case ESC:
			{
				My_ClearBG();
				return 0;
			}break;
		case ENTER:
			{
				Clear_Warning(x,y+13);
				if (strlen(cDealMoney)==0)
				{
					Draw_Warning(x,y+13,LGREEN);
					printf(" 你这么美,放空不填可不行哦^-^");
					color(BLUE,BLACK);
				}
				else if((iDealMoney=My_DealMoney(x,y,cDealMoney)))
				{
					Draw_Popup(x-2,y+3,10,LGREEN,"      温馨提示   ");
					Draw_Warning(x+1,y+5,LGREEN);
					printf("◇☆◆★是否确定存款? ★◆☆◇");
					Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
					printf("确定:ENTER");
					Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
					printf(" 取消:ESC ");
					color(BLUE,BLACK);
					while(1)
					{
						switch(Get_KeyValue())
						{
						case KEY_LEFT:
							{
								if (iFlag==0)
								{
									iFlag=1;
								}
								else
								{
									iFlag--;
								}
								
							}break;
						case KEY_RIGHT:
							{
								if (iFlag==1)
								{
									iFlag=0;
								}
								else
								{
									iFlag++;
								}
							}break;
						case ENTER:
							{
								switch(iFlag)
								{
								case 0:
									{
										pRDate=RLink_Init();
										Set_RecordTime(pRDate);
										Set_RecordInfor(pRDate,0,pDate->iID,iDealMoney,DEPOSIT,pDate->iBalance,(pDate->iBalance)+iDealMoney);
										(pDate->iBalance)+=iDealMoney;
										ULink_AddNode(pRHead,pRDate);
										*pFp=File_Write(pHead,Name_Date_User,sizeof(User));
										*pRFp=File_Write(pRHead,Name_Date_Record,sizeof(Record));
										Draw_Popup(x-2,y-2,19,LGREEN,"★★★存款成功★★★");
										Draw_FormIO(x,y+1);
										printf(" ★账号★");
										GoTo_XY(x+18,y+2);
										User_PrtID(pDate);
										Draw_FormIO(x,y+4);
										printf(" 英文姓名");
										GoTo_XY(x+18,y+5);
										User_PrtAccount(pDate);
										Draw_FormIO(x,y+7);
										printf(" 存款金额");
										GoTo_XY(x+18,y+8);
										printf("%d￥",iDealMoney);
										Draw_FormIO(x,y+10);
										printf(" 当前余额");
										GoTo_XY(x+18,y+11);
										printf("%d￥",pDate->iBalance);
										Draw_Button(x+11,y+13,1,LGREEN,BLUE);
										printf("确认:ENTER");
										color(BLUE,BLACK);
										while(Get_KeyValue()!=ENTER)
										{
											
										};
										return 1;
									}break;
								case 1:
									{
										My_ClearBG();
										color(BLUE,BLACK);
										return 0;
									}break;
								}
							}break;
						case ESC:
							{
								My_ClearBG();
								color(BLUE,BLACK);
								return 0;
							}break;
						}
						Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
						printf("确定:ENTER");
						Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
						printf(" 取消:ESC ");		
						
					}
					
				} 
			}break;
		}
	}
}

int My_WithdrawControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record)
{
	int iFlag=0;
	char cDealMoney[4]={'\0'};
	int iDealMoney=0;
	PRecord pRDate=NULL;
	x=x+5;
	My_ClearBG();
	GoTo_XY(39,1);
	printf("◆取款界面◆");
    Draw_FormIO(x,y);
	printf("   账号");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf(" 英文姓名");
	GoTo_XY(x+18,y+4);
	printf("%s",pDate->cAccount);
    Draw_FormIO(x,y+6);
	printf("当前余额");
	GoTo_XY(x+18,y+7);
	printf("%d￥",pDate->iBalance);
	Draw_FormIO(x,y+9);
	printf("取款100/张");
	GoTo_XY(x,y+12);
	printf("Tip:单笔取款不可以超过一百张(百元面值)");
	while (1)
	{
		switch(FormIO_Control(x,y+9,"人民币",cDealMoney,3,NUMBER,PLAINTEXT))
		{
		case ESC:
			{
				My_ClearBG();
				return 0;
			}break;
		case ENTER:
			{
				Clear_Warning(x,y+13);
				if (strlen(cDealMoney)==0)
				{
					Draw_Warning(x,y+13,LGREEN);
					printf(" 你这么美,放空不填可不行哦^-^");
					color(BLUE,BLACK);
				}
				else if ((iDealMoney=My_DealMoney(x,y,cDealMoney))>pDate->iBalance)
				{
                    Draw_Warning(x,y+13,LGREEN);
					printf("余额不足,取款失败,按ENTER继续");
					color(BLUE,BLACK);
				}
				else if((iDealMoney=My_DealMoney(x,y,cDealMoney)))
				{
                    Draw_Popup(x-2,y+3,10,LGREEN,"      温馨提示   ");
					Draw_Warning(x+1,y+5,LGREEN);
					printf("◇☆◆★是否确定存款? ★◆☆◇");
					Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
					printf("确定:ENTER");
					Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
					printf(" 取消:ESC ");
					color(BLUE,BLACK);
					while(1)
					{
						switch(Get_KeyValue())
						{
						case KEY_LEFT:
							{
								if (iFlag==0)
								{
									iFlag=1;
								}
								else
								{
									iFlag--;
								}
								
							}break;
						case KEY_RIGHT:
							{
								if (iFlag==1)
								{
									iFlag=0;
								}
								else
								{
									iFlag++;
								}
							}break;
						case ENTER:
							{
								switch(iFlag)
								{
								case 0:
									{
										pRDate=RLink_Init();
										Set_RecordTime(pRDate);
										Set_RecordInfor(pRDate,0,pDate->iID,iDealMoney,WITHDRAW,pDate->iBalance,(pDate->iBalance)-iDealMoney);
										(pDate->iBalance)-=iDealMoney;
										ULink_AddNode(pRHead,pRDate);
										*pFp=File_Write(pHead,Name_Date_User,sizeof(User));
										*pRFp=File_Write(pRHead,Name_Date_Record,sizeof(Record));
										Draw_Popup(x-2,y-2,19,LGREEN,"★★★取款成功★★★");
										Draw_FormIO(x,y+1);
										printf(" ★账号★");
										GoTo_XY(x+18,y+2);
										User_PrtID(pDate);
										Draw_FormIO(x,y+4);
										printf(" 英文姓名");
										GoTo_XY(x+18,y+5);
										User_PrtAccount(pDate);
										Draw_FormIO(x,y+7);
										printf(" 取款金额");
										GoTo_XY(x+18,y+8);
										printf("%d￥",iDealMoney);
										Draw_FormIO(x,y+10);
										printf(" 当前余额");
										GoTo_XY(x+18,y+11);
										printf("%d￥",pDate->iBalance);
										Draw_Button(x+11,y+13,1,LGREEN,BLUE);
										printf("确认:ENTER");
										color(BLUE,BLACK);
										while(Get_KeyValue()!=ENTER)
										{
											
										};
										return 1;
									}break;
								case 1:
									{
										My_ClearBG();
										color(BLUE,BLACK);
										return 0;
									}break;
								}
							}break;
						case ESC:
							{
								My_ClearBG();
								color(BLUE,BLACK);
								return 0;
							}break;
						}
						Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
						printf("确定:ENTER");
						Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
						printf(" 取消:ESC ");					
					}	
				} 
			}break;
		}
	}
}

int My_TransferControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record)
{
	int iFlag=0;
	char cDealMoney[4]={'\0'};
	char cID[8]={'\0'};
	int iDealMoney=0;
	PRecord pRDate=NULL;//源账户记录
	PRecord pAimRDate=NULL;//目标账户记录
	PULink pAimHead=NULL;//目标用户通用链表首地址
	PUser pAimDate=NULL;//目标用户数据域
	x=x+5;
	My_ClearBG();
	GoTo_XY(39,1);
	printf("◆转账界面◆");
    Draw_FormIO(x,y-3);
	printf(" 当前账号");
	GoTo_XY(x+18,y-2);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y);
	printf("当前余额");
	GoTo_XY(x+18,y+1);
	printf("%d￥",pDate->iBalance);
	Draw_FormIO(x,y+3);
	printf(" 转账账号");
    Draw_FormIO(x,y+6);
	printf("转账账户名");
	Draw_FormIO(x,y+9);
	printf("转账100/张");
	GoTo_XY(x,y+12);
	printf("Tip:单笔转账不可以超过一百张(百元面值)");
	while (1)
	{
		switch(iFlag)
		{
		case 0:
			{
				switch(FormIO_Control(x,y+3,"",cID,8,NUMBER,PLAINTEXT))
				{
				
				case ESC:
					{
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x+1,y+13);
						if (strlen(cID)==0)
						{
							Draw_Warning(x+1,y+13,LGREEN);
							printf("啊哦~您没有填写转账账号哟~^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(cID)<8)
						{
							Draw_Warning(x+1,y+13,LGREEN);
							printf("再数数看账号是不是八位数字^-^");
							Clear_FormIO(x,y+6,cID);
							color(BLUE,BLACK);
						}
						else if(!(ULink_Cmp(pHead,cID,User_IDcmp)))
						{
							Draw_Warning(x+1,y+13,LGREEN);
							printf(" 抱歉! 小卓没有找到该账号*-* ");
							Clear_FormIO(x,y+3,cID);
							Clear_FormIO(x,y+6,cID);
							color(BLUE,BLACK);
						}
						else
						{
							pAimHead=ULink_Cmp(pHead,cID,User_IDcmp);
							pAimDate=(PUser)pAimHead->pDate;
							GoTo_XY(x+18,y+7);
							printf("%s",pAimDate->cAccount);
							iFlag++;
							if(pAimDate->iIdentity==ADMIN||pAimDate->iIdentity==SUPERADMIN)
							{
								Draw_Warning(x+1,y+13,LGREEN);
								printf(" 抱歉! 不允许给管理员转账*-* ");
								Clear_FormIO(x,y+3,cID);
								Clear_FormIO(x,y+6,cID);
								color(BLUE,BLACK);
								iFlag--;
							}
							else if(pDate->iID==pAimDate->iID)
							{
								Draw_Warning(x+1,y+13,LGREEN);
								printf("  抱歉! 不允许给自己转账*-* ");
								Clear_FormIO(x,y+3,cID);
								Clear_FormIO(x,y+6,cID);
								color(BLUE,BLACK);
								iFlag--;
							}
						}
					}break;
									}

			}break;
		case 1:
			{
				switch(FormIO_Control(x,y+9,"人民币",cDealMoney,3,NUMBER,PLAINTEXT))
				{
				case KEY_UP:
					{
						iFlag=0;
					}break;
				case KEY_DOWN:
					{
						iFlag=0; 
					}break;	
				case ESC:
					{
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+13);
						if (strlen(cDealMoney)==0)
						{
							Draw_Warning(x,y+13,LGREEN);
							printf(" 亲!转账金额放空不填可不行哦^-^");
							color(BLUE,BLACK);
						}
					
						else if ((iDealMoney=My_TransferMoney(x,y,cDealMoney))>pDate->iBalance)
						{
							Draw_Warning(x,y+13,LGREEN);
							printf("余额不足,转账失败,按ENTER继续");
							Clear_FormIO(x,y+9,cDealMoney);
							color(BLUE,BLACK);
						}
						else if(iDealMoney)
						{
							Draw_Popup(x-2,y+3,10,LGREEN,"      温馨提示   ");
							Draw_Warning(x+1,y+5,LGREEN);
							printf("◇☆◆★是否确定转账? ★◆☆◇");
							Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
							printf("确定:ENTER");
							Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
							printf(" 退出:ESC ");
							color(BLUE,BLACK);
							while(1)
							{
								switch(Get_KeyValue())
								{
								case KEY_LEFT:
									{
										if (iFlag==0)
										{
											iFlag=1;
										}
										else
										{
											iFlag--;
										}
										
									}break;
								case KEY_RIGHT:
									{
										if (iFlag==1)
										{
											iFlag=0;
										}
										else
										{
											iFlag++;
										}
									}break;
								case ENTER:
									{
										switch(iFlag)
										{
										case 0:
											{
												pRDate=RLink_Init();
												pAimRDate=RLink_Init();
												Set_RecordTime(pRDate);
												Set_RecordTime(pAimRDate);
												Set_RecordInfor(pRDate,pAimDate->iID,pDate->iID,iDealMoney,TURNOUT,pDate->iBalance,(pDate->iBalance)-iDealMoney);
												(pDate->iBalance)-=iDealMoney;
												Set_RecordInfor(pAimRDate,pDate->iID,pAimDate->iID,iDealMoney,TURNIN,pAimDate->iBalance,(pAimDate->iBalance)+iDealMoney);
												(pAimDate->iBalance)+=iDealMoney;
												ULink_AddNode(pRHead,pRDate);
												ULink_AddNode(pRHead,pAimRDate);
												*pFp=File_Write(pHead,Name_Date_User,sizeof(User));
												*pRFp=File_Write(pRHead,Name_Date_Record,sizeof(Record));
												Draw_Popup(x-2,y-3,20,LGREEN,"★★★转账成功★★★");
												Draw_FormIO(x,y+1);
												printf(" 转账账号");
												GoTo_XY(x+18,y+2);
												printf("%d",pAimDate->iID);
												Draw_FormIO(x,y+4);
												printf("转账用户名");
												GoTo_XY(x+18,y+5);
												printf("%s",pAimDate->cAccount);
												Draw_FormIO(x,y+7);
												printf(" 转账金额");
												GoTo_XY(x+18,y+8);
												printf("%d￥",iDealMoney);
												Draw_FormIO(x,y+10);
												printf(" 当前余额");
												GoTo_XY(x+18,y+11);
												printf("%d￥",pDate->iBalance);
												Draw_Button(x+11,y+13,1,LGREEN,BLUE);
												printf("确认:ENTER");
												color(BLUE,BLACK);
												while(Get_KeyValue()!=ENTER)
												{
													
												};
												return 1;
											}break;
										case 1:
											{
												My_ClearBG();
												color(BLUE,BLACK);
												return 0;
											}break;
										}
									}break;
								case ESC:
									{
										My_ClearBG();
										color(BLUE,BLACK);
										return 0;
									}break;
								}
								Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
								printf("确定:ENTER");
								Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
								printf(" 取消:ESC ");					
							}	
						} 
			}break;
		}
			}break;
		}
		
	}
}



int My_BalanceQueryControl(int x,int y,PUser pDate)
{
	int iFlag=0;
	int iYes=0;
	x=x+5;
	My_ClearBG();
	while(1)
	{
		GoTo_XY(39,1);
		printf("◆余额查询◆");
		Draw_FormIO(x,y);
		printf("   账号");
		GoTo_XY(x+18,y+1);
		printf("%d",pDate->iID);
		Draw_FormIO(x,y+3);
		printf(" 英文姓名");
		GoTo_XY(x+18,y+4);
		printf("%s",pDate->cAccount);
		Draw_FormIO(x,y+6);
		printf("当前余额");
		GoTo_XY(x+18,y+7);
	    printf("%d￥",pDate->iBalance);
		switch(Get_KeyValue())
		{
		case ESC:
			{
				Draw_Popup(x-2,y+3,10,LGREEN,"      温馨提示   ");
				Draw_Warning(x+1,y+5,LGREEN);
				printf("◇☆◆是否留在当前页面? ◆☆◇");
				Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
				printf("确定:ENTER");
				Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
				printf(" 退出:ESC ");
				color(BLUE,BLACK);
				while(1)
				{
					switch(Get_KeyValue())
					{
					case KEY_LEFT:
						{
							if (iFlag==0)
							{
								iFlag=1;
							}
							else
							{
								iFlag--;
							}
							
						}break;
					case KEY_RIGHT:
						{
							if (iFlag==1)
							{
								iFlag=0;
							}
							else
							{
								iFlag++;
							}
						}break;
					case ENTER:
						{
							switch(iFlag)
							{
							case 0:
								{
									iYes=1;
									
								}break;
							case 1:
								{
									My_ClearBG();
									color(BLUE,BLACK);
									return 0;
								}break;
							}
						}break;
					case ESC:
						{
							My_ClearBG();
							color(BLUE,BLACK);
							return 0;
						}break;
					}
					if (iYes==1)
					{
						My_ClearBG();
						color(BLUE,BLACK);
						iYes=0;
						break;
					}
					Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
					printf("确定:ENTER");
					Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
					printf(" 退出:ESC ");					
				}
			}
		}
                            	
	}
	
}


int My_ChangePasswordControl(int x,int y,PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User)
{
	char cOldPassword[8]={'\0'};
	char cNewPassword[8]={'\0'};
	char cReNewPassword[8]={'\0'};
	int iFlag=0;
    My_ClearBG();
	GoTo_XY(39,1);
	printf("◆修改密码◆");
    Draw_FormIO(x,y);
	printf("   账号");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf("  旧密码");
    Draw_FormIO(x,y+6);
	printf("  新密码");
	Draw_FormIO(x,y+9);
	printf(" 确认密码");
	while(1)
	{
		switch (iFlag)
		{
		case 0:
			{
				
				switch(FormIO_Control(x,y+3,"使用六位数字",cOldPassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag=2;
					}break;
				case KEY_DOWN:
					{
						iFlag++; 
					}break;
				case ESC:
					{
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						if (strlen(cOldPassword)==0)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 你这么美,没有密码可不行哦^-^");
							}
							else
							{
								printf(" 我写下代码,只为你写下密码^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(cOldPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
						    printf(" 密码小于六位,请重新输入哦^-^");
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if((strcmp(cOldPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("旧密码输入错误,请重新输入!^-^");
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else
						{
							iFlag++;
						}
					}break;
				}
				GoTo_XY(x+36,y+4);
				printf("            ");
			}break;
		case 1:
			{
				
				switch(FormIO_Control(x,y+6,"使用六位数字",cNewPassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag--;
					}break;
				case KEY_DOWN:
					{
						iFlag++; 
					}break;
				case ESC:
					{
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						if ((strlen(cNewPassword)==0)||(strlen(cOldPassword)==0))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 你这么美,没有密码可不行哦^-^");
							}
							else
							{
								printf(" 我写下代码,只为你写下密码^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(cOldPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 密码不足六位,这样不安全哦^-^");
							}
							else
							{
								printf(" 密码小于六位,请重新输入哦^-^");
							}
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if((strlen(cNewPassword)<6))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 密码不足六位,这样不安全哦^-^");
							}
							else
							{
								printf(" 密码小于六位,请重新输入哦^-^");
							}
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						
						else if((strcmp(cOldPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("旧密码输入错误,请重新输入!^-^");
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if(!(strcmp(cNewPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 新密码不能与旧密码一样哦!^-^");
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						else
						{
							iFlag++;
						}
					}break;
				}
				GoTo_XY(x+36,y+7);
				printf("            ");
			}break;
		case 2:
			{
				
				switch(FormIO_Control(x,y+9,"使用六位数字",cReNewPassword,6,NUMBER,DARKTEXT))
				{
				case KEY_UP:
					{
						iFlag--;
					}break;
				case KEY_DOWN:
					{
						iFlag=0; 
					}break;
				case ESC:
					{ 
						My_ClearBG();
						return 0;
					}break;
				case ENTER:
					{
						Clear_Warning(x,y+12);
						GoTo_XY(x+36,y+10);
						printf("           ");
						if (strlen(cReNewPassword)==0||((strlen(cNewPassword)==0))||((strlen(cOldPassword)==0)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 你这么美,没有密码可不行哦^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(cOldPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 旧密码不足六位,这样不安全哦!");
							}
							else
							{
								printf(" 旧密码小于六位,请重新输入哦!");
							}
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if((strlen(cNewPassword)<6))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 新密码不足六位,这样不安全哦!");
							}
							else
							{
								printf(" 新密码小于六位,请重新输入哦!");
							}
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						else if((strlen(cReNewPassword)<6))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" 新密码不足六位,这样不安全哦!");
							}
							else 
							{
								printf(" 新密码小于六位,请重新输入哦!");
							}
							Clear_FormIO(x,y+9,cReNewPassword);
							color(BLUE,BLACK);
						}
						else if (!(strcmp(cReNewPassword,cNewPassword)))
						{
							if (strlen(cNewPassword)==0)
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" 亲~ 您的新密码不能为空哦!^-^");
								color(BLUE,BLACK);
							}
							else if((strcmp(cOldPassword,pDate->cPasswod)))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf("旧密码输入错误,请重新输入!^-^");
								Clear_FormIO(x,y+3,cOldPassword);
								color(BLUE,BLACK);
							}
							else if(!(strcmp(pDate->cPasswod,cNewPassword)))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" 新密码不能与旧密码一样哦!^-^");
								Clear_FormIO(x,y+6,cNewPassword);
								Clear_FormIO(x,y+6,cReNewPassword);
								color(BLUE,BLACK);
							}
							else
							{
								iFlag=0;
								memcpy(pDate->cPasswod,cNewPassword,8);
								*pFp=File_Write(pHead,Name_Date_User,sizeof(User));
								Draw_Popup(x-2,y-2,19,LGREEN,"请牢记您的用户信息哦~");
								Draw_FormIO(x,y+1);
								printf(" 账户类型");
								GoTo_XY(x+18,y+2);
								User_PrtIdentity(pDate);
								Draw_FormIO(x,y+4);
								printf(" ★账号★");
								GoTo_XY(x+18,y+5);
								User_PrtID(pDate);
								Draw_FormIO(x,y+7);
								printf(" 英文姓名");
								GoTo_XY(x+18,y+8);
								User_PrtAccount(pDate);
								Draw_FormIO(x,y+10);
								printf(" ★密码★");
								GoTo_XY(x+18,y+11);
								User_PrtPassword(pDate);
								Draw_Button(x+11,y+13,iFlag%2==0,LGREEN,BLUE);
								printf("确认:ENTER");
								while(Get_KeyValue()!=ENTER)
								{
									
								};
								Draw_Popup(x-2,y+3,10,RED,"        警告     ");
								Draw_Warning(x+1,y+5,RED);
								printf("  ◆★密码改变,请重新登录★◆ ");
								Draw_Button(x+11,y+8,1,RED,GREEN);
								printf(" 退出:ESC");
								color(BLUE,BLACK);
								while(Get_KeyValue()!=ESC)
								{
								
								}
								return ESC;	
							}
						}
						else
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" 哦吼~两次输入密码不一致哦^-^");
							Clear_FormIO(x,y+9,cReNewPassword);
							color(BLUE,BLACK);
						}
					}break;
				}
				GoTo_XY(x+36,y+10);
				printf("           ");
			}break;
		}
	}	
}
    


void User_RecordControl(PULink pHead,PUser pDate)
{
	      int iFlag=0;
		  PULink pNewHead=NULL;
	      My_ClearBG();
	      Pritf_Tile(45,25,"★★交易记录★★","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf("  ★★请选择你的操作类型★★");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf(" 显示所有 ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf(" 时间查询 ");
		  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
		  printf("   返回   ");
		  while(1)
		  {
			  switch(Get_KeyValue())
			  {
			  case KEY_UP:
				  {
					  if (iFlag==0)
					  {
						  iFlag=2;
					  }
					  else
					  {
						  iFlag--;
					  }
					  
				  }break;
			  case KEY_DOWN:
				  {
					  if (iFlag==2)
					  {
						  iFlag=0;
					  }
					  else
					  {
						  iFlag++;
					  }
				  }break;
			  case ENTER:
				  {
					  switch(iFlag)
					  {
					  case 0:
						  {
							  pNewHead=Select_RecordID(pHead,pDate->iID);
							  User_Record(17,7,pNewHead,pDate,Page_RecordPrint,Draw_RecordPage);
							  My_ClearBG();
						  }break;
					  case 1:
						  {
							  pNewHead=Select_RecordID(pHead,pDate->iID);
							  pNewHead=My_DateControl(17,7,pNewHead,pDate);
							  if (pNewHead==NULL)
							  {
								  
								  break;
							  }
							  color(BLUE,BLACK);
							  My_ClearBG();//清屏
							  User_Record(17,7,pNewHead,pDate,Page_RecordPrint,Draw_RecordPage);
							  My_ClearBG();
						  }break;
					  case 2:
						  {
							  return;
						  }break;
					  }
					  
				  }break;
			  case ESC:
				  {
					  
					  return;
				  }break;
			  }
			  My_ClearBG();
			  Pritf_Tile(45,25,"★★交易记录★★","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf("  ★★请选择你的操作类型★★");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf(" 显示所有 ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf(" 时间查询 ");
			  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
			  printf("   返回   ");
			  color(BLUE,BLACK);
		  }
		  
		  
}


void User_Record(int x,int y,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int))
{
	int iCount=0;
	int iPageNum=0;
	int iLastNum=0;
	int iPage=0;//页数
	int iFlag=0;//被选择的选项
	PULink pTemp=NULL;
	PULink pPriHead=pHead;//开始打印的头节点地址
	y=y-2;
    iCount=ULink_Count(pHead);
	iLastNum=iCount%6;
	if (iLastNum)
	{
		iPageNum=iCount/6;
	}
	else
	{
		iPageNum=iCount/6-1;
	}
    pPriHead=ULink_GetNode(pHead,iPage*6);
	Page(x,y);
	My_Print(x,y,pPriHead,iPage,iFlag);
	GoTo_XY(x+22,y+17);
	printf("第%d/%d页",iPage+1,iPageNum+1);
	while(1)
	{
		switch(Get_KeyValue())
		{
		case KEY_UP:
			{
				if (iPage==iPageNum&&iLastNum)
				{
					if (iFlag==0)
					{
						iFlag=iLastNum-1;
					}
					else
					{
						iFlag--;
					}
				}
				else
				{
					if (iFlag==0)
					{
						iFlag=5;
					}
					else
					{
						iFlag--;
					}
				}
				
			}break;
		case KEY_DOWN:
			{
				if (iPage==iPageNum&&iLastNum)
				{
					if (iFlag==iLastNum-1)
					{
						iFlag=0;
					}
					else
					{
						iFlag++;
					}
				}
				else
				{
					if (iFlag==5)
					{
						iFlag=0;
					}
					else
					{
						iFlag++;
					}
				}
				
			}break;
		case KEY_LEFT:
			{
				iFlag=0;
				iPage--;
				if (iPage<0)
				{
					Draw_Popup(x+6,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+9,y+5,LGREEN);
					printf("◇☆◆★已经是第一页了★◆☆◇");
					Draw_Button(x+19,y+8,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
                    iPage++;
				}
				pPriHead=ULink_GetNode(pHead,iPage*6);
			}break;
		case KEY_RIGHT:
			{	
				iFlag=0;
				iPage++;
				if (iPage>iPageNum)
				{
					Draw_Popup(x+6,y+3,10,LGREEN,"        提示     ");
					Draw_Warning(x+9,y+5,LGREEN);
					printf("◇☆◆★没有再下一页了★◆☆◇");
					Draw_Button(x+19,y+8,1,LGREEN,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
                    iPage--;
				}
				pPriHead=ULink_GetNode(pHead,iPage*6);
			}break;
		case ESC:
			{
				return;	
			}break;
		}
		
		My_Print(x,y,pPriHead,iPage,iFlag);
		GoTo_XY(x+22,y+17);
		printf("第%d/%d页",iPage+1,iPageNum+1);
	}
				
				
}



void Page_RecordPrint(int x,int y,PULink pHead,int iPage,int iFlag)
{
	int i=0;
	x=x-6;
	y=y+3;
	for (i=0;i<6;i++)
	{
		GoTo_XY(x+2,y+2*i);
		printf("      ");
		GoTo_XY(x+10,y+2*i);
		printf("          ");
		GoTo_XY(x+22,y+2*i);
		printf("            ");
		GoTo_XY(x+36,y+2*i);
		printf("            ");
		GoTo_XY(x+50,y+2*i);
		printf("      ");
		GoTo_XY(x+58,y+2*i);
		printf("        ");
	}
	for (i=0;i<6;i++)
	{
		if(pHead==NULL)
		{
			GoTo_XY(x+2,y+2*i);
			printf("      ");
			GoTo_XY(x+10,y+2*i);
			printf("          ");
			GoTo_XY(x+22,y+2*i);
			printf("            ");
			GoTo_XY(x+36,y+2*i);
			printf("            ");
			GoTo_XY(x+50,y+2*i);
			printf("      ");
			GoTo_XY(x+58,y+2*i);
			printf("        ");
		}
		else
		{
			if (i==iFlag)
			{
				color(LBLUE,BLACK);
			}
			GoTo_XY(x+2,y+2*i);
			printf("%-6d",iPage*6+i+1);
            GoTo_XY(x+10,y+2*i);
			printf("%d-%d-%d",((PRecord)(pHead->pDate))->iYear,((PRecord)(pHead->pDate))->iMonth,((PRecord)(pHead->pDate))->iDay);
			GoTo_XY(x+22,y+2*i);
            printf("%d",((PRecord)pHead->pDate)->iDealMoney);
			GoTo_XY(x+36,y+2*i);
			printf("%d",((PRecord)pHead->pDate)->iAfterMoney);
            GoTo_XY(x+50,y+2*i);
			switch(((PRecord)pHead->pDate)->iDealType)
			{
			case DEPOSIT:
				{
					printf("存款");
				}break;
			case WITHDRAW:
				{
               		printf("取款");  
				}break;
			case TURNIN:
				{
					printf("转入");	
				}break;
			case TURNOUT:
				{
					printf("转出");	
				}break;
			}
			GoTo_XY(x+58,y+2*i);
			if (((PRecord)pHead->pDate)->iSourseID==0)
			{
             printf("   ATM机  ");
			}
			else
			{
             printf("%d",((PRecord)pHead->pDate)->iSourseID);
			}
			
			pHead=pHead->pNext;
			if (i==iFlag)
			{
				color(BLUE,BLACK);
			}
		}
		
	}
}


PULink Select_RecordID(PULink pHead,int iAimID)
{
	PULink pTemp=NULL;
	PRecord pDate=NULL;
	if(!(pTemp=ULink_Init(NULL)))
	{
		return NULL;
	}
	pHead=pHead->pNext;
	pDate=RLink_Init();
	while(pHead!=NULL)
	{
		if (((PRecord)pHead->pDate)->iAimID==iAimID)
		{
			memcpy(pDate,pHead->pDate,sizeof(Record));
			ULink_AddNode(pTemp,pDate);
			pDate=RLink_Init();
		}
		pHead=pHead->pNext;
	}
	free(pDate);
	return pTemp;
}

int My_DateIO(int x,int y,char * cTitle,int iFlag,int ForthDate)
{
	int iDateNum=0;
	int iTemp=0;
	char cYear[5]={'\0'};
	char cMonth[3]={'\0'};
	char cDay[3]={'\0'};
	
	while(1)
	{
		
		while(1)
		{
			My_ClearBG();
			Pritf_Tile(45,25,"★★时间查询★★","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
			if (iFlag==1)
			{
				GoTo_XY(35,21);
				printf("起始日期:%d年%d月%d日",ForthDate/10000,(ForthDate%10000)/100,ForthDate%100);
			}
			Draw_Button(36,y-3,1,BLUE,BLUE);
            printf("%s",cTitle);
			Draw_FormIO(x,y+1);
			printf(" ★年份★");
			Draw_FormIO(x,y+4);
			printf(" ★月份★");
			Draw_FormIO(x,y+7);
         	printf(" ★日期★");
			Clear_FormIO(x,y+1,cYear);
			Clear_FormIO(x,y+4,cMonth);
		    Clear_FormIO(x,y+7,cDay);
			iTemp=FormIO_Control(x,y+1,"",cYear,4,NUMBER,PLAINTEXT);
         	if (iTemp==ESC)
         	{
				return ESC;
         	}
			else if(iTemp==ENTER)
			{
				if (strlen(cYear)!=4)
				{
					Draw_Popup(23,y+1,10,RED,"      错误操作   ");
					Draw_Warning(26,y+3,RED);
					printf("   ◇☆年份信息输入错误☆◇");
					Draw_Button(36,y+6,1,RED,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
				}
				else
				{
				break;
				}
			}
         		
		}
		while(1)
		{
			iTemp=FormIO_Control(x,y+4,"",cMonth,2,NUMBER,PLAINTEXT);
			if (iTemp==ESC)
			{
				return ESC;
			}
			else if(iTemp=ENTER)
			{
				if (strlen(cMonth)==0)
				{
					Draw_Popup(23,y+1,10,RED,"      错误操作   ");
					Draw_Warning(26,y+3,RED);
					printf("   ◇☆月份信息不能为空☆◇");
					Draw_Button(36,y+6,1,RED,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					My_ClearBG();
					Pritf_Tile(45,25,"★★时间查询★★","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
					Draw_Button(36,y-3,1,BLUE,BLUE);
                    printf("%s",cTitle);
					Draw_FormIO(x,y+1);
					printf(" ★年份★");
					GoTo_XY(x+18,y+2);
					printf("%s",cYear);
					Draw_FormIO(x,y+4);
					printf(" ★月份★");
					Draw_FormIO(x,y+7);
					printf(" ★日期★");
					Clear_FormIO(x,y+4,cMonth);
				}
				else
				{
					break;
				}
			}
			
		}
		while(1)
		{
			iTemp=FormIO_Control(x,y+7,"",cDay,2,NUMBER,PLAINTEXT);
			if (iTemp==ESC)
			{
				return ESC;
			}
			else if(iTemp=ENTER)
			{
				if (strlen(cDay)==0)
				{
					Draw_Popup(23,y+1,10,RED,"      错误操作   ");
					Draw_Warning(26,y+3,RED);
					printf("   ◇☆日期信息不能为空☆◇");
					Draw_Button(36,y+6,1,RED,GREEN);
					printf("确定:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					My_ClearBG();
					Pritf_Tile(45,25,"★★时间查询★★","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
					Draw_Button(36,y-3,1,BLUE,BLUE);
                    printf("%s",cTitle);
					Draw_FormIO(x,y+1);
					printf(" ★年份★");
					GoTo_XY(x+18,y+2);
					printf("%s",cYear);
					Draw_FormIO(x,y+4);
					printf(" ★月份★");
					GoTo_XY(x+18,y+5);
					printf("%s",cMonth);
					Draw_FormIO(x,y+7);
					printf(" ★日期★");
		            Clear_FormIO(x,y+7,cDay);
				}
				else
				{
					break;
				}
			}
			
		}
		iDateNum=Date_Effective(cYear,cMonth,cDay);
		if (iDateNum)//判断日期输入格式是否正确
		{
			return iDateNum;
		}
		else if (iDateNum==0)
		{
			Draw_Popup(23,y+3,10,RED,"      错误操作   ");
			Draw_Warning(26,y+5,RED);
			printf("   ◇☆输入的日期不存在☆◇");
			Draw_Button(36,y+8,1,RED,GREEN);
			printf("确定:ENTER");
			color(BLUE,BLACK);
			while(Get_KeyValue()!=ENTER)
			{
				
			}
			
		}
		
	}
	
}

PULink My_DateControl(int x,int y,PULink pHead,PUser pDate)
{
	int ForthDate=0;
	int BackDate=0;
	int NowDate=0;
	int iTemp=0;
	int iFlag=0;
	int UserRefisterTimeNum=(((pDate->iYear)*10000)+((pDate->iMonth)*100)+((pDate->iDay)*1));
	time_t Time;
    TIME *pT;	
	time(&Time);
	Pritf_Tile(45,25,"★★时间查询★★","确认:ENTER\t\t      按←↑↓→选择","退出:  ESC  ");
	pT=(TIME*)localtime(&Time);
	NowDate=(((pT->iYear+1900)*10000)+((pT->iMon+1)*100)+((pT->iMDay)*1));
	while(1)
	{
		while(1)
		{
			iFlag=0;
			ForthDate=My_DateIO(26,y," 起始日期",iFlag,ForthDate);//确定起始日期在正常范围内
			if (ForthDate==ESC)
			{
				return NULL;
			}
			else if (ForthDate>NowDate)
			{
				Draw_Popup(23,y+1,10,RED,"      错误操作   ");
				Draw_Warning(26,y+3,RED);
				printf("◇☆起始日期不能是未来日期☆◇");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("确定:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}
			}
			else if(ForthDate<UserRefisterTimeNum)
			{
				Draw_Popup(23,y+1,10,RED,"      错误操作   ");
				Draw_Warning(26,y+3,RED);
				printf(" ◇☆起始日期早于注册时间☆◇");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("确定:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}
			}
			else
			{
				break;
			}
			
		}
		while(1)
		{
			iFlag=1;
			
			BackDate=My_DateIO(26,y," 终止日期",iFlag,ForthDate);//确定终止日期在正常范围内
			if (BackDate==ESC)
			{
				return NULL;
			}
			else if (BackDate>NowDate)
			{
				Draw_Popup(23,y+1,10,RED,"      错误操作   ");
				Draw_Warning(26,y+3,RED);
				printf("◇☆终止日期不能是未来时间☆◇");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("确定:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}
			}
			else if(BackDate<ForthDate)
			{
				Draw_Popup(23,y+1,10,RED,"      错误操作   ");
				Draw_Warning(26,y+3,RED);
				printf(" ◇☆终止日期早于起始时间☆◇");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("确定:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}

			}
			else
			{
				break;
			}
			
		}
		iTemp=Date_Comparison(ForthDate,BackDate);
			if (iTemp==100)
			{
				Draw_Popup(23,y+3,10,RED,"      错误操作   ");
				Draw_Warning(26,y+5,RED);
				printf("  ◇☆时间跨度超过一个月☆◇");
				Draw_Button(36,y+8,1,RED,GREEN);
				printf("确定:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}
			}
			else if (iTemp==1)
			{
				break;
			}   
	}
	return Select_RecordTIME(pHead,ForthDate,BackDate);
	
}

PULink Select_RecordTIME(PULink pHead,int ForthDate,int BackDate)
{
	PULink pTemp=NULL;
	PRecord pDate=NULL;
	if(!(pTemp=ULink_Init(NULL)))
	{
		return NULL;
	}
	pHead=pHead->pNext;
	pDate=RLink_Init();
	while(pHead!=NULL)
	{
		if ((((PRecord)pHead->pDate)->iDateNum>=ForthDate)&&(((PRecord)pHead->pDate)->iDateNum<=BackDate))
		{
			memcpy(pDate,pHead->pDate,sizeof(Record));
			ULink_AddNode(pTemp,pDate);
			pDate=RLink_Init();
		}
		pHead=pHead->pNext;
	}
	free(pDate);
	return pTemp;
}


