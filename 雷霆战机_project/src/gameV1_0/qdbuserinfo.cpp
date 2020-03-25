#include "qdbuserinfo.h"

QDbUserInfo::QDbUserInfo()
{
    QString load = QString("./myDat.db");
    QByteArray filename = load.toLatin1();
    ret = sqlite3_open(filename.data(),&db);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
}

QDbUserInfo::QDbUserInfo(QString load)
{
    QByteArray filename = load.toLatin1();
    ret = sqlite3_open(filename.data(),&db);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
}

bool QDbUserInfo::login(QString name, QString pwd)
{
    char sql[256];
    QByteArray sname = name.toLatin1(),spwd = pwd.toLatin1();
    sprintf(sql,"select user_account,user_passwd  from tbl_userinfo where user_account  = '%s' and user_passwd  = '%s';",sname.data(),spwd.data());

    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    sqlite3_free_table(qresult);
    if(row == 1)
    {
        qDebug("login success");
        return true;
    }
    return false;
}

void QDbUserInfo::setVolum(VOICE mode, int volum)
{
    char sql[256];
    switch(mode)
    {
        case BACKGROUND:
            sprintf(sql,"update tbl_userGameSet set GameSet_backgroundMusic = %d;",volum);
            break;
        case SOUNDEFFECT:
            sprintf(sql,"update tbl_userGameSet set GameSet_soundEffectMusic = %d;",volum);
            break;
        default:;
    }
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    sqlite3_free_table(qresult);
}

int QDbUserInfo::volum(VOICE mode)
{
    char sql[256];
    switch(mode)
    {
        case BACKGROUND:
            sprintf(sql,"select GameSet_backgroundMusic from tbl_userGameSet;");
            break;
        case SOUNDEFFECT:
            sprintf(sql,"select GameSet_soundEffectMusic  from tbl_userGameSet;");
            break;
        default:;
    }
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    int volum;
    QString str = qresult[1];
    volum = str.toInt();
    sqlite3_free_table(qresult);
    return volum;
}

void QDbUserInfo::getUserinfo(REGMODE mode)
{
    char sql[256];

    switch(mode)
    {
        case RANDOMNAME:
            sprintf(sql,"select randomName from tbl_randomName where state = 0;");
            break;
        case UNIQUE:
            sprintf(sql,"select user_account from tbl_userinfo;");
            break;
        default:;
    }

    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    sqlite3_free_table(qresult);
}

void QDbUserInfo::saveUserinfo(QString name,QString pwd,QString question,QString answer)
{
    char sql[256];
    sprintf(sql,"insert into tbl_userinfo values('%s','%s','%s','%s');",
            name.toStdString().c_str(),
            pwd.toStdString().c_str(),
            question.toStdString().c_str(),
            answer.toStdString().c_str());
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    sqlite3_free_table(qresult);
}

bool QDbUserInfo::getQuestion(QString name)
{
    char sql[256];
    sprintf(sql,"select user_securityQuestion,user_securityAnswer from tbl_userinfo where user_account = '%s';",
            name.toStdString().c_str());
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    if(row == 0)
    {
        return false;
    }
    return true;
}

bool QDbUserInfo::getPassword(QString name)
{
    char sql[256];
    sprintf(sql,"select user_passwd from tbl_userinfo where user_account = '%s';",
            name.toStdString().c_str());
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    if(row == 0)
    {
        return false;
    }
    return true;
}

void QDbUserInfo::changePwd(QString name, QString pwd)
{
    char sql[256];
    sprintf(sql,"update tbl_userinfo set user_passwd = '%s' where user_account = '%s';",
            pwd.toStdString().c_str(),name.toStdString().c_str());
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
}

bool QDbUserInfo::rank(int pageRowMax, int &curPage)
{
    char sql[256];
    sprintf(sql,"select user_account,user_integral from tbl_userIntegral order by user_integral desc limit %d,%d;",pageRowMax*(curPage-1),pageRowMax);
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    if(row == 0)
    {
        return false;
    }
    return true;
}

bool QDbUserInfo::addrank(QString name, int inter)
{
    char sql[256];
    sprintf(sql,"insert into tbl_userIntegral values('%s',%d);",name.toStdString().c_str(),inter);
    ret = sqlite3_get_table(db,sql,&qresult,&row,&col,&errmsg);
    if (SQLITE_OK  != ret)
    {
        qDebug()<<ret<<":sqlite3_open "<<sqlite3_errmsg(db);
        exit(0);
    }
    return true;
}





