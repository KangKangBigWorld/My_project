#ifndef QDBUSERINFO_H
#define QDBUSERINFO_H

#include <QString>
#include <QDebug>
#include <stdio.h>
/*  //ʹ�÷�ʽ
    QDbUserInfo info;
    info.setVolum(SOUNDEFFECT,40);
    info.volum(SOUNDEFFECT);//BACKGROUND,
    info.setVolum(BACKGROUND,20);
    info.volum(BACKGROUND);//BACKGROUND,
    //��¼��Ϣƥ��
    if(login(name,passwd)) qDebug()<<"login success";
    //�����Ϣ¼��
*/
#include "sqlite3.h"
//����
enum VOICE
{
    BACKGROUND,
    SOUNDEFFECT
};
//ע��������ݿ�ļ���ģʽ
enum REGMODE
{
    RANDOMNAME,
    UNIQUE
};
//��¼��Ϣƥ��  ע����Ϣƥ�䣨��  �ɻ�����
class QDbUserInfo
{
public:
    QDbUserInfo();
    QDbUserInfo(QString load);

    //��¼�����ݿ�
    bool login(QString name,QString pwd);
    //����������  ��Ч
    void setVolum(VOICE mode,int volum);
    int volum(VOICE mode);
    //ע�������ݿ�
    void getUserinfo(REGMODE mode);
    void saveUserinfo(QString name,QString pwd,QString question,QString answer);
    //��������ʹ��
    bool getQuestion(QString name);//qresult 1���� 2��
    void changePwd(QString name,QString pwd);
    //��¼�����ݿ�
    bool getPassword(QString name);
    bool rank(int pageRowMax,int &curPage);
    bool addrank(QString name,int inter);
    char **qresult;
    int row,col;
private:
    sqlite3 *db;
    char *errmsg;
    int ret;
};

#endif // QDBUSERINFO_H
