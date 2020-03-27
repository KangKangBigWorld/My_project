/****************************************************************************
** Meta object code from reading C++ file 'qstartui.h'
**
** Created: Sun Feb 23 07:08:22 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qstartui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstartui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QStartUi[] = {

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
      10,    9,    9,    9, 0x0a,
      22,    9,    9,    9, 0x0a,
      34,    9,    9,    9, 0x0a,
      46,    9,    9,    9, 0x0a,
      57,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QStartUi[] = {
    "QStartUi\0\0nextslots()\0helpslots()\0"
    "rankslots()\0relslots()\0segslots()\0"
};

const QMetaObject QStartUi::staticMetaObject = {
    { &QMyWidget::staticMetaObject, qt_meta_stringdata_QStartUi,
      qt_meta_data_QStartUi, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QStartUi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QStartUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QStartUi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QStartUi))
        return static_cast<void*>(const_cast< QStartUi*>(this));
    return QMyWidget::qt_metacast(_clname);
}

int QStartUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nextslots(); break;
        case 1: helpslots(); break;
        case 2: rankslots(); break;
        case 3: relslots(); break;
        case 4: segslots(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
