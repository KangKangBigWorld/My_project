#ifndef __FONT_H
#define __FONT_H 	   



// ------------------  汉字字模的数据结构定义 ------------------------ //
struct  Cn32CharTypeDef                   // 汉字字模数据结构 
{
	unsigned char  Index[2];            // 汉字内码索引,一个汉字占两个字节	
	unsigned char   Msk[72];            // 点阵码数据(32*29/8) 
};
/////////////////////////////////////////////////////////////////////////
// 汉字字模表,大小为：24*24                                                          //
// 汉字库: 宋体二号,横向取模左高位,数据排列:从左到右从上到下           //
/////////////////////////////////////////////////////////////////////////
extern  struct  Cn32CharTypeDef const CnChar24x24[30];


#endif
