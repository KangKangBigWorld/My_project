#include "qwindowmanger.h"
#include "qgame.h"


QLoginUi::QLoginUi(QMyWidget *parent)
{
    //设置上级窗口
    higherWidget = parent;
    this->pParent=parent;
    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    //设置背景
    setbg();

    //设置按键
    setbtn();
    //设置标签
    setedit();
    this->hide();
}

void QLoginUi::setbg()
{
    QLabel *lab;
    //设置窗口自动填充背景（覆盖）
    //this->setAutoFillBackground(true);
    //设置窗口大小
    this->setFixedSize(516,442);
    //设置窗口位置
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,300,516,442);
    //设置窗口标题
    this->setWindowTitle(QString::fromLocal8Bit("雷霆战机"));
    //绘制背景图
    lab = new QLabel(this);
    lab->setGeometry(0,0,516,442);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Login/Login_Interface\")}");
    this->hide();
}

void QLoginUi::setbtn()
{

    this->SureButton = new QMyButton("确认",this);
    this->SureButton->setGeometry(QRect(144,350,125,55));
    connect(this->SureButton, SIGNAL(clicked()),this,SLOT(nextFromslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    this->SureButton->setPix(*p);

    this->CancleButton = new QMyButton("返回",this);
    this->CancleButton->setGeometry(QRect(256,350,120,55));
    connect( this->CancleButton, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/Tooltip/Tooltip_RightBtn.png");
    this->CancleButton->setPix(*p);

    this->EyesButton = new QMyButton(this,QString("./Image/CloseEyes.png"));
    this->EyeFlag=NoPlaintext;
    this->EyesButton->setGeometry(QRect(411,225,43,43));
    connect( this->EyesButton, SIGNAL(clicked()),this,SLOT(EyeSlot()) );

    //设置字体
    QFont fon;
    fon.setFamily("行书");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    this->RegisterBtn = new QMyButton("注册账号",this);
    this->RegisterBtn->setGeometry(QRect(50,280,135,60));
    connect( this->RegisterBtn, SIGNAL(clicked()),this,SLOT(regFromslots()));
    p = new QPixmap;
    this->RegisterBtn->setPix(*p);

    this->ChangePWDBtn = new QMyButton("忘记密码",this);
    this->ChangePWDBtn->setGeometry(QRect(195,280,135,60));
    connect( this->ChangePWDBtn, SIGNAL(clicked()),this,SLOT(changePwd()) );
    p = new QPixmap;
    this->ChangePWDBtn->setPix(*p);

    this->GuestsBtn = new QMyButton("游客登录",this);
    this->GuestsBtn->setGeometry(QRect(340,280,135,60));
    connect( this->GuestsBtn, SIGNAL(clicked()),this,SLOT(playerslots()));
    p = new QPixmap;
    this->GuestsBtn->setPix(*p);
}

void QLoginUi::setedit()
{
    //编辑框
    name = new QMyEdit(this);
    name->setGeometry(190,152,264,43);
    name->setMaxLength(12);
    name->setPlaceholderText(QString("请输入您的用户名"));
    connect(name,SIGNAL(returnPressed()),this,SLOT(namefinishslot()));

    pwd = new QMyEdit(this);
    pwd->setMaxLength(8);
    pwd->setGeometry(190,225,220,43);
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setPlaceholderText(QString("请输入1-8位密码"));
    connect(pwd,SIGNAL(focusIn(int)),this,SLOT(nameslot()));
    connect(pwd,SIGNAL(returnPressed()),this,SLOT(nextFromslots()));
}


void QLoginUi::nextFromslots()
{
    QMyTip *tip;
    //验证用户名和密码
    QSingleTon *single = QSingleTon::GetInstance();
    QDbUserInfo *info = &(single->info);
    if(name->text().isEmpty())
    {
        tip = new QMyTip(this,"用户名不能为空哦！");
        name->setFocus();
        return;
    }
    if(this->pwd->text().isEmpty())
    {
        tip = new QMyTip(this,"密码不能为空哦！");
        this->pwd->setFocus();
        return;
    }
    if(!info->getPassword(name->text()))
    {
        tip = new QMyTip(this,"用户名不存在哦!");
        this->pwd->clear();
        name->clear();
        name->setFocus();
        return;
    }
    //传用户名到游戏模式 构建 隐藏登录窗口 清空密码
    QString pwd(info->qresult[1]);
    if(pwd != this->pwd->text())
    {
        sqlite3_free_table(info->qresult);
        tip = new QMyTip(NULL,"密码不正确哦！");
        this->pwd->clear();
        this->pwd->setFocus();
        return;
    }
    //用户
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
        tip= new QMyTip(this,"用户名不能为空哦！");
        name->setFocus();
        return;
    }
}

void QLoginUi::namefinishslot()
{
    if(name->text().isEmpty())
    {
        QMyTip *tip;
        tip= new QMyTip(this,"用户名不能为空哦！");
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

