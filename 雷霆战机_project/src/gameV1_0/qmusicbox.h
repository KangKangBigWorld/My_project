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
    //��������
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *mediaObject;
    //������Ч
    Phonon::AudioOutput *audioOutputSound;
    Phonon::MediaObject *mediaObjectSound;
    //����
    Phonon::MediaSource sources[music_MAX];
    //����
    int volumeValue;
    int soundValue;
signals:

public slots:
    //���ű�������
    //��ͣ��������
    //���Ű�����Ч
    void playAgain();//ѭ�����ű�������
    void setVolume(int value);//����
    void setSound(int value);//��Ч��С
};

#endif // QMUSICBOX_H
