/****************************************************************************
** Meta object code from reading C++ file 'QCustomplotWrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qcustomplot/QCustomplotWrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCustomplotWrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCustomPlotWrapper_t {
    QByteArrayData data[15];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCustomPlotWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCustomPlotWrapper_t qt_meta_stringdata_QCustomPlotWrapper = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QCustomPlotWrapper"
QT_MOC_LITERAL(1, 19, 14), // "updatePlotSize"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "width"
QT_MOC_LITERAL(4, 41, 6), // "height"
QT_MOC_LITERAL(5, 48, 8), // "addPoint"
QT_MOC_LITERAL(6, 57, 4), // "time"
QT_MOC_LITERAL(7, 62, 6), // "value1"
QT_MOC_LITERAL(8, 69, 6), // "value2"
QT_MOC_LITERAL(9, 76, 10), // "resetGraph"
QT_MOC_LITERAL(10, 87, 10), // "setupGraph"
QT_MOC_LITERAL(11, 98, 10), // "secondPlot"
QT_MOC_LITERAL(12, 109, 6), // "xLabel"
QT_MOC_LITERAL(13, 116, 6), // "yLabel"
QT_MOC_LITERAL(14, 123, 9) // "firstPlot"

    },
    "QCustomPlotWrapper\0updatePlotSize\0\0"
    "width\0height\0addPoint\0time\0value1\0"
    "value2\0resetGraph\0setupGraph\0secondPlot\0"
    "xLabel\0yLabel\0firstPlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCustomPlotWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    3,   39,    2, 0x02 /* Public */,
       9,    0,   46,    2, 0x02 /* Public */,
      10,    4,   47,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // methods: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,

       0        // eod
};

void QCustomPlotWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCustomPlotWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePlotSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->addPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->resetGraph(); break;
        case 3: _t->setupGraph((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCustomPlotWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_QCustomPlotWrapper.data,
    qt_meta_data_QCustomPlotWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCustomPlotWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCustomPlotWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCustomPlotWrapper.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int QCustomPlotWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
