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
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenericTpev_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenericTpev_t qt_meta_stringdata_GenericTpev = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GenericTpev"
QT_MOC_LITERAL(1, 12, 15), // "updateLastEntry"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "clickedEval"
QT_MOC_LITERAL(4, 41, 10), // "clickedLog"
QT_MOC_LITERAL(5, 52, 4), // "name"
QT_MOC_LITERAL(6, 57, 11) // "clickedSlot"

    },
    "GenericTpev\0updateLastEntry\0\0clickedEval\0"
    "clickedLog\0name\0clickedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenericTpev[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

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
        case 0: _t->updateLastEntry(); break;
        case 1: _t->clickedEval(); break;
        case 2: _t->clickedLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->clickedSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GenericTpev::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericTpev::updateLastEntry)) {
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericTpev::clickedLog)) {
                *result = 2;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GenericTpev::updateLastEntry()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GenericTpev::clickedEval()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GenericTpev::clickedLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_Tank_t {
    QByteArrayData data[6];
    char stringdata0[39];
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
QT_MOC_LITERAL(4, 27, 5), // "state"
QT_MOC_LITERAL(5, 33, 5) // "empty"

    },
    "Tank\0clickedSlot\0\0setState\0state\0empty"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tank[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,
    QMetaType::Void,

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
        case 2: _t->empty(); break;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_Pump_t {
    QByteArrayData data[6];
    char stringdata0[43];
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
QT_MOC_LITERAL(4, 27, 5), // "state"
QT_MOC_LITERAL(5, 33, 9) // "setBroken"

    },
    "Pump\0clickedSlot\0\0setState\0state\0"
    "setBroken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pump[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,    4,
    QMetaType::Void,

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
        case 2: _t->setBroken(); break;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_Engine_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine_t qt_meta_stringdata_Engine = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Engine"
QT_MOC_LITERAL(1, 7, 14), // "engineSupplied"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "Engine\0engineSupplied\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Engine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->engineSupplied(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Engine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Engine::engineSupplied)) {
                *result = 0;
                return;
            }
        }
    }
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

// SIGNAL 0
void Engine::engineSupplied()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
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
struct qt_meta_stringdata_ValveTank_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ValveTank_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ValveTank_t qt_meta_stringdata_ValveTank = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ValveTank"
QT_MOC_LITERAL(1, 10, 11), // "clickedSlot"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "ValveTank\0clickedSlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ValveTank[] = {

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

void ValveTank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ValveTank *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ValveTank::staticMetaObject = { {
    &Valve::staticMetaObject,
    qt_meta_stringdata_ValveTank.data,
    qt_meta_data_ValveTank,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ValveTank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ValveTank::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ValveTank.stringdata0))
        return static_cast<void*>(this);
    return Valve::qt_metacast(_clname);
}

int ValveTank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Valve::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ValveEngine_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ValveEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ValveEngine_t qt_meta_stringdata_ValveEngine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ValveEngine"
QT_MOC_LITERAL(1, 12, 11), // "clickedSlot"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "ValveEngine\0clickedSlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ValveEngine[] = {

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

void ValveEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ValveEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ValveEngine::staticMetaObject = { {
    &Valve::staticMetaObject,
    qt_meta_stringdata_ValveEngine.data,
    qt_meta_data_ValveEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ValveEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ValveEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ValveEngine.stringdata0))
        return static_cast<void*>(this);
    return Valve::qt_metacast(_clname);
}

int ValveEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Valve::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
