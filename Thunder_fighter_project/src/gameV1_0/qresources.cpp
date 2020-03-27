#include "qresources.h"

#include <QDir>
#include <QFileInfoList>
QResources* QResources::m_pInstance = NULL;

QResources *QResources::GetInstance()
{
    if(m_pInstance == NULL)
    {
        m_pInstance = new QResources();
    }
    return m_pInstance;
}

void QResources::Release()
{
    if(m_pInstance)
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}



QResources::QResources()
{
    QString path("./Image/Game/");
    QDir dir(path);
    QFileInfoList f_list=dir.entryInfoList();
    dir.setFilter(QDir::Files|QDir::NoDot|QDir::NoDotAndDotDot|QDir::NoSymLinks);
    for(int i=0;i<f_list.count();i++)
    {
        QFileInfo f_info=f_list.at(i);
        QString stt=f_info.fileName();//获取文件名
        if(stt == QString(".") || stt == QString(".."))
        {
            continue;
        }
        gamePix.insert(stt,QPixmap(path+stt));
    }

    path = QString("./Image/GameUI/");
    dir.setPath(path);
    f_list=dir.entryInfoList();
    dir.setFilter(QDir::Files|QDir::NoDot|QDir::NoDotAndDotDot|QDir::NoSymLinks);
    for(int i=0;i<f_list.count();i++)
    {
        QFileInfo f_info=f_list.at(i);
        QString stt=f_info.fileName();//获取文件名
        if(stt == QString(".") || stt == QString(".."))
        {
            continue;
        }
        gamePix.insert(stt,QPixmap(path+stt));
    }
}
