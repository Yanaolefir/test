/****************************************************************************
** Meta object code from reading C++ file 'fault.h'
**
** Created: Wed 4. May 11:03:12 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fault.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fault.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fault[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   24,    6,    6, 0x0a,
      62,   54,    6,    6, 0x0a,
      77,   24,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_fault[] = {
    "fault\0\0right_open(bool)\0filename\0"
    "analys_file(QString)\0number1\0"
    "res_fault(int)\0make_sign(QString)\0"
};

void fault::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        fault *_t = static_cast<fault *>(_o);
        switch (_id) {
        case 0: _t->right_open((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->analys_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->res_fault((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->make_sign((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData fault::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject fault::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_fault,
      qt_meta_data_fault, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fault::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fault::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fault::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fault))
        return static_cast<void*>(const_cast< fault*>(this));
    return QListWidget::qt_metacast(_clname);
}

int fault::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void fault::right_open(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
