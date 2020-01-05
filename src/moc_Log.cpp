/****************************************************************************
** Meta object code from reading C++ file 'Log.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Log.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Log.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log_t {
    QByteArrayData data[13];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log_t qt_meta_stringdata_Log = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Log"
QT_MOC_LITERAL(1, 4, 9), // "lastEntry"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 21), // "QMap<QString,qint32>*"
QT_MOC_LITERAL(4, 37, 7), // "addLine"
QT_MOC_LITERAL(5, 45, 4), // "name"
QT_MOC_LITERAL(6, 50, 11), // "itemClicked"
QT_MOC_LITERAL(7, 62, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 79, 4), // "save"
QT_MOC_LITERAL(9, 84, 4), // "load"
QT_MOC_LITERAL(10, 89, 10), // "addEvalLog"
QT_MOC_LITERAL(11, 100, 14), // "mistakeMessage"
QT_MOC_LITERAL(12, 115, 5) // "clear"

    },
    "Log\0lastEntry\0\0QMap<QString,qint32>*\0"
    "addLine\0name\0itemClicked\0QListWidgetItem*\0"
    "save\0load\0addEvalLog\0mistakeMessage\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void Log::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Log *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lastEntry((*reinterpret_cast< QMap<QString,qint32>*(*)>(_a[1]))); break;
        case 1: _t->addLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->addEvalLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Log::*)(QMap<QString,qint32> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Log::lastEntry)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Log::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Log.data,
    qt_meta_data_Log,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Log::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Log::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Log::lastEntry(QMap<QString,qint32> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
