#include "qmusicbox.h"

#include "qdbuserinfo.h"

QMusicBox::QMusicBox()
{
    QDbUserInfo info;
    this->soundValue = info.volum(SOUNDEFFECT);//ÒôÐ§
    this->volumeValue = info.volum(BACKGROUND);//±³¾°ÒôÀÖ

    sources[BackgroundMusic] = Phonon::MediaSource("./Music/BackgroundMusic.mp3");
    sources[_321] = Phonon::MediaSource("./Music/321.mp3");
    sources[Course01] = Phonon::MediaSource("./Music/Course01.mp3");
    sources[Course02] = Phonon::MediaSource("./Music/Course02.mp3");
    sources[Course03] = Phonon::MediaSource("./Music/Course03.mp3");
    sources[Course04] = Phonon::MediaSource("./Music/Course04.mp3");
    sources[Course05] = Phonon::MediaSource("./Music/Course05.mp3");
    sources[BulletBiuBiuBiu] = Phonon::MediaSource("./Music/BulletBiuBiuBiu.wav");
    sources[ReadyGo] = Phonon::MediaSource("./Music/ReadyGo.mp3");
    sources[Touch] = Phonon::MediaSource("./Music/Touch.mp3");

    //²¥·Å±³¾°ÒôÀÖ
    mediaObject = new Phonon::MediaObject(this);
    mediaObject->setCurrentSource(sources[BackgroundMusic]);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->play();
    connect(mediaObject,SIGNAL(finished()),this,SLOT(playAgain()));//Ñ­»·²¥·Å

    //ÒôÐ§ÊôÐÔÅäÖÃ
    mediaObjectSound = new Phonon::MediaObject(this);
    audioOutputSound = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObjectSound, audioOutputSound);

    //ÉèÖÃÒôÀÖ
    audioOutput->setVolume(volumeValue/100.0);
    audioOutputSound->setVolume(soundValue/100.0);
}

void QMusicBox::playAgain()
{
    mediaObject->setCurrentSource(sources[BackgroundMusic]);
    mediaObject->play();
}

void QMusicBox::playSound(MUISENAME name)
{
    mediaObjectSound->setCurrentSource(sources[name]);
    mediaObjectSound->play();
}

void QMusicBox::setVolume(int value)
{
    audioOutput->setVolume(value/100.0);
    volumeValue = value;
}

void QMusicBox::setSound(int value)
{
    audioOutputSound->setVolume(value/100.0);
    soundValue = value;
}


