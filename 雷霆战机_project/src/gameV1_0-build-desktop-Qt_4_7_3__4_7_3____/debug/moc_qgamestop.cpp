/****************************************************************************
** Meta object code from reading C++ file 'qgamestop.h'
**
** Created: Sun Feb 23 07:08:47 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qgamestop.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgamestop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGameStop[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   10,   10,   10, 0x0a,
      35,   10,   10,   10, 0x0a,
      44,   10,   10,   10, 0x0a,
      55,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QGameStop[] = {
    "QGameStop\0\0mySignal(int)\0gameSet()\0"
    "reGame()\0exitGame()\0gameStart()\0"
};

const QMetaObject QGameStop::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QGameStop,
      qt_meta_data_QGameStop, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGameStop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGameStop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGameStop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGameStop))
        return static_cast<void*>(const_cast< QGameStop*>(this));
    return QWidget::qt_metacast(_clname);
}

int QGameStop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mySignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: gameSet(); break;
        case 2: reGame(); break;
        case 3: exitGame(); break;
        case 4: gameStart(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QGameStop::mySignal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
