/****************************************************************************
** Meta object code from reading C++ file 'qsetfrom.h'
**
** Created: Sun Feb 23 07:08:50 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qsetfrom.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsetfrom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSetFrom[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      35,   10,    9,    9, 0x0a,
      58,   53,    9,    9, 0x0a,
      77,   71,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSetFrom[] = {
    "QSetFrom\0\0value\0setEditVolume(int)\0"
    "setEditSound(int)\0hard\0setHard(int)\0"
    "guide\0setGuide(int)\0"
};

const QMetaObject QSetFrom::staticMetaObject = {
    { &QMyWidget::staticMetaObject, qt_meta_stringdata_QSetFrom,
      qt_meta_data_QSetFrom, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSetFrom::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSetFrom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSetFrom::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSetFrom))
        return static_cast<void*>(const_cast< QSetFrom*>(this));
    return QMyWidget::qt_metacast(_clname);
}

int QSetFrom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setEditVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setEditSound((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setHard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setGuide((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
