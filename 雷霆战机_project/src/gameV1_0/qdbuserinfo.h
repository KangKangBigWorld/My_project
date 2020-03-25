#ifndef QDBUSERINFO_H
#define QDBUSERINFO_H

#include <QString>
#include <QDebug>
#include <stdio.h>
/*  //使用方式
    QDbUserInfo info;
    info.setVolum(SOUNDEFFECT,40);
    info.volum(SOUNDEFFECT);//BACKGROUND,
    info.setVolum(BACKGROUND,20);
    info.volum(BACKGROUND);//BACKGROUND,
    //登录信息匹配
    if(login(name,passwd)) qDebug()<<"login success";
    //祖册信息录入
*/
#include "sqlite3.h"
//声音
enum VOICE
{
    BACKGROUND,
    SOUNDEFFECT
};
//注册访问数据库的几种模式
enum REGMODE
{
    RANDOMNAME,
    UNIQUE
};
//登录信息匹配  注册信息匹配（）  飞机属性
class QDbUserInfo
{
public:
    QDbUserInfo();
    QDbUserInfo(QString load);

    //登录用数据库
    bool login(QString name,QString pwd);
    //设置音量用  音效
    void setVolum(VOICE mode,int volum);
    int volum(VOICE mode);
    //注册用数据库
    void getUserinfo(REGMODE mode);
    void saveUserinfo(QString name,QString pwd,QString question,QString answer);
    //忘记密码使用
    bool getQuestion(QString name);//qresult 1问题 2答案
    void changePwd(QString name,QString pwd);
    //登录用数据库
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
