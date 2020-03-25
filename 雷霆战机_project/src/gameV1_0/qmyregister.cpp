#include "qwindowmanger.h"

QMyRegister::QMyRegister(QMyWidget *parent)
{
    //设置上级窗口
    higherWidget = parent;
    pParent = parent;
    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    //设置背景
    setbg();

    //设置按键
    setbtn();
    //设置标签
    setedit();
    this->hide();
}

void QMyRegister::setbg()
{
    QLabel *lab;
    //设置窗口自动填充背景（覆盖）
     //this->setAutoFillBackground(true);
    //设置窗口大小
    this->setFixedSize(576,652);
    //设置窗口位置
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,205,576,652);
    //设置窗口标题
    this->setWindowTitle(QString::fromLocal8Bit("雷霆战机"));
    //绘制背景图
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Register/Register_Interface.png\")}");
}

void QMyRegister::setbtn()
{
    QMyButton *btn;

    btn = new QMyButton("确认",this);
    btn->setGeometry(QRect(160,548,140,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(nextFromslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    btn->setPix(*p);

    btn = new QMyButton("返回",this);
    btn->setGeometry(QRect(287,550,130,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/Tooltip/Tooltip_RightBtn.png");
    btn->setPix(*p);

    //设置字体
    QFont fon;
    fon.setFamily("行书");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);
}
/*
enum mode
{
    请输入用户名
    用户名注册
    请输入密码
    请确认密码
    答案不能为空
};*/

void QMyRegister::setedit()
{
    //只能数字
    QRegExp regx("[0-9]+$");
    QValidator *validator;

    //编辑框
    name = new QMyEdit(this);
    name->setGeometry(208,187,290,43);
    name->setMaxLength(12);
    name->setPlaceholderText(QString("请输入用户名"));

    pwd = new QMyEdit(this);
    pwd->setMaxLength(8);
    pwd->setGeometry(208,253,290,43);
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setPlaceholderText(QString("请输入8位数字密码"));
    validator = new QRegExpValidator(regx, pwd );
    pwd->setValidator( validator );
    pwd->setContextMenuPolicy(Qt::NoContextMenu);//右键菜单不存在
    connect(pwd,SIGNAL(focusIn(int)),this,SLOT(nameslots()));
    connect(pwd,SIGNAL(textChanged(QString)),this,SLOT(pwdTureOpenslots()));

    pwdTure = new QMyEdit(this);
    pwdTure->setMaxLength(8);
    pwdTure->setGeometry(208,330,290,43);
    pwdTure->setEchoMode(QLineEdit::Password);
    pwdTure->setPlaceholderText(QString("请确认密码"));
    validator = new QRegExpValidator(regx, pwdTure );
    pwdTure->setValidator( validator );
    pwdTure->setDisabled(true);//禁止输入
    pwdTure->setContextMenuPolicy(Qt::NoContextMenu);//右键菜单不存在


    //设置编辑
        this->Question=new QComboBox(this);
        this->Question->setGeometry(208,397,290,43);
        this->Question->addItem("您的电话号码是？",0);
        this->Question->addItem("您母亲的电话号码是？",1);
        this->Question->addItem("您父亲的电话号码是？",2);
        this->Question->setItemText(0,QString::fromLocal8Bit("您的电话号码是？"));
        this->Question->setItemText(1,QString::fromLocal8Bit("您母亲的电话号码是？"));
        this->Question->setItemText(2,QString::fromLocal8Bit("您父亲的电话号码是？"));
        this->Question->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
        this->Question->setFont(QFont("KaiTi_GB2312",15, QFont::Bold));
    Answer = new QMyEdit(this);
    Answer->setMaxLength(12);
    Answer->setGeometry(208,465,290,43);
    Answer->setPlaceholderText(QString("请输入您的答案"));
    name->setFocus();

    connect(name,SIGNAL(returnPressed()),this,SLOT(namefinishslot()));
    connect(pwd,SIGNAL(returnPressed()),this,SLOT(pwdfinishslot()));
    connect(pwdTure,SIGNAL(returnPressed()),this,SLOT(pwdTurefinishslot()));
    connect(Answer,SIGNAL(returnPressed()),this,SLOT(Answerfinishslot()));
}

void QMyRegister::nextFromslots()
{
    QWidget *widget;
    if(name->text().isEmpty())
    {
        widget = new QMyTip(this,"用户名不能为空哦!");
        name->setFocus();
        return;
    }
    if(pwdTure->text().isEmpty())
    {
        if(pwd->text().isEmpty())
        {
            widget = new QMyTip(this,"密码不能为空哦!");
            pwd->setFocus();
            return;
        }
        widget = new QMyTip(this,"请确认密码哦!");
        pwdTure->setFocus();
        return;
    }
    if(pwdTure->text() != pwd->text())
    {
        widget = new QMyTip(this,"请输入相同密码哦!");
        pwdTure->clear();
        pwd->clear();
        pwd->setFocus();
        return;
    }
    if(Answer->text().isEmpty())
    {
        widget = new QMyTip(this,"答案不能为空哦!");
        Answer->setFocus();
        return;
    }

    QSingleTon *single = QSingleTon::GetInstance();
    single->info.saveUserinfo(name->text(),pwd->text(),Question->currentText(),Answer->text());
    QString str("注册成功用户:");
    str = str + name->text();
    widget = new QMyTip(higherWidget,str);

    this->hide();
}

void QMyRegister::nameslots()
{
    QWidget *widget;
    if(name->text().isEmpty())
    {
        widget = new QMyTip(this,"用户名不能为空哦!");
        //焦点位置
        name->setFocus();
        return;
    }
    QSingleTon *single = QSingleTon::GetInstance();
    if(single->info.getQuestion(name->text()))
    {
        widget = new QMyTip(this,"用户名已经注册哦!");
        //焦点  用户名清空
        name->clear();
        name->setFocus();
        return;
    }
}

void QMyRegister::pwdTureOpenslots()
{
    if(pwd->text().isEmpty())
    {
        pwdTure->setDisabled(true);//禁止输入
    }
    else
    {
        pwdTure->setDisabled(false);//允许输入
    }

}

void QMyRegister::namefinishslot()
{
    pwd->setFocus();
}

void QMyRegister::pwdfinishslot()
{
    if(!pwd->text().isEmpty())
    {
        pwdTure->setFocus();
    }
    else
    {
        QMyTip *widget;
        widget = new QMyTip(this,"密码不能为空哦!");
    }
}

void QMyRegister::pwdTurefinishslot()
{
    Answer->setFocus();
}
void QMyRegister::Answerfinishslot()
{
    nextFromslots();
}


