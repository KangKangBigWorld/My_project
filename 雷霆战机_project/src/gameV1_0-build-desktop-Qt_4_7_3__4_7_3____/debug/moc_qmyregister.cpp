/****************************************************************************
** Meta object code from reading C++ file 'qmyregister.h'
**
** Created: Sun Feb 23 07:08:30 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qmyregister.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmyregister.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyRegister[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      29,   12,   12,   12, 0x0a,
      41,   12,   12,   12, 0x0a,
      60,   12,   12,   12, 0x0a,
      77,   12,   12,   12, 0x0a,
      93,   12,   12,   12, 0x0a,
     113,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyRegister[] = {
    "QMyRegister\0\0nextFromslots()\0nameslots()\0"
    "pwdTureOpenslots()\0namefinishslot()\0"
    "pwdfinishslot()\0pwdTurefinishslot()\0"
    "Answerfinishslot()\0"
};

const QMetaObject QMyRegister::staticMetaObject = {
    { &QMyWidget::staticMetaObject, qt_meta_stringdata_QMyRegister,
      qt_meta_data_QMyRegister, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyRegister::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyRegister))
        return static_cast<void*>(const_cast< QMyRegister*>(this));
    return QMyWidget::qt_metacast(_clname);
}

int QMyRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nextFromslots(); break;
        case 1: nameslots(); break;
        case 2: pwdTureOpenslots(); break;
        case 3: namefinishslot(); break;
        case 4: pwdfinishslot(); break;
        case 5: pwdTurefinishslot(); break;
        case 6: Answerfinishslot(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
