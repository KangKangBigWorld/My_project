#include "qwindowmanger.h"

QChangePassword::QChangePassword(QMyWidget *parent)
{
    //设置上级窗口
    higherWidget = parent;
    pParent = parent;
    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    QLabel *lab;
    //设置窗口大小
    this->setFixedSize(558,652);
    //设置窗口位置
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,205,558,652);
    //绘制背景图
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/ChangePasswd/ChangePasswd.png\")}");

    setedit();
    setbtn();
    this->hide();
}

void QChangePassword::setedit()
{
    //只能数字
    QRegExp regx("[0-9]+$");
    QValidator *validator;

    //编辑框
    name = new QMyEdit(this);
    Question = new QMyEdit(this);
    Answer = new QMyEdit(this);
    pwd = new QMyEdit(this);
    pwdTure = new QMyEdit(this);

    name->setGeometry(208,187,290,43);
    name->setPlaceholderText(QString("请输入用户名"));
    name->setMaxLength(12);
    name->setFocus();
    connect(name,SIGNAL(textChanged(QString)),this,SLOT(nameMatchingslot()));

    Question->setGeometry(207,245,290,43);
    Question->setPlaceholderText(QString("根据用户名匹配"));
    Question->setDisabled(true);//禁止输入

    Answer->setGeometry(207,315,290,43);
    Answer->setPlaceholderText(QString("请先输入用户名"));
    Answer->setMaxLength(12);
    Answer->setDisabled(true);//禁止输入

    pwd->setGeometry(207,390,290,43);
    pwd->setPlaceholderText(QString("请输入8位数字密码"));
    pwd->setMaxLength(8);
    pwd->setDisabled(true);//禁止输入
    validator = new QRegExpValidator(regx, pwd );
    pwd->setValidator( validator );
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setContextMenuPolicy(Qt::NoContextMenu);//右键菜单不存在

    pwdTure->setGeometry(207,469,290,43);
    pwdTure->setPlaceholderText(QString("输入8位数字请密码"));
    pwdTure->setMaxLength(8);
    pwdTure->setDisabled(true);//禁止输入
    validator = new QRegExpValidator(regx, pwdTure );
    pwdTure->setEchoMode(QLineEdit::Password);
    pwdTure->setValidator( validator );
    pwdTure->setContextMenuPolicy(Qt::NoContextMenu);//右键菜单不存在

    connect(name,SIGNAL(returnPressed()),this,SLOT(namefinishslot()));
    connect(Answer,SIGNAL(returnPressed()),this,SLOT(Answerfinishslot()));
    connect(pwd,SIGNAL(returnPressed()),this,SLOT(pwdfinishslot()));
    connect(pwdTure,SIGNAL(returnPressed()),this,SLOT(nextFromslots()));

}

void QChangePassword::setbtn()
{
    QMyButton *btn;
    btn = new QMyButton("确认",this);
    btn->setGeometry(QRect(155,548,140,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(nextFromslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    btn->setPix(*p);

    btn = new QMyButton("返回",this);
    btn->setGeometry(QRect(282,550,130,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/Tooltip/Tooltip_RightBtn.png");
    btn->setPix(*p);
}


void QChangePassword::nameMatchingslot()
{
    QSingleTon *single = QSingleTon::GetInstance();
    if(!single->info.getQuestion(name->text()))
    {
        Question->clear();
        Answer->setDisabled(true);//输入禁止
        pwd->setDisabled(true);//输入禁止
        sqlite3_free_table(single->info.qresult);
        return;
    }
    else
    {
        Answer->setEnabled(true);//输入
        pwd->setEnabled(true);//输入
        Question->setText(single->info.qresult[2]);
    }
}

void QChangePassword::namefinishslot()
{
    if(!Question->text().isEmpty())
    {
        Answer->setFocus();
    }
    else
    {
        QMyTip *tip;
        tip= new QMyTip(this,"用户名未注册");
    }
}

void QChangePassword::Answerfinishslot()
{
    QSingleTon *single = QSingleTon::GetInstance();
    if(Answer->text() == QString(single->info.qresult[3]))
    {
        pwd->setDisabled(false);//输入
        pwd->setFocus();
    }
    else
    {
        QMyTip *tip;
        tip= new QMyTip(this,"答案不正确");
        Answer->clear();
        Answer->setFocus();
    }
}

void QChangePassword::pwdfinishslot()
{
    QMyTip *tip;
    QSingleTon *single = QSingleTon::GetInstance();
    QDbUserInfo *info = &(single->info);
    info->getPassword(name->text());
    QString pwd(info->qresult[1]);
    if(pwd == this->pwd->text())
    {
        sqlite3_free_table(info->qresult);
        tip = new QMyTip(NULL,"新旧密码不能够相同哦！");
        this->pwd->clear();
        this->pwd->setFocus();
        return;
    }
    else if(!this->pwd->text().isEmpty())
    {
        pwdTure->setDisabled(false);//输入
        pwdTure->setFocus();
    }
    else
    {
        QMyTip *widget;
        widget = new QMyTip(this,"答案不能为空哦!");
    }
}

void QChangePassword::nextFromslots()
{
    QMyTip *tip;
    if(Question->text().isEmpty())
    {
        name->setFocus();
        tip = new QMyTip(this,"用户名不存在");
        return;
    }
    QSingleTon *single = QSingleTon::GetInstance();
    if(!(Answer->text() == QString(single->info.qresult[3])))
    {
        QMyTip *tip;
        tip= new QMyTip(this,"答案不正确");
        Answer->clear();
        Answer->setFocus();
        return;
    }
    if(pwd->text().isEmpty())
    {
        pwd->setDisabled(false);//输入
        pwdTure->setDisabled(false);//输入
        pwd->setFocus();
        tip = new QMyTip(this,"密码为空");
        return;
    }
    if(!cmpPwd())
    {
        pwdTure->clear();
        pwdTure->setFocus();
        tip = new QMyTip(this,"密码不一致");
        return;
    }

    sqlite3_free_table(single->info.qresult);
    single->info.changePwd(name->text(),pwd->text());
    tip = new QMyTip(higherWidget,"密码修改完成");

    //higherWidget->show();
    this->hide();
}

bool QChangePassword::cmpPwd()
{
    return (pwd->text() == pwdTure->text());
}
