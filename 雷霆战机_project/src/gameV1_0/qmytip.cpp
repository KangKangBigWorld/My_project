#include "qmytip.h"
#include "qwindowmanger.h"
QMyTip::QMyTip(QWidget *parent,QString tip) :
    QWidget(parent)
{

    //初始化变量
    this->label=NULL;
    this->SureButton=NULL;
    this->CancleButton=NULL;
    this->btn=NULL;
    //设置鼠标样式
    //设置鼠标
    QCursor  cursor(QPixmap("./Image/mouse.png"),-2,-2);
    this->setCursor(cursor);

    //去掉标题栏
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //设置模态窗口
    setWindowModality(Qt::WindowModal);

    //设置透明
    //setWindowOpacity(0.5);
    setAttribute(Qt::WA_TranslucentBackground, true);

    resize(300,200);

    //在父窗口居中显示

    this->move(QWindowManger::intence->pStart->x()+(QWindowManger::intence->pStart->width()-this->width())/ 2,
               QWindowManger::intence->pStart->y()+(QWindowManger::intence->pStart->height()-this->height())/ 2);

    //绘制背景图
    btn = new QPushButton(this);
    btn->setGeometry(this->rect());
    btn->setStyleSheet("QPushButton{border-image:url(\"./Image/Tooltip/Tooltip_Str.png\")}");
    connect(btn,SIGNAL(clicked()),this,SLOT(close()));
    setTipInfo(tip);
    parent->show();
    this->show();

    keyClose = true;
}

#include "qmywidget.h"
QMyTip::QMyTip(QWidget *parent,break_mode mode) :
    QWidget(parent)
{
    //初始化变量
    this->label=NULL;
    this->SureButton=NULL;
    this->CancleButton=NULL;
    this->btn=NULL;
    //设置鼠标样式
    this->setWindowTitle("雷霆战机");
    setWindowIcon(QIcon("./Image/Icon/Icon.png"));//图标
    keyClose = false;
    //去掉标题栏
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //设置模态窗口
    setWindowModality(Qt::WindowModal);

    //设置透明
    setAttribute(Qt::WA_TranslucentBackground, true);

    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    resize(300,200);
    //在父窗口居中显示
    this->move(QWindowManger::intence->pStart->x()+(QWindowManger::intence->pStart->width()-this->width())/ 2,
               QWindowManger::intence->pStart->y()+(QWindowManger::intence->pStart->height()-this->height())/ 2);


    //绘制背景图

    label = new QLabel(this);
    label->setGeometry(this->rect());
    switch(mode)
    {
        case EXIT:
            label->setStyleSheet("QLabel{border-image:url(\"./Image/Tooltip/Tooltip_Exit.png\")}");
            break;
        case LOGOUT:
            label->setStyleSheet("QLabel{border-image:url(\"./Image/Tooltip/Tooltip_Logout.png\")}");
            break;
        case RETURN:
            label->setStyleSheet("QLabel{border-image:url(\"./Image/Tooltip/Tooltip_Return.png\")}");
            break;
        default:
            break;
    }

    //设置按键

    this->SureButton = new QMyButton("确认",this);
    this->SureButton->setGeometry(QRect(70,130,90,50));
    connect( this->SureButton, SIGNAL(clicked()),((QMyWidget *)(parent)),SLOT(yesOrno()) );
    connect(this->SureButton,SIGNAL(clicked()),this,SLOT(close()));
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    this->SureButton->setPix(*p);

    this->CancleButton = new QMyButton("返回",this);
    this->CancleButton->setGeometry(QRect(150,130,80,50));
    connect(this->CancleButton,SIGNAL(clicked()),this,SLOT(close()));
    p = new QPixmap("./Image/Tooltip/Tooltip_RightBtn.png");
    this->CancleButton->setPix(*p);

    this->show();
}

void QMyTip::setTipInfo(QString tip)
{
    label = new QLabel(this);
    label->resize(200,85);
    label->move(label->x()+50,label->y()+50);

    //自动换行
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignTop);
    //设置提示信息
    label->setText(tip);

    //设置字号
    QFont ft;
    ft.setPointSize(15);
    label->setFont(ft);

    //设置颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    label->setPalette(pa);
}

void QMyTip::keyPressEvent(QKeyEvent *)
{
    if(keyClose)
    {
        delete this;
    }
}
QMyTip::~QMyTip()
{
    if(this->label!=NULL)delete this->label;
    if(this->SureButton!=NULL)delete this->SureButton;
    if(this->CancleButton!=NULL)delete this->CancleButton;
    if(this->btn!=NULL)delete this->btn;
}
