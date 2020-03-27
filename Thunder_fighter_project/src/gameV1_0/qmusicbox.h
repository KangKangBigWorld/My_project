#ifndef QMUSICBOX_H
#define QMUSICBOX_H

#include <QDebug>
#include <phonon>
#include <QObject>

typedef enum musicName
{
    _321,
    Course01,
    Course02,
    Course03,
    Course04,
    Course05,
    BulletBiuBiuBiu,
    ReadyGo,
    Touch,
    BackgroundMusic,
    music_MAX
}MUISENAME;

class QMusicBox :public QObject
{
    Q_OBJECT
public:
    explicit QMusicBox();
    void playSound(MUISENAME name);
    int volume(){return volumeValue;}
    int sound(){return soundValue;}
private:
    //±≥æ∞“Ù¿÷
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *mediaObject;
    //∞¥º¸“Ù–ß
    Phonon::AudioOutput *audioOutputSound;
    Phonon::MediaObject *mediaObjectSound;
    //“Ù¿÷
    Phonon::MediaSource sources[music_MAX];
    //…˘“Ù
    int volumeValue;
    int soundValue;
signals:

public slots:
    //≤•∑≈±≥æ∞“Ù¿÷
    //‘›Õ£±≥æ∞“Ù¿÷
    //≤•∑≈∞¥º¸“Ù–ß
    void playAgain();//—≠ª∑≤•∑≈±≥æ∞“Ù¿÷
    void setVolume(int value);//“Ù¡ø
    void setSound(int value);//“Ù–ß¥Û–°
};

#endif // QMUSICBOX_H
