/****************************************************************************
** Meta object code from reading C++ file 'FilterInfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/FilterInfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterInfo_t {
    QByteArrayData data[16];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterInfo_t qt_meta_stringdata_FilterInfo = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FilterInfo"
QT_MOC_LITERAL(1, 11, 11), // "nameChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "xAxisLabelChanged"
QT_MOC_LITERAL(4, 42, 17), // "yAxisLabelChanged"
QT_MOC_LITERAL(5, 60, 11), // "typeChanged"
QT_MOC_LITERAL(6, 72, 11), // "noteChanged"
QT_MOC_LITERAL(7, 84, 16), // "firstPlotChanged"
QT_MOC_LITERAL(8, 101, 17), // "secondPlotChanged"
QT_MOC_LITERAL(9, 119, 4), // "name"
QT_MOC_LITERAL(10, 124, 10), // "xAxisLabel"
QT_MOC_LITERAL(11, 135, 10), // "yAxisLabel"
QT_MOC_LITERAL(12, 146, 4), // "type"
QT_MOC_LITERAL(13, 151, 4), // "note"
QT_MOC_LITERAL(14, 156, 9), // "firstPlot"
QT_MOC_LITERAL(15, 166, 10) // "secondPlot"

    },
    "FilterInfo\0nameChanged\0\0xAxisLabelChanged\0"
    "yAxisLabelChanged\0typeChanged\0noteChanged\0"
    "firstPlotChanged\0secondPlotChanged\0"
    "name\0xAxisLabel\0yAxisLabel\0type\0note\0"
    "firstPlot\0secondPlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       7,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::Int, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

void FilterInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->xAxisLabelChanged(); break;
        case 2: _t->yAxisLabelChanged(); break;
        case 3: _t->typeChanged(); break;
        case 4: _t->noteChanged(); break;
        case 5: _t->firstPlotChanged(); break;
        case 6: _t->secondPlotChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::xAxisLabelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::yAxisLabelChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::typeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::noteChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::firstPlotChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FilterInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterInfo::secondPlotChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FilterInfo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->xAxisLabel(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->yAxisLabel(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->type(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->note(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->firstPlot(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->secondPlot(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FilterInfo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setXAxisLabel(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setYAxisLabel(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setType(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setNote(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setFirstPlot(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setSecondPlot(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FilterInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FilterInfo.data,
    qt_meta_data_FilterInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterInfo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FilterInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FilterInfo::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FilterInfo::xAxisLabelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FilterInfo::yAxisLabelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FilterInfo::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FilterInfo::noteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FilterInfo::firstPlotChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FilterInfo::secondPlotChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
