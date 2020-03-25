/****************************************************************************
** Meta object code from reading C++ file 'qmyedit.h'
**
** Created: Sun Feb 23 07:08:31 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qmyedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmyedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      23,    8,    8,    8, 0x05,
      36,    8,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QMyEdit[] = {
    "QMyEdit\0\0focusOut(int)\0focusIn(int)\0"
    "lineEditEmptySignal()\0"
};

const QMetaObject QMyEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_QMyEdit,
      qt_meta_data_QMyEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyEdit))
        return static_cast<void*>(const_cast< QMyEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int QMyEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: focusOut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: focusIn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: lineEditEmptySignal(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QMyEdit::focusOut(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMyEdit::focusIn(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMyEdit::lineEditEmptySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
