#include "qwindowmanger.h"

QChangePassword::QChangePassword(QMyWidget *parent)
{
    //�����ϼ�����
    higherWidget = parent;
    pParent = parent;
    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    QLabel *lab;
    //���ô��ڴ�С
    this->setFixedSize(558,652);
    //���ô���λ��
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,205,558,652);
    //���Ʊ���ͼ
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/ChangePasswd/ChangePasswd.png\")}");

    setedit();
    setbtn();
    this->hide();
}

void QChangePassword::setedit()
{
    //ֻ������
    QRegExp regx("[0-9]+$");
    QValidator *validator;

    //�༭��
    name = new QMyEdit(this);
    Question = new QMyEdit(this);
    Answer = new QMyEdit(this);
    pwd = new QMyEdit(this);
    pwdTure = new QMyEdit(this);

    name->setGeometry(208,187,290,43);
    name->setPlaceholderText(QString("�������û���"));
    name->setMaxLength(12);
    name->setFocus();
    connect(name,SIGNAL(textChanged(QString)),this,SLOT(nameMatchingslot()));

    Question->setGeometry(207,245,290,43);
    Question->setPlaceholderText(QString("�����û���ƥ��"));
    Question->setDisabled(true);//��ֹ����

    Answer->setGeometry(207,315,290,43);
    Answer->setPlaceholderText(QString("���������û���"));
    Answer->setMaxLength(12);
    Answer->setDisabled(true);//��ֹ����

    pwd->setGeometry(207,390,290,43);
    pwd->setPlaceholderText(QString("������8λ��������"));
    pwd->setMaxLength(8);
    pwd->setDisabled(true);//��ֹ����
    validator = new QRegExpValidator(regx, pwd );
    pwd->setValidator( validator );
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setContextMenuPolicy(Qt::NoContextMenu);//�Ҽ��˵�������

    pwdTure->setGeometry(207,469,290,43);
    pwdTure->setPlaceholderText(QString("����8λ����������"));
    pwdTure->setMaxLength(8);
    pwdTure->setDisabled(true);//��ֹ����
    validator = new QRegExpValidator(regx, pwdTure );
    pwdTure->setEchoMode(QLineEdit::Password);
    pwdTure->setValidator( validator );
    pwdTure->setContextMenuPolicy(Qt::NoContextMenu);//�Ҽ��˵�������

    connect(name,SIGNAL(returnPressed()),this,SLOT(namefinishslot()));
    connect(Answer,SIGNAL(returnPressed()),this,SLOT(Answerfinishslot()));
    connect(pwd,SIGNAL(returnPressed()),this,SLOT(pwdfinishslot()));
    connect(pwdTure,SIGNAL(returnPressed()),this,SLOT(nextFromslots()));

}

void QChangePassword::setbtn()
{
    QMyButton *btn;
    btn = new QMyButton("ȷ��",this);
    btn->setGeometry(QRect(155,548,140,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(nextFromslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    btn->setPix(*p);

    btn = new QMyButton("����",this);
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
        Answer->setDisabled(true);//�����ֹ
        pwd->setDisabled(true);//�����ֹ
        sqlite3_free_table(single->info.qresult);
        return;
    }
    else
    {
        Answer->setEnabled(true);//����
        pwd->setEnabled(true);//����
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
        tip= new QMyTip(this,"�û���δע��");
    }
}

void QChangePassword::Answerfinishslot()
{
    QSingleTon *single = QSingleTon::GetInstance();
    if(Answer->text() == QString(single->info.qresult[3]))
    {
        pwd->setDisabled(false);//����
        pwd->setFocus();
    }
    else
    {
        QMyTip *tip;
        tip= new QMyTip(this,"�𰸲���ȷ");
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
        tip = new QMyTip(NULL,"�¾����벻�ܹ���ͬŶ��");
        this->pwd->clear();
        this->pwd->setFocus();
        return;
    }
    else if(!this->pwd->text().isEmpty())
    {
        pwdTure->setDisabled(false);//����
        pwdTure->setFocus();
    }
    else
    {
        QMyTip *widget;
        widget = new QMyTip(this,"�𰸲���Ϊ��Ŷ!");
    }
}

void QChangePassword::nextFromslots()
{
    QMyTip *tip;
    if(Question->text().isEmpty())
    {
        name->setFocus();
        tip = new QMyTip(this,"�û���������");
        return;
    }
    QSingleTon *single = QSingleTon::GetInstance();
    if(!(Answer->text() == QString(single->info.qresult[3])))
    {
        QMyTip *tip;
        tip= new QMyTip(this,"�𰸲���ȷ");
        Answer->clear();
        Answer->setFocus();
        return;
    }
    if(pwd->text().isEmpty())
    {
        pwd->setDisabled(false);//����
        pwdTure->setDisabled(false);//����
        pwd->setFocus();
        tip = new QMyTip(this,"����Ϊ��");
        return;
    }
    if(!cmpPwd())
    {
        pwdTure->clear();
        pwdTure->setFocus();
        tip = new QMyTip(this,"���벻һ��");
        return;
    }

    sqlite3_free_table(single->info.qresult);
    single->info.changePwd(name->text(),pwd->text());
    tip = new QMyTip(higherWidget,"�����޸����");

    //higherWidget->show();
    this->hide();
}

bool QChangePassword::cmpPwd()
{
    return (pwd->text() == pwdTure->text());
}
