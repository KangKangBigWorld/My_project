/****************************************************************************
** Meta object code from reading C++ file 'qmywidget.h'
**
** Created: Sun Feb 23 07:08:27 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qmywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      21,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyWidget[] = {
    "QMyWidget\0\0yesOrno()\0lastFromslots()\0"
};

const QMetaObject QMyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QMyWidget,
      qt_meta_data_QMyWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyWidget))
        return static_cast<void*>(const_cast< QMyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QMyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: yesOrno(); break;
        case 1: lastFromslots(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
