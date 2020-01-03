/****************************************************************************
** Meta object code from reading C++ file 'affichage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "affichage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'affichage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GenericTpev_t {
    QByteArrayData data[8];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenericTpev_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenericTpev_t qt_meta_stringdata_GenericTpev = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GenericTpev"
QT_MOC_LITERAL(1, 12, 10), // "clickedLog"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "clickedEval"
QT_MOC_LITERAL(4, 36, 12), // "stateChanged"
QT_MOC_LITERAL(5, 49, 4), // "name"
QT_MOC_LITERAL(6, 54, 5), // "state"
QT_MOC_LITERAL(7, 60, 11) // "clickedSlot"

    },
    "GenericTpev\0clickedLog\0\0clickedEval\0"
    "stateChanged\0name\0state\0clickedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenericTpev[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,
       4,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Short,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GenericTpev::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GenericTpev *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedLog(); break;
        case 1: _t->clickedEval(); break;
        case 2: _t->stateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->stateChanged((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 4: _t->clickedSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GenericTpev::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericTpev::clickedLog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GenericTpev::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericTpev::clickedEval)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GenericTpev::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericTpev::stateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GenericTpev::*)(short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericTpev::stateChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GenericTpev::staticMetaObject = { {
    &QAbstractButton::staticMetaObject,
    qt_meta_stringdata_GenericTpev.data,
    qt_meta_data_GenericTpev,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GenericTpev::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenericTpev::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GenericTpev.stringdata0))
        return static_cast<void*>(this);
    return QAbstractButton::qt_metacast(_clname);
}

int GenericTpev::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GenericTpev::clickedLog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GenericTpev::clickedEval()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GenericTpev::stateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GenericTpev::stateChanged(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_Tank_t {
    QByteArrayData data[5];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tank_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tank_t qt_meta_stringdata_Tank = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Tank"
QT_MOC_LITERAL(1, 5, 11), // "clickedSlot"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "setState"
QT_MOC_LITERAL(4, 27, 5) // "state"

    },
    "Tank\0clickedSlot\0\0setState\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tank[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,

       0        // eod
};

void Tank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tank *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSlot(); break;
        case 1: _t->setState((*reinterpret_cast< short(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tank::staticMetaObject = { {
    &GenericTpev::staticMetaObject,
    qt_meta_stringdata_Tank.data,
    qt_meta_data_Tank,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tank::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tank.stringdata0))
        return static_cast<void*>(this);
    return GenericTpev::qt_metacast(_clname);
}

int Tank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericTpev::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_Pump_t {
    QByteArrayData data[5];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pump_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pump_t qt_meta_stringdata_Pump = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Pump"
QT_MOC_LITERAL(1, 5, 11), // "clickedSlot"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "setState"
QT_MOC_LITERAL(4, 27, 5) // "state"

    },
    "Pump\0clickedSlot\0\0setState\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pump[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,

       0        // eod
};

void Pump::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pump *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSlot(); break;
        case 1: _t->setState((*reinterpret_cast< short(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Pump::staticMetaObject = { {
    &GenericTpev::staticMetaObject,
    qt_meta_stringdata_Pump.data,
    qt_meta_data_Pump,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Pump::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pump::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pump.stringdata0))
        return static_cast<void*>(this);
    return GenericTpev::qt_metacast(_clname);
}

int Pump::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericTpev::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_Engine_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine_t qt_meta_stringdata_Engine = {
    {
QT_MOC_LITERAL(0, 0, 6) // "Engine"

    },
    "Engine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine[] = {

 // content:
       8,       // revision
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

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Engine::staticMetaObject = { {
    &GenericTpev::staticMetaObject,
    qt_meta_stringdata_Engine.data,
    qt_meta_data_Engine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Engine.stringdata0))
        return static_cast<void*>(this);
    return GenericTpev::qt_metacast(_clname);
}

int Engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericTpev::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Valve_t {
    QByteArrayData data[3];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Valve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Valve_t qt_meta_stringdata_Valve = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Valve"
QT_MOC_LITERAL(1, 6, 11), // "clickedSlot"
QT_MOC_LITERAL(2, 18, 0) // ""

    },
    "Valve\0clickedSlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Valve[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Valve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Valve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Valve::staticMetaObject = { {
    &GenericTpev::staticMetaObject,
    qt_meta_stringdata_Valve.data,
    qt_meta_data_Valve,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Valve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Valve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Valve.stringdata0))
        return static_cast<void*>(this);
    return GenericTpev::qt_metacast(_clname);
}

int Valve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericTpev::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[7];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "saveSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "loadSignal"
QT_MOC_LITERAL(4, 34, 7), // "saveLog"
QT_MOC_LITERAL(5, 42, 7), // "loadLog"
QT_MOC_LITERAL(6, 50, 17) // "accountConnection"

    },
    "MainWindow\0saveSignal\0\0loadSignal\0"
    "saveLog\0loadLog\0accountConnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   45,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loadSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->saveLog(); break;
        case 3: _t->loadLog(); break;
        case 4: _t->accountConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::saveSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::loadSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::saveSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::loadSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
