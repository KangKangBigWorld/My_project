/****************************************************************************
** Meta object code from reading C++ file 'qabout.h'
**
** Created: Sun Feb 23 07:08:46 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qabout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QAbout[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QAbout[] = {
    "QAbout\0"
};

const QMetaObject QAbout::staticMetaObject = {
    { &QMyWidget::staticMetaObject, qt_meta_stringdata_QAbout,
      qt_meta_data_QAbout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QAbout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QAbout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QAbout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QAbout))
        return static_cast<void*>(const_cast< QAbout*>(this));
    return QMyWidget::qt_metacast(_clname);
}

int QAbout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
