/****************************************************************************
** Meta object code from reading C++ file 'qmusicbox.h'
**
** Created: Sun Feb 23 07:08:34 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qmusicbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmusicbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMusicBox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      29,   23,   10,   10, 0x0a,
      44,   23,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMusicBox[] = {
    "QMusicBox\0\0playAgain()\0value\0"
    "setVolume(int)\0setSound(int)\0"
};

const QMetaObject QMusicBox::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMusicBox,
      qt_meta_data_QMusicBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMusicBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMusicBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMusicBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMusicBox))
        return static_cast<void*>(const_cast< QMusicBox*>(this));
    return QObject::qt_metacast(_clname);
}

int QMusicBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: playAgain(); break;
        case 1: setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setSound((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
