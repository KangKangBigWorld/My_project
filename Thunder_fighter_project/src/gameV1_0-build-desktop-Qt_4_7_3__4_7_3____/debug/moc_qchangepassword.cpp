/****************************************************************************
** Meta object code from reading C++ file 'qchangepassword.h'
**
** Created: Sun Feb 23 07:08:44 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qchangepassword.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qchangepassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QChangePassword[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      33,   16,   16,   16, 0x0a,
      52,   16,   16,   16, 0x0a,
      68,   16,   16,   16, 0x0a,
      85,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QChangePassword[] = {
    "QChangePassword\0\0nextFromslots()\0"
    "nameMatchingslot()\0pwdfinishslot()\0"
    "namefinishslot()\0Answerfinishslot()\0"
};

const QMetaObject QChangePassword::staticMetaObject = {
    { &QMyWidget::staticMetaObject, qt_meta_stringdata_QChangePassword,
      qt_meta_data_QChangePassword, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QChangePassword::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QChangePassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QChangePassword::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QChangePassword))
        return static_cast<void*>(const_cast< QChangePassword*>(this));
    return QMyWidget::qt_metacast(_clname);
}

int QChangePassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nextFromslots(); break;
        case 1: nameMatchingslot(); break;
        case 2: pwdfinishslot(); break;
        case 3: namefinishslot(); break;
        case 4: Answerfinishslot(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
