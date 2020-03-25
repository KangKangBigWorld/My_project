#include "My_Control.h"

void MainWIN_Control()
{
	FILE* fp=NULL;//�����û��ļ���ָ�����
	FILE* Rfp=NULL;//������¼�ļ���ָ�����
	FILE** pFp=&fp;//��������û���¼�ļ���ָ�����
	FILE** pRFp=&Rfp;//������ż�¼��¼�ļ���ָ�����
	int iFlag=0;
	PULink pHead=NULL;//�����û�ͨ�������׵�ַ
	PULink pRHead=NULL;//������¼ͨ�������׵�ַ
    char* Name_Date_User="User.txt";//�û����ļ����ַ�����ָ�����
	char* Name_Date_Record="Record.txt";//��¼���ļ����ַ�����ָ�����
	Draw_Main();//����������ͼ��
	Draw_Background(45,25);//�汳����
	pHead=ULink_Init(User_Init());//��ʼ���û�ͨ������
	pRHead=ULink_Init(RLink_Init());//��ʼ����¼ͨ������
	User_SetAll(((PUser)pHead->pDate),19050001,SUPERADMIN,ACTIVE,"admin","123456",0);//��ʼ����������Ա����ͷ���
    fp=File_Open(Name_Date_User);//���û��ļ�
	Rfp=File_Open(Name_Date_Record);//�򿪼�¼�ļ�
    pHead->pNext=(File_Read(fp,sizeof(User)))->pNext;//��ȡ�û��ļ�
	pRHead->pNext=(File_Read(Rfp,sizeof(Record)))->pNext;//��ȡ��¼�ļ�
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
						Register_Control(25,5,pHead,pFp,Name_Date_User,USER);//ע�Ṧ��
					}break;
				case 1:
					{
						
					}break;
				case 2:
					{
						Login_Control(25,5,pHead,pFp,Name_Date_User,pRHead,pRFp,Name_Date_Record);//��¼����
						My_ClearBG();//����
					}break;
				case 3:
					{
						SignOut_Control();//�˳�
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
	char sAccount[12]={'\0'};//�˺�����
	char sPassword[8]={'\0'};//��������
	char sRePassword[8]={'\0'};//�ٴ���������
	PULink pLoginUser=NULL;
	PUser pDate=NULL;
	int ifOver=0;
	int iFlag=0;//�ж�ѡ���ı�־λ
	// 	int iFlagAccount=0;//�ж��˺ŵı�־λ
	// 	int iFlagPassword=0;//�ж�����ı�־λ
	// 	int iFlagRePassword=0;//�ж��˺ŵı�־λ
	My_ClearBG();
	GoTo_XY(41,1);
	printf("����¼��");
	Draw_Popup(x-2,y-2,20,LGREEN," ");
	Draw_Warning(x+1,y,LGREEN);
	printf(" ��! ��ѡ���˺Ż������¼Ŷ^-^");
	Draw_Button(x+11,y+5,iFlag%2==0,LBLUE,BLUE);
	printf("   �˺�   ");
	Draw_Button(x+11,y+10,iFlag%2==1,LBLUE,BLUE);
	printf("  �û���  ");
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
						printf(" ��! ע����Χ�����Ƿ�ȫŶ^-^");
						Draw_FormIO(x,y+3);
						printf("  �˺�");
						Draw_FormIO(x,y+6);
						printf("  ����");
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
												printf(" С׿������û����д�˺�Ӵ ^-^");
												color(BLUE,BLACK);
											}
											else if(strlen(sAccount)<8)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("С׿��������˺��ǰ�λ��ѽ^-^");
												}
												else
												{
													printf("���������˺��ǲ��ǰ�λ����^-^");
												}
												Clear_FormIO(x,y+6,sAccount);
												color(BLUE,BLACK);
											}
											else if(!(ULink_Cmp(pHead,sAccount,User_IDcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" ��Ǹ! С׿û���ҵ����˺�*-* ");
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
													printf(" ����ô��,û������ɲ���Ŷ^-^");
												}
												else
												{
													printf(" ��д�´���,ֻΪ��д������^-^");
												}
												color(BLUE,BLACK);
											}
											else if(strlen(sPassword)<6)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("������λ���ֿɲ���������Ŷ^-^");
												}
												else
												{
													printf(" ���벻����λ,�����ٻ�С׿^-^");
												}
												Clear_FormIO(x,y+6,sPassword);
												color(BLUE,BLACK);
											}
											else if (strlen(sAccount)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" С׿������û����д�˺�Ӵ ^-^");
												color(BLUE,BLACK);
											}
											else if(strlen(sAccount)<8)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("С׿��������˺��ǰ�λ��ѽ^-^");
												}
												else
												{
													printf("����ϸ�������ǲ��ǰ�λ����^-^");
												}
												Clear_FormIO(x,y+6,sAccount);
												color(BLUE,BLACK);
											}
											else if(!(pLoginUser=ULink_Cmp(pHead,sAccount,User_IDcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" ��Ǹ! С׿û���ҵ����˺�*-* ");
												Clear_FormIO(x,y+3,sAccount);
												color(BLUE,BLACK);
											}
											else if(User_Passwordcmp((pDate=(PUser)pLoginUser->pDate),sPassword))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" ��¼�ɹ�!��ENTER�ٻ�С׿^-^ ");
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
												printf(" ���! ������������д���*-* ");
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
						printf(" ��! ע����Χ�����Ƿ�ȫŶ^-^");
						Draw_FormIO(x,y+3);
						printf(" �û���");
						Draw_FormIO(x,y+6);
						printf("  ����");
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
												printf("С׿������û����д�û���Ӵ^-^");
												color(BLUE,BLACK);
											}
											else if(!(ULink_Cmp(pHead,sAccount,User_Accountcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" ��Ǹ! С׿û���ҵ����û�*-* ");
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
													printf(" ����ô��,û������ɲ���Ŷ^-^");
												}
												else
												{
													printf(" ��д�´���,ֻΪ��д������^-^");
												}
												color(BLUE,BLACK);
											}
											else if(strlen(sPassword)<6)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												if (rand()%3)
												{
													printf("������λ���ֿɲ���������Ŷ^-^");
												}
												else
												{
													printf(" ���벻����λ,�����ٻ�С׿^-^");
												}
												Clear_FormIO(x,y+6,sPassword);
												color(BLUE,BLACK);
											}
											else if (strlen(sAccount)==0)
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf("С׿������û����д�û���Ӵ^-^");
												color(BLUE,BLACK);
											}
											else if(!(pLoginUser=ULink_Cmp(pHead,sAccount,User_Accountcmp)))
											{
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" ��Ǹ! С׿û���ҵ����û�*-* ");
												Clear_FormIO(x,y+3,sAccount);
												color(BLUE,BLACK);
											}
											else if(User_Passwordcmp((pDate=(PUser)pLoginUser->pDate),sPassword))
											{
												
												Draw_Warning(x+1,y+12,LGREEN);
												printf(" ��¼�ɹ�!��ENTER�ٻ�С׿^-^ ");
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
												printf(" ���! ������������д���*-* ");
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
		printf("   �˺�   ");
		Draw_Button(x+11,y+10,iFlag%2==1,LBLUE,BLUE);
		printf("  �û���  ");
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
	x+=14;//������ƫ��
	y+=1;//�������ƫ��
	show_cursor();//��ʾ���
	GoTo_XY(x+22,y);
	printf("%s",pTips);
	switch(My_ConIO(cStr,iMaxLen,iPutType,isPlaintext,x+4,y))
	{
	case KEY_UP:
		{
			hide_cursor();//���ع��
			return KEY_UP;
		}break;
	case KEY_DOWN:
		{
			hide_cursor();//���ع��
			return KEY_DOWN;
		}break;
	case ENTER:
		{
			hide_cursor();//���ع��
			return ENTER;	
		}break;
	case ESC:
		{
			hide_cursor();//���ع��
			return ESC;
		}break;
	}		//������ʮ��
	return 0;
}


void Register_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,int iIDentity)
{
	
	char sAccount[12]={'\0'};
	char sPassword[8]={'\0'};
	char sRePassword[8]={'\0'};
	PUser pDate=NULL;
	int ifOver=0;
	int iFlag=0;//�ж�ѡ���ı�־λ
	PULink pLast=ULink_GetNode(pHead,ULink_Count(pHead)-1);//�ҵ�Ϊ�ڵ㸳ֵ��pLast
	int iNewId=User_GetID((PUser)(pLast->pDate))+(rand()%100)+1;//Ϊ�ڵ�id+1
	My_ClearBG();
	GoTo_XY(41,1);
	printf("��ע���");
	Draw_FormIO(x,y);
	printf("   �˺�");
	GoTo_XY(x+18,y+1);
	printf("%d",iNewId);
	Draw_FormIO(x,y+3);
	printf(" Ӣ������");
	Draw_FormIO(x,y+6);
	printf("  ����");
	Draw_FormIO(x,y+9);
	printf(" ȷ������");
	while(1)
	{     
		switch (iFlag)
		{
		case 0:
			{
				switch(FormIO_Control(x,y+3,"�˺�ֻ������",sAccount,8,LETTER,PLAINTEXT))
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
							printf("��ſ�ѽ~С׿��֪����������^-^");
							color(BLUE,BLACK);
						}
						else if(ULink_Strmp(pHead,sAccount,User_Accountcmp))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("��ѽ!��������Ѿ���ע����*-*");
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
				
				switch(FormIO_Control(x,y+6,"ʹ����λ����",sPassword,6,NUMBER,DARKTEXT))
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
								printf(" ����ô��,û������ɲ���Ŷ^-^");
							}
							else
							{
								printf(" ��д�´���,ֻΪ��д������^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(sPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" ���벻����λ,��������ȫŶ^-^");
							}
							else
							{
								printf(" ����С����λ,����������Ŷ^-^");
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
				
				switch(FormIO_Control(x,y+9,"ʹ����λ����",sRePassword,6,NUMBER,DARKTEXT))
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
							printf(" ����ô��,û������ɲ���Ŷ^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(sRePassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" ���벻����λ,��������ȫŶ^-^");
							}
							else 
							{
								printf(" ����С����λ,����������Ŷ^-^");
							}
							Clear_FormIO(x,y+9,sRePassword);
							color(BLUE,BLACK);
						}
						else if (!(strcmp(sPassword,sRePassword)))
						{
							if (strlen(sAccount)==0)
							{
								Draw_Warning(x,y+12,LGREEN);
								printf("��ſ�ѽ~С׿��֪����������^-^");
								color(BLUE,BLACK);
							}
							else if(ULink_Strmp(pHead,sAccount,User_Accountcmp))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" ��ѽ!��������Ѿ���ע����*-*");
								Clear_FormIO(x,y+3,sAccount);
								color(BLUE,BLACK);
							}
							else
							{
								iFlag=0;
								pDate=User_Init();
								User_SetAll(pDate,iNewId,iIDentity,ACTIVE,sAccount,sPassword,0);
								ULink_AddNode(pHead,pDate);
								Draw_Popup(x-2,y-2,20,LGREEN,"���μ������û���ϢŶ~");
								Draw_FormIO(x,y+1);
								printf(" �˻�����");
								GoTo_XY(x+18,y+2);
								User_PrtIdentity(((PUser)pLast->pNext->pDate));
								Draw_FormIO(x,y+4);
								printf(" ���˺š�");
								GoTo_XY(x+18,y+5);
								User_PrtID(((PUser)pLast->pNext->pDate));
								Draw_FormIO(x,y+7);
								printf(" Ӣ������");
								GoTo_XY(x+18,y+8);
								User_PrtAccount(((PUser)pLast->pNext->pDate));
								Draw_FormIO(x,y+10);
								printf(" �������");
								GoTo_XY(x+18,y+11);
								User_PrtPassword(((PUser)pLast->pNext->pDate));
								Draw_Button(x+2,y+14,iFlag%2==0,LGREEN,BLUE);
								printf("ȷ��:ENTER");
								Draw_Button(x+20,y+14,iFlag%2==1,LGREEN,BLUE);
								printf(" �޸�:ESC ");
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
										printf("��ע���");
										Draw_FormIO(x,y);
										printf("   �˺�");
										GoTo_XY(x+18,y+1);
										printf("%d",iNewId);
										Draw_FormIO(x,y+3);
										printf(" Ӣ������");
										GoTo_XY(x+18,y+4);
										printf("%s",sAccount);
										Draw_FormIO(x,y+6);
										printf("  ����");
										GoTo_XY(x+18,y+7);
										printf("%s",sPassword);
										Draw_FormIO(x,y+9);
										printf(" ȷ������");
										GoTo_XY(x+18,y+10);
										printf("%s",sRePassword);
										Draw_Warning(x,y+12,LGREEN);
										printf("��! �Ѿ�Ϊ����ʾ����,���޸�^-^");
										iFlag=0;
										color(BLUE,BLACK);
									}
									else
									{
										Draw_Button(x+2,y+14,iFlag%2==0,LGREEN,BLUE);
										printf("ȷ��:ENTER");
										Draw_Button(x+20,y+14,iFlag%2==1,LGREEN,BLUE);
										printf(" �޸�:ESC ");
										color(BLUE,BLACK);
									}	
								}
							}
						}
						else
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" Ŷ��~�����������벻һ��Ŷ^-^");
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
	My_ClearBG(); //������Ļ
    Draw_UserWin();//�û�����
	Draw_User_Button(iFlag);//�û���ť
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
				}//ע���û�
				My_ClearBG(); //������Ļ
                Draw_UserWin();//����Ա����
			}break;
		case ENTER:
			{
				switch(iFlag)
				{
				case 0://����
					{
						My_DepositControl(20,6,pHead,pFp,Name_Date_User,pDate,pRHead,pRFp,Name_Date_Record);
					}break;
				case 1://ȡ���
					{
						My_WithdrawControl(20,6,pHead,pFp,Name_Date_User,pDate,pRHead,pRFp,Name_Date_Record);	
					}break;
				case 2://ת�˹���
					{
						My_TransferControl(20,6,pHead,pFp,Name_Date_User,pDate,pRHead,pRFp,Name_Date_Record);
					}break;
				case 3://ע������
					{
						if (Control_Cancell(21,4))
						{
							return;
						}
					}break;
				case 4://����ѯ
					{
						My_BalanceQueryControl(20,6,pDate);
					}break;
				case 5://���׼�¼
					{
						User_RecordControl(pRHead,pDate);
					}break;
				case 6://�޸�����
					{
						if ((My_ChangePasswordControl(25,6,pHead,pDate,pFp,Name_Date_User))==ESC)
						{
							return;
						}
						
					}break;
				case 7://�˳�
					{
						SignOut_Control();
						Draw_UserWin();
						
					}break;	
				}
				My_ClearBG(); //������Ļ
                Draw_UserWin();//����Ա����
				
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
	My_ClearBG(); //������Ļ
    Draw_AdminWin();//����Ա����
	Draw_Admin_Button(iFlag);//�û���ť
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
				My_ClearBG(); //������Ļ
                Draw_AdminWin();//����Ա����
				//ע���û�
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
				My_ClearBG(); //������Ļ
				Draw_AdminWin();//����Ա����
				
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
	printf("�����Ա��ѯ�����");
	Draw_Button(36,6,iFlag%4==0,LBLUE,BLUE);
	printf(" ȫ����ѯ ");
	Draw_Button(36,9,iFlag%4==1,LBLUE,BLUE);
	printf(" �����ѯ ");
	Draw_Button(36,12,iFlag%4==2,LBLUE,BLUE);
	printf(" ������ѯ ");
	Draw_Button(36,15,iFlag%4==3,LBLUE,BLUE);
	printf("   ����   ");
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
						printf("��ȫ����ѯ��");
						Page_Turning(20,4,pHead,Page_Print,Draw_Page);
						My_ClearBG();
						GoTo_XY(36,1);
						printf("�����Ա��ѯ�����");
					}break;
				case 1:
					{
						iFlag=0;
						My_ClearBG();
						GoTo_XY(36,1);
						printf("�����Ա��ѯ�����");
						Draw_Button(36,6,iFlag%3==0,LBLUE,BLUE);
						printf("  ����Ա  ");
						Draw_Button(36,10,iFlag%3==1,LBLUE,BLUE);
						printf(" ��ͨ�û� ");
						Draw_Button(36,14,iFlag%3==2,LBLUE,BLUE);
						printf("   ����   ");
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
											printf("�����Ա��ѯ��");
											Page_Turning(20,4,(pTemp=Select_Identity(pHead,1)),Page_Print,Draw_Page);
											ULink_Free(pTemp,1);
											My_ClearBG();
											GoTo_XY(36,1);
											printf("�����Ա��ѯ�����");
										}break;
									case 1:
										{
											My_ClearBG();
											GoTo_XY(39,1);
											printf("���û���ѯ��  ");
											Page_Turning(20,4,(pTemp=Select_Identity(pHead,0)),Page_Print,Draw_Page);
											ULink_Free(pTemp,1);
											My_ClearBG();
											GoTo_XY(36,1);
											printf("�����Ա��ѯ�����"); 
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
							printf("  ����Ա  ");
							Draw_Button(36,10,iFlag%3==1,LBLUE,BLUE);
							printf(" ��ͨ�û� ");
							Draw_Button(36,14,iFlag%3==2,LBLUE,BLUE);
							printf("   ����   ");
						}
					}break;
				case 2:
					{
						Fuzzy_Search(pHead);
						My_ClearBG();
						Pritf_Tile(45,25,"�����Ա��ѯ�����","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
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
							printf(" ȫ����ѯ ");
							Draw_Button(36,9,iFlag%4==1,LBLUE,BLUE);
							printf(" �����ѯ ");
							Draw_Button(36,12,iFlag%4==2,LBLUE,BLUE);
							printf(" ������ѯ ");
							Draw_Button(36,15,iFlag%4==3,LBLUE,BLUE);
							printf("   ����   ");
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
				printf(" ��ͨ�û� ");
			}
			else
			{
				printf("  ����Ա  ");
			}
			GoTo_XY(x+34,y+2*i);
			printf("%-10s",((PUser)pHead->pDate)->cAccount);
			GoTo_XY(x+46,y+2*i);
			printf("%8d",((PUser)pHead->pDate)->iBalance);
			GoTo_XY(x+56,y+2*i);
			if (((PUser)pHead->pDate)->iCondition=ACTIVE)
			{
				printf("��Ծ");
			}
			else
			{
				printf("����");
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
	int iLastNum=0;//��ҳ��
	int iPage=0;//ҳ��
	int iFlag=0;//��ѡ���ѡ��
	PULink pTemp=NULL;
	PULink pPriHead=pHead;//��ʼ��ӡ��ͷ�ڵ��ַ
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
	printf("��%d/%dҳ",iPage+1,iPageNum+1);
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
					Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("�������Ѿ��ǵ�һҳ�ˡ�����");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
					Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("������û������һҳ�ˡ�����");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
		printf("��%d/%dҳ",iPage+1,iPageNum+1);
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
	printf("��ģ��/��ȷ ��ѯ��  ");
	Pritf_Tile(45,25,"��ģ��/��ȷ ��ѯ��","ȷ��:ENTER  �����ѡ���������             ��ѯ�ɹ���ESC���ٴβ�ѯ","  �˳�:ESC");
	Draw_FormIO(25,3);
	printf("��ѯ�û���");
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
					Draw_Popup(23,9,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(26,11,LGREEN);
					printf("����ﱧǸ,�˺Ų���Ϊ��!�����");
					Draw_Button(36,14,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					Draw_Page(20,6);		
				}
				pTemp=Select_UserName(pHead,cAccount);
				if (!(ULink_Count(pTemp)))
				{
					Draw_Popup(23,9,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(26,11,LGREEN);
					printf("�����ﱧǸ,���޴���!������");
					Draw_Button(36,14,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
	printf("�����Ա��ѯ�����");	
}

void Admin_Register(PULink pHead,FILE** pFp,char* Name_Date_User)
{
	int iFlag=0;
	My_ClearBG();
	Pritf_Tile(45,25,"���û�ע������","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf(" �����ѡ��ע���û������͡��");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf("  ����Ա  ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf(" ��ͨ�û� ");
		  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
		  printf("   ����   ");
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
			  Pritf_Tile(45,25,"���û�ע������","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf(" �����ѡ��ע���û������͡��");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf("  ����Ա  ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf(" ��ͨ�û� ");
			  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
			  printf("   ����   ");
		  }
		  
		  
		  
}

void User_Delect(PULink pHead,PUser pDate,FILE** pFp,char* pFilename)
{
	int iFlag=0;
	My_ClearBG();
	Pritf_Tile(45,25,"���û�ɾ�������","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf("  �����ѡ����Ĳ������͡��");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf(" ��ʾ���� ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf("   ����   ");
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
			  Pritf_Tile(45,25,"���û�ע������","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf("  �����ѡ����Ĳ������͡��");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf(" ��ʾ���� ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf("   ����   ");
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
	int iPage=0;//ҳ��
	int iFlag=0;//��ѡ���ѡ��
	int iMyFlag=0;
	PULink pTemp=NULL;
	PULink pPriHead=pHead;//��ʼ��ӡ��ͷ�ڵ��ַ
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
	printf("��%d/%dҳ",iPage+1,iPageNum+1);
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
					Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("�������Ѿ��ǵ�һҳ�ˡ�����");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
					Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("������û������һҳ�ˡ�����");
					Draw_Button(x+16,y+8,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
					Draw_Popup(x+3,y+3,10,RED,"      �Ƿ�����   ");
					Draw_Warning(x+6,y+5,RED);
					printf(" �������Ȩ�޲���������");
					Draw_Button(x+16,y+8,1,RED,GREEN);
					printf("ȷ��:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
				}
				else if((temp2!=0))
				{
					Draw_Popup(x+3,y+3,10,RED,"      �Ƿ�����   ");
					Draw_Warning(x+6,y+5,RED);
					printf(" �������˻������������");
					Draw_Button(x+16,y+8,1,RED,GREEN);
					printf("ȷ��:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
                    Page(x,y);
				}
				else
				{
					iMyFlag=0;
					Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+6,y+5,LGREEN);
					printf("��������ȷ�����Ĳ���������");
					Draw_Button(x+6,y+8,iMyFlag%2==0,RED,LGREEN);
					printf("ȷ��:ENTER");
					Draw_Button(x+26,y+8,iMyFlag%2==1,RED,LGREEN);
					printf(" ȡ��:ESC ");
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
										Draw_Popup(x+3,y+3,10,LGREEN,"        ����     ");
										Draw_Warning(x+6,y+5,LGREEN);
										printf(" �������ɾ���ɹ��������");
										Draw_Button(x+16,y+8,1,LGREEN,GREEN);
										printf("ȷ��:ENTER");
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
						printf("ȷ��:ENTER");
						Draw_Button(x+26,y+8,iMyFlag%2==1,RED,LGREEN);
						printf(" ȡ��:ESC ");		
						
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
		printf("��%d/%dҳ",iPage+1,iPageNum+1);
	}
	
}

void User_ChangePassword(PULink pHead,PUser pDate,FILE** pFp,char* pFilename)
{
	int iFlag=0;
	My_ClearBG();
	Pritf_Tile(45,25,"���޸���������","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf("  �����ѡ����Ĳ������͡��");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf(" ��ʾ���� ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf("   ����   ");
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
			  Pritf_Tile(45,25,"���޸���������","ȷ��:ENTER\t\t      �������ѡ��","�˳�:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf("  �����ѡ����Ĳ������͡��");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf(" ��ʾ���� ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf("   ����   ");
		  }
		  
		  
}

int My_ChangePassword(int x,int y,PUser pDate)
{
	char cNewPassword[8]={'\0'};
	char cReNewPassword[8]={'\0'};
	int iFlag=0;
    My_ClearBG();
	GoTo_XY(39,1);
	printf("���޸������");
    Draw_FormIO(x,y);
	printf("   �˺�");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf(" Ӣ������");
	GoTo_XY(x+18,y+4);
	printf("%s",pDate->cAccount);
    Draw_FormIO(x,y+6);
	printf("  ������");
	Draw_FormIO(x,y+9);
	printf(" ȷ������");
	while(1)
	{
		switch (iFlag)
		{			
		case 0:
			{
				
				switch(FormIO_Control(x,y+6,"ʹ����λ����",cNewPassword,6,NUMBER,DARKTEXT))
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
								printf(" ����ô��,û������ɲ���Ŷ^-^");
							}
							else
							{
								printf(" ��д�´���,ֻΪ��д������^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(cNewPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" ���벻����λ,��������ȫŶ^-^");
							}
							else
							{
								printf(" ����С����λ,����������Ŷ^-^");
							}
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						else if(!(strcmp(cNewPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" �����벻���������һ��Ŷ!^-^");
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
				
				switch(FormIO_Control(x,y+9,"ʹ����λ����",cReNewPassword,6,NUMBER,DARKTEXT))
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
							printf(" ����ô��,û������ɲ���Ŷ^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(cReNewPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" ���벻����λ,��������ȫŶ^-^");
							}
							else 
							{
								printf(" ����С����λ,����������Ŷ^-^");
							}
							Clear_FormIO(x,y+9,cReNewPassword);
							color(BLUE,BLACK);
						}
						else if (!(strcmp(cReNewPassword,cNewPassword)))
						{
							if (strlen(cNewPassword)==0)
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" ����ô��,û������ɲ���Ŷ^-^");
								color(BLUE,BLACK);
							}
							else if(!(strcmp(pDate->cPasswod,cNewPassword)))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" �����벻���������һ��Ŷ!^-^");
								Clear_FormIO(x,y+6,cNewPassword);
								color(BLUE,BLACK);
							}
							else
							{
								iFlag=0;
								memcpy(pDate->cPasswod,cNewPassword,8);
								Draw_Popup(x-2,y-2,19,LGREEN,"���μ������û���ϢŶ~");
								Draw_FormIO(x,y+1);
								printf(" �˻�����");
								GoTo_XY(x+18,y+2);
								User_PrtIdentity(pDate);
								Draw_FormIO(x,y+4);
								printf(" ���˺š�");
								GoTo_XY(x+18,y+5);
								User_PrtID(pDate);
								Draw_FormIO(x,y+7);
								printf(" Ӣ������");
								GoTo_XY(x+18,y+8);
								User_PrtAccount(pDate);
								Draw_FormIO(x,y+10);
								printf(" �������");
								GoTo_XY(x+18,y+11);
								User_PrtPassword(pDate);
								Draw_Button(x+11,y+13,iFlag%2==0,LGREEN,BLUE);
								printf("ȷ��:ENTER");
								while(Get_KeyValue()!=ENTER)
								{
									
								};
								return 1;
							}
						}
						else
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" Ŷ��~�����������벻һ��Ŷ^-^");
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
		int iPage=0;//ҳ��
		int iFlag=0;//��ѡ���ѡ��
		PULink pTemp=NULL;
		PULink pPriHead=pHead;//��ʼ��ӡ��ͷ�ڵ��ַ
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
		printf("��%d/%dҳ",iPage+1,iPageNum+1);
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
						Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf("�������Ѿ��ǵ�һҳ�ˡ�����");
						Draw_Button(x+16,y+8,1,LGREEN,GREEN);
						printf("ȷ��:ENTER");
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
						Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf("������û������һҳ�ˡ�����");
						Draw_Button(x+16,y+8,1,LGREEN,GREEN);
						printf("ȷ��:ENTER");
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
						Draw_Popup(x+3,y+3,10,RED,"      �Ƿ�����   ");
						Draw_Warning(x+6,y+5,RED);
						printf(" �������Ȩ�޲���������");
						Draw_Button(x+16,y+8,1,RED,GREEN);
						printf("ȷ��:ENTER");
						color(BLUE,BLACK);
						while(Get_KeyValue()!=ENTER)
						{
							
						}
                        Page(x,y);
					}
					else
					{
						iFlag=0;
						Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf("��������ȷ�����Ĳ���������");
						Draw_Button(x+6,y+8,iFlag%2==0,RED,LGREEN);
						printf("ȷ��:ENTER");
						Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
						printf(" ȡ��:ESC ");
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
												Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
												Draw_Warning(x+6,y+5,LGREEN);
												printf(" ��������޸ĳɹ��������");
												Draw_Button(x+16,y+8,1,LGREEN,GREEN);
											}
											else
											{
												Draw_Popup(x+3,y+3,10,LGREEN,"        ��ʾ     ");
												Draw_Warning(x+6,y+5,LGREEN);
												printf(" ��������޸�ʧ�ܡ������");
												Draw_Button(x+16,y+8,1,LGREEN,GREEN);
											}
											
											printf("ȷ��:ENTER");
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
							printf("ȷ��:ENTER");
							Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
							printf(" ȡ��:ESC ");		
							
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
		printf("��%d/%dҳ",iPage+1,iPageNum+1);
	}	
}

int Control_Cancell(int x,int y)
{
	int iFlag=0;
	Draw_Popup(x+3,y+3,10,LGREEN,"        ע��     ");
	Draw_Warning(x+6,y+5,LGREEN);
	printf("�������Ƿ�ע���û�? ������");
	Draw_Button(x+6,y+8,iFlag%2==0,RED,LGREEN);
	printf("ȷ��:ENTER");
	Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
	printf(" ȡ��:ESC ");
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
						Draw_Popup(x+3,y+3,10,LGREEN,"        ע��     ");
						Draw_Warning(x+6,y+5,LGREEN);
						printf(" �������ע���ɹ��������");
						Draw_Button(x+16,y+8,1,LGREEN,GREEN);
						printf("ȷ��:ENTER");
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
		printf("ȷ��:ENTER");
		Draw_Button(x+26,y+8,iFlag%2==1,RED,LGREEN);
		printf(" ȡ��:ESC ");		
		
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
	printf("���������");
    Draw_FormIO(x,y);
	printf("   �˺�");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf(" Ӣ������");
	GoTo_XY(x+18,y+4);
	printf("%s",pDate->cAccount);
    Draw_FormIO(x,y+6);
	printf("��ǰ���");
	GoTo_XY(x+18,y+7);
	printf("%d��",pDate->iBalance);
	Draw_FormIO(x,y+9);
	printf("���100/��");
	GoTo_XY(x,y+12);
	printf("Tip:���ʴ����Գ���һ����(��Ԫ��ֵ)");
	while (1)
	{
		switch(FormIO_Control(x,y+9,"�����",cDealMoney,3,NUMBER,PLAINTEXT))
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
					printf(" ����ô��,�ſղ���ɲ���Ŷ^-^");
					color(BLUE,BLACK);
				}
				else if((iDealMoney=My_DealMoney(x,y,cDealMoney)))
				{
					Draw_Popup(x-2,y+3,10,LGREEN,"      ��ܰ��ʾ   ");
					Draw_Warning(x+1,y+5,LGREEN);
					printf("�������Ƿ�ȷ�����? ������");
					Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
					printf("ȷ��:ENTER");
					Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
					printf(" ȡ��:ESC ");
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
										Draw_Popup(x-2,y-2,19,LGREEN,"������ɹ�����");
										Draw_FormIO(x,y+1);
										printf(" ���˺š�");
										GoTo_XY(x+18,y+2);
										User_PrtID(pDate);
										Draw_FormIO(x,y+4);
										printf(" Ӣ������");
										GoTo_XY(x+18,y+5);
										User_PrtAccount(pDate);
										Draw_FormIO(x,y+7);
										printf(" �����");
										GoTo_XY(x+18,y+8);
										printf("%d��",iDealMoney);
										Draw_FormIO(x,y+10);
										printf(" ��ǰ���");
										GoTo_XY(x+18,y+11);
										printf("%d��",pDate->iBalance);
										Draw_Button(x+11,y+13,1,LGREEN,BLUE);
										printf("ȷ��:ENTER");
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
						printf("ȷ��:ENTER");
						Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
						printf(" ȡ��:ESC ");		
						
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
	printf("��ȡ������");
    Draw_FormIO(x,y);
	printf("   �˺�");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf(" Ӣ������");
	GoTo_XY(x+18,y+4);
	printf("%s",pDate->cAccount);
    Draw_FormIO(x,y+6);
	printf("��ǰ���");
	GoTo_XY(x+18,y+7);
	printf("%d��",pDate->iBalance);
	Draw_FormIO(x,y+9);
	printf("ȡ��100/��");
	GoTo_XY(x,y+12);
	printf("Tip:����ȡ����Գ���һ����(��Ԫ��ֵ)");
	while (1)
	{
		switch(FormIO_Control(x,y+9,"�����",cDealMoney,3,NUMBER,PLAINTEXT))
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
					printf(" ����ô��,�ſղ���ɲ���Ŷ^-^");
					color(BLUE,BLACK);
				}
				else if ((iDealMoney=My_DealMoney(x,y,cDealMoney))>pDate->iBalance)
				{
                    Draw_Warning(x,y+13,LGREEN);
					printf("����,ȡ��ʧ��,��ENTER����");
					color(BLUE,BLACK);
				}
				else if((iDealMoney=My_DealMoney(x,y,cDealMoney)))
				{
                    Draw_Popup(x-2,y+3,10,LGREEN,"      ��ܰ��ʾ   ");
					Draw_Warning(x+1,y+5,LGREEN);
					printf("�������Ƿ�ȷ�����? ������");
					Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
					printf("ȷ��:ENTER");
					Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
					printf(" ȡ��:ESC ");
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
										Draw_Popup(x-2,y-2,19,LGREEN,"����ȡ��ɹ�����");
										Draw_FormIO(x,y+1);
										printf(" ���˺š�");
										GoTo_XY(x+18,y+2);
										User_PrtID(pDate);
										Draw_FormIO(x,y+4);
										printf(" Ӣ������");
										GoTo_XY(x+18,y+5);
										User_PrtAccount(pDate);
										Draw_FormIO(x,y+7);
										printf(" ȡ����");
										GoTo_XY(x+18,y+8);
										printf("%d��",iDealMoney);
										Draw_FormIO(x,y+10);
										printf(" ��ǰ���");
										GoTo_XY(x+18,y+11);
										printf("%d��",pDate->iBalance);
										Draw_Button(x+11,y+13,1,LGREEN,BLUE);
										printf("ȷ��:ENTER");
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
						printf("ȷ��:ENTER");
						Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
						printf(" ȡ��:ESC ");					
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
	PRecord pRDate=NULL;//Դ�˻���¼
	PRecord pAimRDate=NULL;//Ŀ���˻���¼
	PULink pAimHead=NULL;//Ŀ���û�ͨ�������׵�ַ
	PUser pAimDate=NULL;//Ŀ���û�������
	x=x+5;
	My_ClearBG();
	GoTo_XY(39,1);
	printf("��ת�˽����");
    Draw_FormIO(x,y-3);
	printf(" ��ǰ�˺�");
	GoTo_XY(x+18,y-2);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y);
	printf("��ǰ���");
	GoTo_XY(x+18,y+1);
	printf("%d��",pDate->iBalance);
	Draw_FormIO(x,y+3);
	printf(" ת���˺�");
    Draw_FormIO(x,y+6);
	printf("ת���˻���");
	Draw_FormIO(x,y+9);
	printf("ת��100/��");
	GoTo_XY(x,y+12);
	printf("Tip:����ת�˲����Գ���һ����(��Ԫ��ֵ)");
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
							printf("��Ŷ~��û����дת���˺�Ӵ~^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(cID)<8)
						{
							Draw_Warning(x+1,y+13,LGREEN);
							printf("���������˺��ǲ��ǰ�λ����^-^");
							Clear_FormIO(x,y+6,cID);
							color(BLUE,BLACK);
						}
						else if(!(ULink_Cmp(pHead,cID,User_IDcmp)))
						{
							Draw_Warning(x+1,y+13,LGREEN);
							printf(" ��Ǹ! С׿û���ҵ����˺�*-* ");
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
								printf(" ��Ǹ! �����������Աת��*-* ");
								Clear_FormIO(x,y+3,cID);
								Clear_FormIO(x,y+6,cID);
								color(BLUE,BLACK);
								iFlag--;
							}
							else if(pDate->iID==pAimDate->iID)
							{
								Draw_Warning(x+1,y+13,LGREEN);
								printf("  ��Ǹ! ��������Լ�ת��*-* ");
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
				switch(FormIO_Control(x,y+9,"�����",cDealMoney,3,NUMBER,PLAINTEXT))
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
							printf(" ��!ת�˽��ſղ���ɲ���Ŷ^-^");
							color(BLUE,BLACK);
						}
					
						else if ((iDealMoney=My_TransferMoney(x,y,cDealMoney))>pDate->iBalance)
						{
							Draw_Warning(x,y+13,LGREEN);
							printf("����,ת��ʧ��,��ENTER����");
							Clear_FormIO(x,y+9,cDealMoney);
							color(BLUE,BLACK);
						}
						else if(iDealMoney)
						{
							Draw_Popup(x-2,y+3,10,LGREEN,"      ��ܰ��ʾ   ");
							Draw_Warning(x+1,y+5,LGREEN);
							printf("�������Ƿ�ȷ��ת��? ������");
							Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
							printf("ȷ��:ENTER");
							Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
							printf(" �˳�:ESC ");
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
												Draw_Popup(x-2,y-3,20,LGREEN,"����ת�˳ɹ�����");
												Draw_FormIO(x,y+1);
												printf(" ת���˺�");
												GoTo_XY(x+18,y+2);
												printf("%d",pAimDate->iID);
												Draw_FormIO(x,y+4);
												printf("ת���û���");
												GoTo_XY(x+18,y+5);
												printf("%s",pAimDate->cAccount);
												Draw_FormIO(x,y+7);
												printf(" ת�˽��");
												GoTo_XY(x+18,y+8);
												printf("%d��",iDealMoney);
												Draw_FormIO(x,y+10);
												printf(" ��ǰ���");
												GoTo_XY(x+18,y+11);
												printf("%d��",pDate->iBalance);
												Draw_Button(x+11,y+13,1,LGREEN,BLUE);
												printf("ȷ��:ENTER");
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
								printf("ȷ��:ENTER");
								Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
								printf(" ȡ��:ESC ");					
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
		printf("������ѯ��");
		Draw_FormIO(x,y);
		printf("   �˺�");
		GoTo_XY(x+18,y+1);
		printf("%d",pDate->iID);
		Draw_FormIO(x,y+3);
		printf(" Ӣ������");
		GoTo_XY(x+18,y+4);
		printf("%s",pDate->cAccount);
		Draw_FormIO(x,y+6);
		printf("��ǰ���");
		GoTo_XY(x+18,y+7);
	    printf("%d��",pDate->iBalance);
		switch(Get_KeyValue())
		{
		case ESC:
			{
				Draw_Popup(x-2,y+3,10,LGREEN,"      ��ܰ��ʾ   ");
				Draw_Warning(x+1,y+5,LGREEN);
				printf("�����Ƿ����ڵ�ǰҳ��? �����");
				Draw_Button(x+1,y+8,iFlag%2==0,RED,LGREEN);
				printf("ȷ��:ENTER");
				Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
				printf(" �˳�:ESC ");
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
					printf("ȷ��:ENTER");
					Draw_Button(x+21,y+8,iFlag%2==1,RED,LGREEN);
					printf(" �˳�:ESC ");					
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
	printf("���޸������");
    Draw_FormIO(x,y);
	printf("   �˺�");
	GoTo_XY(x+18,y+1);
	printf("%d",pDate->iID);
	Draw_FormIO(x,y+3);
	printf("  ������");
    Draw_FormIO(x,y+6);
	printf("  ������");
	Draw_FormIO(x,y+9);
	printf(" ȷ������");
	while(1)
	{
		switch (iFlag)
		{
		case 0:
			{
				
				switch(FormIO_Control(x,y+3,"ʹ����λ����",cOldPassword,6,NUMBER,DARKTEXT))
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
								printf(" ����ô��,û������ɲ���Ŷ^-^");
							}
							else
							{
								printf(" ��д�´���,ֻΪ��д������^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(cOldPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
						    printf(" ����С����λ,����������Ŷ^-^");
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if((strcmp(cOldPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("�������������,����������!^-^");
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
				
				switch(FormIO_Control(x,y+6,"ʹ����λ����",cNewPassword,6,NUMBER,DARKTEXT))
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
								printf(" ����ô��,û������ɲ���Ŷ^-^");
							}
							else
							{
								printf(" ��д�´���,ֻΪ��д������^-^");
							}
							color(BLUE,BLACK);
						}
						else if(strlen(cOldPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" ���벻����λ,��������ȫŶ^-^");
							}
							else
							{
								printf(" ����С����λ,����������Ŷ^-^");
							}
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if((strlen(cNewPassword)<6))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" ���벻����λ,��������ȫŶ^-^");
							}
							else
							{
								printf(" ����С����λ,����������Ŷ^-^");
							}
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						
						else if((strcmp(cOldPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf("�������������,����������!^-^");
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if(!(strcmp(cNewPassword,pDate->cPasswod)))
						{
							Draw_Warning(x,y+12,LGREEN);
							printf(" �����벻���������һ��Ŷ!^-^");
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
				
				switch(FormIO_Control(x,y+9,"ʹ����λ����",cReNewPassword,6,NUMBER,DARKTEXT))
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
							printf(" ����ô��,û������ɲ���Ŷ^-^");
							color(BLUE,BLACK);
						}
						else if(strlen(cOldPassword)<6)
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" �����벻����λ,��������ȫŶ!");
							}
							else
							{
								printf(" ������С����λ,����������Ŷ!");
							}
							Clear_FormIO(x,y+3,cOldPassword);
							color(BLUE,BLACK);
						}
						else if((strlen(cNewPassword)<6))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" �����벻����λ,��������ȫŶ!");
							}
							else
							{
								printf(" ������С����λ,����������Ŷ!");
							}
							Clear_FormIO(x,y+6,cNewPassword);
							color(BLUE,BLACK);
						}
						else if((strlen(cReNewPassword)<6))
						{
							Draw_Warning(x,y+12,LGREEN);
							if (rand()%3)
							{
								printf(" �����벻����λ,��������ȫŶ!");
							}
							else 
							{
								printf(" ������С����λ,����������Ŷ!");
							}
							Clear_FormIO(x,y+9,cReNewPassword);
							color(BLUE,BLACK);
						}
						else if (!(strcmp(cReNewPassword,cNewPassword)))
						{
							if (strlen(cNewPassword)==0)
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" ��~ ���������벻��Ϊ��Ŷ!^-^");
								color(BLUE,BLACK);
							}
							else if((strcmp(cOldPassword,pDate->cPasswod)))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf("�������������,����������!^-^");
								Clear_FormIO(x,y+3,cOldPassword);
								color(BLUE,BLACK);
							}
							else if(!(strcmp(pDate->cPasswod,cNewPassword)))
							{
								Draw_Warning(x,y+12,LGREEN);
								printf(" �����벻���������һ��Ŷ!^-^");
								Clear_FormIO(x,y+6,cNewPassword);
								Clear_FormIO(x,y+6,cReNewPassword);
								color(BLUE,BLACK);
							}
							else
							{
								iFlag=0;
								memcpy(pDate->cPasswod,cNewPassword,8);
								*pFp=File_Write(pHead,Name_Date_User,sizeof(User));
								Draw_Popup(x-2,y-2,19,LGREEN,"���μ������û���ϢŶ~");
								Draw_FormIO(x,y+1);
								printf(" �˻�����");
								GoTo_XY(x+18,y+2);
								User_PrtIdentity(pDate);
								Draw_FormIO(x,y+4);
								printf(" ���˺š�");
								GoTo_XY(x+18,y+5);
								User_PrtID(pDate);
								Draw_FormIO(x,y+7);
								printf(" Ӣ������");
								GoTo_XY(x+18,y+8);
								User_PrtAccount(pDate);
								Draw_FormIO(x,y+10);
								printf(" �������");
								GoTo_XY(x+18,y+11);
								User_PrtPassword(pDate);
								Draw_Button(x+11,y+13,iFlag%2==0,LGREEN,BLUE);
								printf("ȷ��:ENTER");
								while(Get_KeyValue()!=ENTER)
								{
									
								};
								Draw_Popup(x-2,y+3,10,RED,"        ����     ");
								Draw_Warning(x+1,y+5,RED);
								printf("  ��������ı�,�����µ�¼��� ");
								Draw_Button(x+11,y+8,1,RED,GREEN);
								printf(" �˳�:ESC");
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
							printf(" Ŷ��~�����������벻һ��Ŷ^-^");
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
	      Pritf_Tile(45,25,"��ｻ�׼�¼���","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
		  Draw_Warning(26,5,BLUE);
		  printf("  �����ѡ����Ĳ������͡��");
		  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
		  printf(" ��ʾ���� ");
		  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
		  printf(" ʱ���ѯ ");
		  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
		  printf("   ����   ");
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
							  My_ClearBG();//����
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
			  Pritf_Tile(45,25,"��ｻ�׼�¼���","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
			  Draw_Warning(26,5,BLUE);
			  printf("  �����ѡ����Ĳ������͡��");
			  Draw_Button(36,9,iFlag%3==0,LBLUE,BLUE);
			  printf(" ��ʾ���� ");
			  Draw_Button(36,13,iFlag%3==1,LBLUE,BLUE);
			  printf(" ʱ���ѯ ");
			  Draw_Button(36,17,iFlag%3==2,LBLUE,BLUE);
			  printf("   ����   ");
			  color(BLUE,BLACK);
		  }
		  
		  
}


void User_Record(int x,int y,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int))
{
	int iCount=0;
	int iPageNum=0;
	int iLastNum=0;
	int iPage=0;//ҳ��
	int iFlag=0;//��ѡ���ѡ��
	PULink pTemp=NULL;
	PULink pPriHead=pHead;//��ʼ��ӡ��ͷ�ڵ��ַ
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
	printf("��%d/%dҳ",iPage+1,iPageNum+1);
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
					Draw_Popup(x+6,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+9,y+5,LGREEN);
					printf("�������Ѿ��ǵ�һҳ�ˡ�����");
					Draw_Button(x+19,y+8,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
					Draw_Popup(x+6,y+3,10,LGREEN,"        ��ʾ     ");
					Draw_Warning(x+9,y+5,LGREEN);
					printf("������û������һҳ�ˡ�����");
					Draw_Button(x+19,y+8,1,LGREEN,GREEN);
					printf("ȷ��:ENTER");
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
		printf("��%d/%dҳ",iPage+1,iPageNum+1);
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
					printf("���");
				}break;
			case WITHDRAW:
				{
               		printf("ȡ��");  
				}break;
			case TURNIN:
				{
					printf("ת��");	
				}break;
			case TURNOUT:
				{
					printf("ת��");	
				}break;
			}
			GoTo_XY(x+58,y+2*i);
			if (((PRecord)pHead->pDate)->iSourseID==0)
			{
             printf("   ATM��  ");
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
			Pritf_Tile(45,25,"���ʱ���ѯ���","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
			if (iFlag==1)
			{
				GoTo_XY(35,21);
				printf("��ʼ����:%d��%d��%d��",ForthDate/10000,(ForthDate%10000)/100,ForthDate%100);
			}
			Draw_Button(36,y-3,1,BLUE,BLUE);
            printf("%s",cTitle);
			Draw_FormIO(x,y+1);
			printf(" ����ݡ�");
			Draw_FormIO(x,y+4);
			printf(" ���·ݡ�");
			Draw_FormIO(x,y+7);
         	printf(" �����ڡ�");
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
					Draw_Popup(23,y+1,10,RED,"      �������   ");
					Draw_Warning(26,y+3,RED);
					printf("   ��������Ϣ���������");
					Draw_Button(36,y+6,1,RED,GREEN);
					printf("ȷ��:ENTER");
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
					Draw_Popup(23,y+1,10,RED,"      �������   ");
					Draw_Warning(26,y+3,RED);
					printf("   ����·���Ϣ����Ϊ�ա��");
					Draw_Button(36,y+6,1,RED,GREEN);
					printf("ȷ��:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					My_ClearBG();
					Pritf_Tile(45,25,"���ʱ���ѯ���","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
					Draw_Button(36,y-3,1,BLUE,BLUE);
                    printf("%s",cTitle);
					Draw_FormIO(x,y+1);
					printf(" ����ݡ�");
					GoTo_XY(x+18,y+2);
					printf("%s",cYear);
					Draw_FormIO(x,y+4);
					printf(" ���·ݡ�");
					Draw_FormIO(x,y+7);
					printf(" �����ڡ�");
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
					Draw_Popup(23,y+1,10,RED,"      �������   ");
					Draw_Warning(26,y+3,RED);
					printf("   ���������Ϣ����Ϊ�ա��");
					Draw_Button(36,y+6,1,RED,GREEN);
					printf("ȷ��:ENTER");
					color(BLUE,BLACK);
					while(Get_KeyValue()!=ENTER)
					{
						
					}
					My_ClearBG();
					Pritf_Tile(45,25,"���ʱ���ѯ���","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
					Draw_Button(36,y-3,1,BLUE,BLUE);
                    printf("%s",cTitle);
					Draw_FormIO(x,y+1);
					printf(" ����ݡ�");
					GoTo_XY(x+18,y+2);
					printf("%s",cYear);
					Draw_FormIO(x,y+4);
					printf(" ���·ݡ�");
					GoTo_XY(x+18,y+5);
					printf("%s",cMonth);
					Draw_FormIO(x,y+7);
					printf(" �����ڡ�");
		            Clear_FormIO(x,y+7,cDay);
				}
				else
				{
					break;
				}
			}
			
		}
		iDateNum=Date_Effective(cYear,cMonth,cDay);
		if (iDateNum)//�ж����������ʽ�Ƿ���ȷ
		{
			return iDateNum;
		}
		else if (iDateNum==0)
		{
			Draw_Popup(23,y+3,10,RED,"      �������   ");
			Draw_Warning(26,y+5,RED);
			printf("   �����������ڲ����ڡ��");
			Draw_Button(36,y+8,1,RED,GREEN);
			printf("ȷ��:ENTER");
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
	Pritf_Tile(45,25,"���ʱ���ѯ���","ȷ��:ENTER\t\t      ����������ѡ��","�˳�:  ESC  ");
	pT=(TIME*)localtime(&Time);
	NowDate=(((pT->iYear+1900)*10000)+((pT->iMon+1)*100)+((pT->iMDay)*1));
	while(1)
	{
		while(1)
		{
			iFlag=0;
			ForthDate=My_DateIO(26,y," ��ʼ����",iFlag,ForthDate);//ȷ����ʼ������������Χ��
			if (ForthDate==ESC)
			{
				return NULL;
			}
			else if (ForthDate>NowDate)
			{
				Draw_Popup(23,y+1,10,RED,"      �������   ");
				Draw_Warning(26,y+3,RED);
				printf("�����ʼ���ڲ�����δ�����ڡ��");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("ȷ��:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}
			}
			else if(ForthDate<UserRefisterTimeNum)
			{
				Draw_Popup(23,y+1,10,RED,"      �������   ");
				Draw_Warning(26,y+3,RED);
				printf(" �����ʼ��������ע��ʱ����");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("ȷ��:ENTER");
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
			
			BackDate=My_DateIO(26,y," ��ֹ����",iFlag,ForthDate);//ȷ����ֹ������������Χ��
			if (BackDate==ESC)
			{
				return NULL;
			}
			else if (BackDate>NowDate)
			{
				Draw_Popup(23,y+1,10,RED,"      �������   ");
				Draw_Warning(26,y+3,RED);
				printf("�����ֹ���ڲ�����δ��ʱ����");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("ȷ��:ENTER");
				color(BLUE,BLACK);
				while(Get_KeyValue()!=ENTER)
				{
					
				}
			}
			else if(BackDate<ForthDate)
			{
				Draw_Popup(23,y+1,10,RED,"      �������   ");
				Draw_Warning(26,y+3,RED);
				printf(" �����ֹ����������ʼʱ����");
				Draw_Button(36,y+6,1,RED,GREEN);
				printf("ȷ��:ENTER");
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
				Draw_Popup(23,y+3,10,RED,"      �������   ");
				Draw_Warning(26,y+5,RED);
				printf("  ���ʱ���ȳ���һ���¡��");
				Draw_Button(36,y+8,1,RED,GREEN);
				printf("ȷ��:ENTER");
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


