#include "qwindowmanger.h"

QStartUi::QStartUi(QMyWidget *parent) :
    QMyWidget(parent)
{
    higherWidget = 0;
    //��������
    QCursor  cursor(QPixmap("./Image/mouse.png"));
    this->setCursor(cursor);
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    //���ñ���
    setbg();

    //����
    //this->pDesktop = QApplication::desktop();
    //CVxMainWindow w(pDesk);
    //this->move((pDesk->width() - this->width()) / 2, (this->pDesktop->height() - this->height()) / 2);

    //���ñ�ǩ��С����
    setlab();
    //���ð���
    setbtn();
}
//�������ñ���
void QStartUi::setbg()
{
    //���ô��ڴ�С
    this->setFixedSize(563,1000);
    //����������
    //pDesktop=QApplication::desktop();
    //this->move((pDesktop->width()-640)/2,(pDesktop->height()-1136)/2);
    this->move(650,10);
    //���ô��ڱ���
    this->setWindowTitle(QString::fromLocal8Bit("����ս��"));
    //���ô���ͼ��
    this->setWindowIcon(QIcon("./Image/Icon/Icon.jpg"));
    //ȥ�߿�
    this->setWindowFlags(Qt::FramelessWindowHint);
    //���ñ���
    //QPalette palette;
    //���õ�ɫ���ˢ
    //palette.setBrush(QPalette::Background,QBrush(QPixmap("./Image/must/cover2.jpg")));
    //����Ϊ�˴��ڵĵ�ɫ��
    //this->setPalette(palette);
    //���ñ���͸��
    //this->setAttribute(Qt::WA_TranslucentBackground,false);


    btnSize = QSize(200,80);
    btnBase = QPoint((width()-btnSize.width())/2,300);
    btnBps = QPoint(0,btnSize.height()+30);
}

void QStartUi::setlab()
{

    QParallelAnimationGroup *group;
    QPropertyAnimation *anim;
    group = new QParallelAnimationGroup;
    //���Ʊ���ͼ
    pIconLTZJ = new QLabel(this);
    pIconLTZJ->resize(size());
    pIconLTZJ->setScaledContents(true);
    pIconLTZJ->setStyleSheet("QLabel{border-image:url(\"./Image/must/cover2.jpg\")}");

    //����
    this->pLabel= new QLabel(this);
    this->pLabel->setStyleSheet("QLabel{border-image:url(\"./Image/LoginWidgetUI/cover-logo.png\")}");
    this->pLabel->setGeometry((size().width()-586)/2,40,586,206);
    //������˸
        QPoint enterPoint(280,205);
        QSize maxSize(100,100);
        this->pStar = new QLabel(this);
        this->pStar->setStyleSheet("QLabel{border-image:url(\"./Image/LoginWidgetUI/StartUI_Star.png\")}");
        anim = new QPropertyAnimation(this->pStar,"geometry");
        anim->setDuration(4000);
        anim->setLoopCount(-1);
        anim->setKeyValueAt(0,QRect(enterPoint.x(),enterPoint.y(),0,0));
        anim->setKeyValueAt(0.5,QRect(enterPoint.x() - maxSize.width()/2,enterPoint.y()  - maxSize.height()/2,maxSize.width(),maxSize.height()));
        anim->setKeyValueAt(1,QRect(enterPoint.x(),enterPoint.y(),0,0));
        group->addAnimation(anim);

        //��������
        QSize girlStart(200,200);
        QSize girlEnd(150,150);
        this->pPeole = new QLabel(this);
        this->pPeole->setStyleSheet("QLabel{border-image:url(\"./Image/LoginWidgetUI/StartUI_NPC.png\")}");
        anim = new QPropertyAnimation(this->pPeole,"geometry");
        anim->setDuration(3000);
        anim->setLoopCount(-1);
        anim->setKeyValueAt(0,QRect(this->width()-girlStart.width(),this->height()-girlStart.height(),girlStart.width(),girlStart.height()));
        anim->setKeyValueAt(0.2,QRect(this->width()-girlEnd.width(),this->height()-girlEnd.height(),girlEnd.width(),girlEnd.height()));
        anim->setKeyValueAt(1,QRect(this->width()-girlStart.width(),this->height()-girlStart.height(),girlStart.width(),girlStart.height()));
        group->addAnimation(anim);

        //��
        this->pLight = new QLabel(this);
        this->pLight->setStyleSheet("QLabel{border-image:url(\"./Image/LoginWidgetUI/cover-logo-flash.png\")}");
        this->pLight->setFocusPolicy(Qt::NoFocus);
        anim = new QPropertyAnimation(this->pLight,"geometry");
        anim->setDuration(5000);
        anim->setLoopCount(-1);
        anim->setStartValue(QRect(-210,40,187,210));
        anim->setEndValue(QRect(this->width()+210,40,187,210));
        group->addAnimation(anim);

        //�Ʒɹ�
        this->pCloud = new QLabel(this);
        this->pCloud->setStyleSheet("QLabel{border-image:url(\"./Image/LoginWidgetUI/StartUI_WhiteCloud.png\")}");
        anim = new QPropertyAnimation(this->pCloud,"geometry");
        anim->setDuration(5000);
        anim->setLoopCount(-1);
        anim->setStartValue(QRect(-60,42,60,40));
        anim->setEndValue(QRect(460,78,58,42));
        group->addAnimation(anim);
        this->pCloud2 = new QLabel(this);
        this->pCloud2->setStyleSheet("QLabel{border-image:url(\"./Image/LoginWidgetUI/StartUI_WhiteCloud.png\")}");
        this->pCloud2->setGeometry((this->width()-586)/2,40,586,206);
        anim = new QPropertyAnimation(this->pCloud2,"geometry");
        anim->setDuration(11000);
        anim->setLoopCount(-1);
        anim->setStartValue(QRect(-200,90,200,100));
        anim->setEndValue(QRect(550,82,150,150));
        group->addAnimation(anim);

        group->start();
}

void QStartUi::setbtn()
{
    //���ð�ť

    pLoginBtn = new QMyButton("��¼",this);
    pLoginBtn->setGeometry(QRect(btnBase.x(),btnBase.y(),btnSize.width(),btnSize.height()));
    connect( pLoginBtn, SIGNAL(clicked()),this,SLOT(nextslots()) );

    btnBase += btnBps;
    pHelpBtn = new QMyButton("����",this);
    pHelpBtn->setGeometry(QRect(btnBase.x(),btnBase.y(),btnSize.width(),btnSize.height()));
    connect( pHelpBtn, SIGNAL(clicked()),this,SLOT(helpslots()) );

    btnBase += btnBps;
    pRankBtn = new QMyButton("���а�",this);
    pRankBtn->setGeometry(QRect(btnBase.x(),btnBase.y(),btnSize.width(),btnSize.height()));
    connect( pRankBtn, SIGNAL(clicked()),this,SLOT(rankslots()) );

    btnBase += btnBps;
    pAboutBtn = new QMyButton("����",this);
    pAboutBtn->setGeometry(QRect(btnBase.x(),btnBase.y(),btnSize.width(),btnSize.height()));
    connect( pAboutBtn, SIGNAL(clicked()),this,SLOT(relslots()) );

    btnBase += btnBps;
    pExitBtn = new QMyButton("�˳�",this);
    pExitBtn->setGeometry(QRect(btnBase.x(),btnBase.y(),btnSize.width(),btnSize.height()));
    connect( pExitBtn, SIGNAL(clicked()),this,SLOT(lastFromslots()));

    pSetBtn = new QMyButton(this,QString("./Image/StartUI/StartUI_SetButton.png"));
    pSetBtn->setGeometry(QRect(30,840,100,100));
    connect( pSetBtn, SIGNAL(clicked()),this,SLOT(segslots()));
}

void QStartUi::nextslots()
{
    this->hide();
    QWindowManger::intence->pLoginPopup->show();
}

void QStartUi::helpslots()
{
    this->hide();
    QWindowManger::intence->pHelp->show();
}

void QStartUi::rankslots()
{
    //����  ����
    this->hide();
    QWindowManger::intence->pRankList->show();
}

void QStartUi::relslots()
{
    this->hide();
    QWindowManger::intence->pAbout->show();
}

void QStartUi::segslots()
{
    this->hide();
    QWindowManger::intence->pSetFrom->show();
}



void QStartUi::AllButtonHide()
{
    this->pLoginBtn->hide();
    this->pHelpBtn->hide();
    this->pRankBtn->hide();
    this->pAboutBtn->hide();
    this->pExitBtn->hide();
    this->pSetBtn->hide();
}


void QStartUi::AllButtonShow()
{

    this->pLoginBtn->show();
    this->pHelpBtn->show();
    this->pRankBtn->show();
    this->pAboutBtn->show();
    this->pExitBtn->show();
    this->pSetBtn->show();
}



