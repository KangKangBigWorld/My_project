#include "qwindowmanger.h"
#include "qgame.h"


QLoginUi::QLoginUi(QMyWidget *parent)
{
    //�����ϼ�����
    higherWidget = parent;
    this->pParent=parent;
    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    //���ñ���
    setbg();

    //���ð���
    setbtn();
    //���ñ�ǩ
    setedit();
    this->hide();
}

void QLoginUi::setbg()
{
    QLabel *lab;
    //���ô����Զ���䱳�������ǣ�
    //this->setAutoFillBackground(true);
    //���ô��ڴ�С
    this->setFixedSize(516,442);
    //���ô���λ��
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,300,516,442);
    //���ô��ڱ���
    this->setWindowTitle(QString::fromLocal8Bit("����ս��"));
    //���Ʊ���ͼ
    lab = new QLabel(this);
    lab->setGeometry(0,0,516,442);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Login/Login_Interface\")}");
    this->hide();
}

void QLoginUi::setbtn()
{

    this->SureButton = new QMyButton("ȷ��",this);
    this->SureButton->setGeometry(QRect(144,350,125,55));
    connect(this->SureButton, SIGNAL(clicked()),this,SLOT(nextFromslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    this->SureButton->setPix(*p);

    this->CancleButton = new QMyButton("����",this);
    this->CancleButton->setGeometry(QRect(256,350,120,55));
    connect( this->CancleButton, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/Tooltip/Tooltip_RightBtn.png");
    this->CancleButton->setPix(*p);

    this->EyesButton = new QMyButton(this,QString("./Image/CloseEyes.png"));
    this->EyeFlag=NoPlaintext;
    this->EyesButton->setGeometry(QRect(411,225,43,43));
    connect( this->EyesButton, SIGNAL(clicked()),this,SLOT(EyeSlot()) );

    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    this->RegisterBtn = new QMyButton("ע���˺�",this);
    this->RegisterBtn->setGeometry(QRect(50,280,135,60));
    connect( this->RegisterBtn, SIGNAL(clicked()),this,SLOT(regFromslots()));
    p = new QPixmap;
    this->RegisterBtn->setPix(*p);

    this->ChangePWDBtn = new QMyButton("��������",this);
    this->ChangePWDBtn->setGeometry(QRect(195,280,135,60));
    connect( this->ChangePWDBtn, SIGNAL(clicked()),this,SLOT(changePwd()) );
    p = new QPixmap;
    this->ChangePWDBtn->setPix(*p);

    this->GuestsBtn = new QMyButton("�ο͵�¼",this);
    this->GuestsBtn->setGeometry(QRect(340,280,135,60));
    connect( this->GuestsBtn, SIGNAL(clicked()),this,SLOT(playerslots()));
    p = new QPixmap;
    this->GuestsBtn->setPix(*p);
}

void QLoginUi::setedit()
{
    //�༭��
    name = new QMyEdit(this);
    name->setGeometry(190,152,264,43);
    name->setMaxLength(12);
    name->setPlaceholderText(QString("�����������û���"));
    connect(name,SIGNAL(returnPressed()),this,SLOT(namefinishslot()));

    pwd = new QMyEdit(this);
    pwd->setMaxLength(8);
    pwd->setGeometry(190,225,220,43);
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setPlaceholderText(QString("������1-8λ����"));
    connect(pwd,SIGNAL(focusIn(int)),this,SLOT(nameslot()));
    connect(pwd,SIGNAL(returnPressed()),this,SLOT(nextFromslots()));
}


void QLoginUi::nextFromslots()
{
    QMyTip *tip;
    //��֤�û���������
    QSingleTon *single = QSingleTon::GetInstance();
    QDbUserInfo *info = &(single->info);
    if(name->text().isEmpty())
    {
        tip = new QMyTip(this,"�û�������Ϊ��Ŷ��");
        name->setFocus();
        return;
    }
    if(this->pwd->text().isEmpty())
    {
        tip = new QMyTip(this,"���벻��Ϊ��Ŷ��");
        this->pwd->setFocus();
        return;
    }
    if(!info->getPassword(name->text()))
    {
        tip = new QMyTip(this,"�û���������Ŷ!");
        this->pwd->clear();
        name->clear();
        name->setFocus();
        return;
    }
    //���û�������Ϸģʽ ���� ���ص�¼���� �������
    QString pwd(info->qresult[1]);
    if(pwd != this->pwd->text())
    {
        sqlite3_free_table(info->qresult);
        tip = new QMyTip(NULL,"���벻��ȷŶ��");
        this->pwd->clear();
        this->pwd->setFocus();
        return;
    }
    //�û�
    QGame *game;
    game= new QGame(this,name->text());
    this->pwd->clear();
    this->hide();
}

void QLoginUi::playerslots()
{
    QGame *game;
    game= new QGame(this);
    game->show();
    this->hide();
}

void QLoginUi::regFromslots()
{
    this->hide();
    QWindowManger::intence->pRegister->show();
}

void QLoginUi::nameslot()
{
    if(name->text().isEmpty())
    {
        QMyTip *tip;
        tip= new QMyTip(this,"�û�������Ϊ��Ŷ��");
        name->setFocus();
        return;
    }
}

void QLoginUi::namefinishslot()
{
    if(name->text().isEmpty())
    {
        QMyTip *tip;
        tip= new QMyTip(this,"�û�������Ϊ��Ŷ��");
        name->setFocus();
        return;
    }
    else
    {
        pwd->setFocus();
    }
}

 void QLoginUi::EyeSlot()
 {
     if(EyeFlag==Plaintext)
     {
         QPixmap *p = new  QPixmap("./Image/CloseEyes.png");
         this->EyesButton->setPix(*p);
         pwd->setEchoMode(QLineEdit::Password);
         EyeFlag=NoPlaintext;
     }
     else if(EyeFlag==NoPlaintext)
     {
         QPixmap *p = new  QPixmap("./Image/OpenEyes.png");
         this->EyesButton->setPix(*p);
         pwd->setEchoMode(QLineEdit::Normal);
         EyeFlag=Plaintext;
     }
 }

void QLoginUi::changePwd()
{
    this->hide();
    QWindowManger::intence->ChangePassword->show();
}

