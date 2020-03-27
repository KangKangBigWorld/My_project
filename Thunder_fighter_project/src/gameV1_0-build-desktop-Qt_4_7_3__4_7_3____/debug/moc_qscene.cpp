/****************************************************************************
** Meta object code from reading C++ file 'qscene.h'
**
** Created: Sun Feb 23 08:00:50 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameV1_0/qscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QScene[] = {

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
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      18,    7,    7,    7, 0x0a,
      29,    7,    7,    7, 0x0a,
      38,    7,    7,    7, 0x0a,
      46,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QScene[] = {
    "QScene\0\0gameEnd()\0newEnemy()\0bgMove()\0"
    "start()\0stop()\0"
};

const QMetaObject QScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_QScene,
      qt_meta_data_QScene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QScene))
        return static_cast<void*>(const_cast< QScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int QScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gameEnd(); break;
        case 1: newEnemy(); break;
        case 2: bgMove(); break;
        case 3: start(); break;
        case 4: stop(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QScene::gameEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
