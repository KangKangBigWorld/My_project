#ifndef __ASCII_H
#define __ASCII_H	   
//����ASCII��
//ƫ����32 
//ASCII�ַ���: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//PC2LCD2002ȡģ��ʽ���ã�����+����ʽ+˳��+C51��ʽ
//�ܹ���3���ַ�����12*12��16*16��24*24�����û������������������ֱ��ʵ��ַ�����
//ÿ���ַ���ռ�õ��ֽ���Ϊ:(size/8+((size%8)?1:0))*(size/2),����size:���ֿ�����ʱ�ĵ����С(12/16/24...)
 
//12*8 ASCII�ַ�������
extern const unsigned char asc_1206[95][12];  
//16*8 ASCII�ַ�������
extern const unsigned char asc_1608[95][16];  
//24*12 ASICII�ַ�������
extern const unsigned char asc_2412[95][36];  
//24�� 12��

#endif
