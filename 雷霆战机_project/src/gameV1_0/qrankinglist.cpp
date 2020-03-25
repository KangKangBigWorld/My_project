#include "qrankinglist.h"
#include <QHeaderView>
#include <string>
QRankingList::QRankingList(QMyWidget *parent)
{
    //设置上级窗口
    higherWidget = parent;

    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    //去掉标题栏
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //设置模态窗口
    setWindowModality(Qt::WindowModal);

    //设置背景图
    QLabel *lab;
    resize(400,600);
    this->setGeometry(higherWidget->x()+(higherWidget->width()-this->width())/2,300,400,600);
    //绘制背景图
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setScaledContents(true);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Rank/RankList.png\")}");

    //设置按键
    QMyButton *btn;
    btn = new QMyButton("",this);
    btn->setGeometry(QRect(40,480,60,60));
    connect( btn, SIGNAL(clicked()),this,SLOT(pageLastslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Rank/Last.png");
    btn->setPix(*p);

    btn = new QMyButton("",this);
    btn->setGeometry(QRect(300,480,60,60));
    connect( btn, SIGNAL(clicked()),this,SLOT(pageNextslots()) );
    p = new QPixmap("./Image/Rank/Next.png");
    btn->setPix(*p);

    btn = new QMyButton("退出",this);
    btn->setGeometry(QRect(110,550,180,40));
    connect( btn, SIGNAL(clicked()),this,SLOT(yesOrno()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);

    //设置初始页面
    pageCur = 1;

    //初始化数据表
    table.setRowCount(7);
    table.setColumnCount(3);

    //设置行宽
    table.setColumnWidth(0,80);
    table.setColumnWidth(1,150);
    table.setColumnWidth(2,80);

    table.setParent(this);
    table.setGeometry(50,260,340,220);
    table.verticalHeader()->setVisible(false); // 隐藏水平header
    table.horizontalHeader()->setVisible(false); // 隐藏水平header
    table.setEnabled(false);
    table.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table.setStyleSheet("QTableWidget{border-radius:1px;background:transparent;color:rgb(255,100,255);font-size:15px;}");

    paintPage();
}

void QRankingList::pageLastslots()
{
    pageCur--;
    if(pageCur >  0)
    {
        paintPage();
        return;
    }
    pageCur = 1;
    QMyTip *tip;
    tip = new QMyTip(this,"已经是第一页了");
}

void QRankingList::pageNextslots()
{
    pageCur++;
    if(paintPage()) return;
    QMyTip *tip;
    tip = new QMyTip(this,"已经是最后一页了");
    pageCur--;
}

bool QRankingList::paintPage()
{
    QSingleTon *single = QSingleTon::GetInstance();
    if (!single->info.rank(7,this->pageCur))
    {
        return false;
    }
    int i = 0;
    QTableWidgetItem *name;
    char ch[6];
    for (; i < single->info.row; i++)
    {
        name=new QTableWidgetItem();//创建一个Item
        sprintf(ch,"%d",((pageCur-1)*7+i+1));
        name->setText(ch);
        table.setItem(i,0,name);

        name=new QTableWidgetItem();//创建一个Item
        name->setText(single->info.qresult[2*i+2]);
        table.setItem(i,1,name);
        name=new QTableWidgetItem();//创建一个Item
        name->setText(single->info.qresult[2*i+3]);
        table.setItem(i,2,name);
    }
    sqlite3_free_table(single->info.qresult);
    return true;
}
