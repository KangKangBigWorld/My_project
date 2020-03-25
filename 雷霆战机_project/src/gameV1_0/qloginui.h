#ifndef QLOGINUI_H
#define QLOGINUI_H

#include "qmywidget.h"
#include "qmyedit.h"
#include "qsingleton.h"
#include "qmytip.h"
#include "qchangepassword.h"
#include "qmyregister.h"

#define EDIT_X_WIN 100
#define EDIT_Y_WIN 60
#define EDIT_DX_WIN 0
#define EDIT_DY_WIN 60
#define EDIT_WIDTH_WIN 200
#define EDIT_HIGH_WIN 50

typedef enum ifPlaintext
{
    NoPlaintext,
    Plaintext
}IFPLAINTEXT;


class QLoginUi : public QMyWidget
{
    Q_OBJECT
public:
    QLoginUi(QMyWidget *parent = 0);
private:
    void setbg();
    void setbtn();
    void setedit();
    QMyWidget *pParent;
    QMyEdit *name;
    QMyEdit *pwd;
    QMyButton* SureButton;
    QMyButton* CancleButton;
    QMyButton* EyesButton;
    QMyButton* RegisterBtn;
    QMyButton* ChangePWDBtn;
    QMyButton* GuestsBtn;
    bool EyeFlag;
signals:

public slots:
    void changePwd();
    //用户
    void nextFromslots();
    //游客
    void playerslots();
    void regFromslots();

    void namefinishslot();
    void nameslot();

    void EyeSlot();
};

#endif // QLOGINUI_H
