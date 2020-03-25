/****************************************************************************
** Meta object code from reading C++ file 'qguide.h'
**
** Created: Sun Feb 23 07:08:39 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qguide.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qguide.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGuide[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,    7,    7,    7, 0x0a,
      30,    7,    7,    7, 0x0a,
      41,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QGuide[] = {
    "QGuide\0\0mySignal()\0pageback()\0pagenext()\0"
    "exitbtn()\0"
};

const QMetaObject QGuide::staticMetaObject = {
    { &QMyWidget::staticMetaObject, qt_meta_stringdata_QGuide,
      qt_meta_data_QGuide, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGuide::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGuide::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGuide::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGuide))
        return static_cast<void*>(const_cast< QGuide*>(this));
    return QMyWidget::qt_metacast(_clname);
}

int QGuide::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mySignal(); break;
        case 1: pageback(); break;
        case 2: pagenext(); break;
        case 3: exitbtn(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QGuide::mySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
