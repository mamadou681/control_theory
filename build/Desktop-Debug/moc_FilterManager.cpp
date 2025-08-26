/****************************************************************************
** Meta object code from reading C++ file 'FilterManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/FilterManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterManager_t {
    QByteArrayData data[26];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterManager_t qt_meta_stringdata_FilterManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FilterManager"
QT_MOC_LITERAL(1, 14, 18), // "filterModelChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "applyFilter"
QT_MOC_LITERAL(4, 46, 5), // "value"
QT_MOC_LITERAL(5, 52, 4), // "type"
QT_MOC_LITERAL(6, 57, 13), // "getSensorData"
QT_MOC_LITERAL(7, 71, 11), // "resetFilter"
QT_MOC_LITERAL(8, 83, 5), // "param"
QT_MOC_LITERAL(9, 89, 6), // "deltaT"
QT_MOC_LITERAL(10, 96, 8), // "applyEKF"
QT_MOC_LITERAL(11, 105, 13), // "addFilterInfo"
QT_MOC_LITERAL(12, 119, 4), // "name"
QT_MOC_LITERAL(13, 124, 4), // "note"
QT_MOC_LITERAL(14, 129, 10), // "xAxisLabel"
QT_MOC_LITERAL(15, 140, 10), // "yAxisLabel"
QT_MOC_LITERAL(16, 151, 9), // "firstPlot"
QT_MOC_LITERAL(17, 161, 10), // "secondPlot"
QT_MOC_LITERAL(18, 172, 11), // "filterModel"
QT_MOC_LITERAL(19, 184, 19), // "QmlObjectListModel*"
QT_MOC_LITERAL(20, 204, 10), // "filterType"
QT_MOC_LITERAL(21, 215, 17), // "AverageFilterType"
QT_MOC_LITERAL(22, 233, 23), // "MovingAverageFilterType"
QT_MOC_LITERAL(23, 257, 17), // "LowPassFilterType"
QT_MOC_LITERAL(24, 275, 16), // "KalmanFilterType"
QT_MOC_LITERAL(25, 292, 7) // "EKFType"

    },
    "FilterManager\0filterModelChanged\0\0"
    "applyFilter\0value\0type\0getSensorData\0"
    "resetFilter\0param\0deltaT\0applyEKF\0"
    "addFilterInfo\0name\0note\0xAxisLabel\0"
    "yAxisLabel\0firstPlot\0secondPlot\0"
    "filterModel\0QmlObjectListModel*\0"
    "filterType\0AverageFilterType\0"
    "MovingAverageFilterType\0LowPassFilterType\0"
    "KalmanFilterType\0EKFType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   76, // properties
       1,   80, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    2,   45,    2, 0x02 /* Public */,
       6,    1,   50,    2, 0x02 /* Public */,
       7,    3,   53,    2, 0x02 /* Public */,
      10,    0,   60,    2, 0x02 /* Public */,
      11,    7,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Double, QMetaType::Double, QMetaType::Int,    4,    5,
    QMetaType::Double, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,    5,    8,    9,
    QMetaType::QVariantMap,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,    5,   13,   14,   15,   16,   17,

 // properties: name, type, flags
      18, 0x80000000 | 19, 0x00495009,

 // properties: notify_signal_id
       0,

 // enums: name, alias, flags, count, data
      20,   20, 0x0,    5,   85,

 // enum data: key, value
      21, uint(FilterManager::AverageFilterType),
      22, uint(FilterManager::MovingAverageFilterType),
      23, uint(FilterManager::LowPassFilterType),
      24, uint(FilterManager::KalmanFilterType),
      25, uint(FilterManager::EKFType),

       0        // eod
};

void FilterManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterModelChanged(); break;
        case 1: { double _r = _t->applyFilter((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 2: { double _r = _t->getSensorData((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->resetFilter((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 4: { QVariantMap _r = _t->applyEKF();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->addFilterInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilterManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterManager::filterModelChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QmlObjectListModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FilterManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QmlObjectListModel**>(_v) = _t->filterModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FilterManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FilterManager.data,
    qt_meta_data_FilterManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FilterManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FilterManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FilterManager::filterModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
