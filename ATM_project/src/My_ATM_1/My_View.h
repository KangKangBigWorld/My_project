#ifndef _MY_VIEW_H_
#define _MY_VIEW_H_
#include <stdio.h>
#include <windows.h>
#include "GoTo_XY.h"
#include "User_LinkList.h"

/******************************宏定义***************************************/
#define BLACK   0   //黑色
#define DBLUE   1   //蓝色 
#define DGREEN  2   //绿色
#define BLUE    3   //湖蓝色
#define RED     4   //红色
#define VIOLET  5   //紫色 
#define YELLOW  6   //黄色
#define WHITE   7   //白色
#define GRAY    8   //灰色 
#define LBLUE   9   //淡蓝色
#define GREEN   10  //淡绿色
#define LGREEN  11  //淡浅绿色
#define LRED    12  //淡红色
#define LVIOLET 13  //淡紫色
#define LYELLOW 14  //亮黄色
#define LWHITE  15  //亮白色

/***********************************数据类型定义********************************/




/******************************函数原型***************************************/

/************************************************************************/
/*                                                                      
   *函数名称:void color(int iFore,int iBack);
   *功能描述:释放通用链表
   *参数说明:
   *        iFore       前景色（字的颜色）
   *        iBack       背景色（背景的颜色）
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :
　　0=黑色                8=灰色　　
　  1=蓝色                9=淡蓝色        十六进制        　　                        
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色              11=淡浅绿色     0xb　
　　4=红色                12=淡红色       0xc　　
　　5=紫色                13=淡紫色       0xd        　　
　　6=黄色                14=淡黄色       0xe        　　
　　7=白色                15=亮白色       0xf 
　　也可以把这些值设置成常量。
                                                                        */
void color(int iFore,int iBack);

/************************************************************************/
/*                                                                      
   *函数名称:void Draw_line(int x,int y,int iLen);
   *功能描述:划线
   *参数说明:
   *        x           外框左上角出现的横坐标
   *        y           外框左上角出现的纵坐标
   *        iLen         长度
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.12            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_line(int x,int y,int iLen);

/************************************************************************/
/*                                                                      
   *函数名称:void Draw_Button(int x,int y,int iSelect,int iSColor,int iNSColor));
   *功能描述:绘制按键外框，并将光标移至框内，选择按键框改变样式
   *参数说明:
   *        x           外框左上角出现的横坐标
   *        y           外框左上角出现的纵坐标
   *        iSelect     是否选择按键的标志
   *        iSColor     选择按键时按键的颜色
   *        iNSColor    未选择按键时按键的颜色
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.12            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Button(int x,int y,int iSelect,int iSColor,int iNSColor);

/************************************************************************/
/*                                                                      
   *函数名称:void Draw_Warning(int x,int y,int iColor);
   *功能描述:绘制警告外框，并将光标移至框内，选择按键框改变样式
   *参数说明:
   *        x           外框左上角出现的横坐标
   *        y           外框左上角出现的纵坐标
   *        iSelect     是否选择按键的标志
   *        iSColor     选择按键时按键的颜色
   *        iNSColor    未选择按键时按键的颜色
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Warning(int x,int y,int iColor);

/************************************************************************/
/*                                                                      
   *函数名称:void Clear_Waring(int x,int y);
   *功能描述:清除警告
   *参数说明:
   *        x           外框左上角出现的横坐标
   *        y           外框左上角出现的纵坐标
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :
　
                                                                        */
void Clear_Warning(int x,int y);

/************************************************************************/
/*                                                                      
   *函数名称:void Draw_Popup(int x,int y,int hight,int iColor,char* sTitle);
   *功能描述:弹窗的外框
   *参数说明:
   *        x           外框左上角出现的横坐标
   *        y           外框左上角出现的纵坐标
   *        hight       外框的高度
   *        iColor      外框的颜色
   *        Title       弹窗的标题
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Popup(int x,int y,int hight,int iColor,char* sTitle);


/************************************************************************/
/*                                                                      
   *函数名称:void Draw_FormIO(int x,int y);
   *功能描述:绘制一个一行二列表格，并把光标移动到表格第一列内
   *参数说明:
   *        x           表格左上角出现的横坐标
   *        y           表格左上角出现的纵坐标
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.12            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_FormIO(int x,int y);

/************************************************************************/
/*                                                                      
   *函数名称:void Clear_FormIO(int x,int y,char* cStr);
   *功能描述:情况表格内的输入内容并重置输入。
   *参数说明:
   *        x           表格左上角出现的横坐标
   *        y           表格左上角出现的纵坐标
   *        cStr        输入的字符串首地址
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.15            修改人:何亚康
   *描述    :
　
                                                                        */
void Clear_FormIO(int x,int y,char* cStr);

/************************************************************************/
/*                                                                      
*函数名称:void Draw_Background(int iWide,int iHight);
   *功能描述:绘制背景，打印标题和左、右下角信息
   *参数说明:
   *        iWide       背景宽度为2*iWide
   *        iHight      背景高度为iHight
   *        sTitle      标题字符串首地址
   *        sLowLeft    左下角字符串首地址
   *        sLowRight   右下角字符串首地址
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Background(int iWide,int iHight);

/************************************************************************/
/*                                                                      
*函数名称:void Pritf_Tile(int iWide,int iHight,char* sTitle,char* sLowLeft,char* sLowRight);
   *功能描述:打印标题和左、右下角信息
   *参数说明:
   *        iWide       背景宽度为2*iWide
   *        iHight      背景高度为iHight
   *        sTitle      标题字符串首地址
   *        sLowLeft    左下角字符串首地址
   *        sLowRight   右下角字符串首地址
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void Pritf_Tile(int iWide,int iHight,char* sTitle,char* sLowLeft,char* sLowRight);


/************************************************************************/
/*                                                                      
   *函数名称:void My_Date();
   *功能描述:清空主界面
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void My_ClearBG();




/************************************************************************/
/*                                                                      
*函数名称:void Draw_Main(void);
   *功能描述:
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Main(void);

/************************************************************************/
/*                                                                      
*函数名称:void Draw_Main_Button(int iFlag);
   *功能描述:绘制主界面按键
   *参数说明:
   *        iFlag       传递选择按键信号
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Main_Button(int iFlag);


/************************************************************************/
/*                                                                      
*函数名称:void Draw_SignOut(int iFlag);
   *功能描述:绘制退出界面
   *参数说明:
   *        iFlag       传递选择按键信号
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_SignOut(int iFlag);

/************************************************************************/
/*                                                                      
*函数名称:void Draw_UserWin();
   *功能描述:用户界面
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.16            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_UserWin();

/************************************************************************/
/*                                                                      
*函数名称:void Draw_AdminWin();
   *功能描述:管理员界面
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.16            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_AdminWin();

/************************************************************************/
/*                                                                      
*函数名称:void Draw_User_Button(int iFlag);
   *功能描述:用户按键
   *参数说明:
   *        iFlag       传递选择按键信号
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.16            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_User_Button(int iFlag);

/************************************************************************/
/*                                                                      
*函数名称:void Draw_Admin_Button(int iFlag);
   *功能描述:管理员按键
   *参数说明:
   *        iFlag       传递选择按键信号
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.16            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Admin_Button(int iFlag);

/************************************************************************/
/*                                                                      
*函数名称:void Draw_Page(int x,int y);
   *功能描述:翻页表格
   *参数说明:
   *        x           表格左上角出现的横坐标
   *        y           表格左上角出现的纵坐标
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.16            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_Page(int x,int y);


/************************************************************************/
/*                                                                      
*函数名称:void Draw_RecordPage(int x,int y);
   *功能描述:记录的表格
   *参数说明:
   *        x           表格左上角出现的横坐标
   *        y           表格左上角出现的纵坐标
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.16            修改人:何亚康
   *描述    :
　
                                                                        */
void Draw_RecordPage(int x,int y);


#endif