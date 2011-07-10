/****************************************************************************
** Meta object code from reading C++ file 'proxy.h'
**
** Created: Sun 10. Jul 19:57:59 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../proxy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Proxy[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      27,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,    6,    6,    6, 0x08,
      66,    6,    6,    6, 0x08,
      80,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Proxy[] = {
    "Proxy\0\0onInSocketReceive()\0"
    "onOutSocketReceive()\0onNewConnection()\0"
    "onConnected()\0onStateChanged()\0"
};

const QMetaObject Proxy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Proxy,
      qt_meta_data_Proxy, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Proxy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Proxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Proxy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Proxy))
        return static_cast<void*>(const_cast< Proxy*>(this));
    return QObject::qt_metacast(_clname);
}

int Proxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onInSocketReceive(); break;
        case 1: onOutSocketReceive(); break;
        case 2: onNewConnection(); break;
        case 3: onConnected(); break;
        case 4: onStateChanged(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Proxy::onInSocketReceive()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Proxy::onOutSocketReceive()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
