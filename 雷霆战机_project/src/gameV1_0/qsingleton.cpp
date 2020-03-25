#include "qsingleton.h"

QAftermath aftermath;
QSingleTon* QSingleTon::m_pInstance = NULL;

QSingleTon *QSingleTon::GetInstance()
{
    if(m_pInstance == NULL)
    {
        m_pInstance = new QSingleTon();
        //atexit(Release);
    }
    return m_pInstance;
}

void QSingleTon::Release()
{
    if(m_pInstance)
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

QSingleTon::QSingleTon():
    m_nCount(0)
{
    name = QString();
    hard = 2;
    guide = 1;
    integral = 0;
}

QAftermath::~QAftermath()
{
    QSingleTon *single = QSingleTon::GetInstance();
    delete single;

    QResources *sources = QResources::GetInstance();
    delete sources;
}

