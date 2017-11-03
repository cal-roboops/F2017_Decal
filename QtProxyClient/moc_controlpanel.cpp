/****************************************************************************
** Meta object code from reading C++ file 'controlpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controlpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControlPanel_t {
    QByteArrayData data[16];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlPanel_t qt_meta_stringdata_ControlPanel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ControlPanel"
QT_MOC_LITERAL(1, 13, 21), // "on_button_set_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "on_pushButton_up_pressed"
QT_MOC_LITERAL(4, 61, 25), // "on_pushButton_up_released"
QT_MOC_LITERAL(5, 87, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(6, 110, 27), // "on_radioButton_tank_clicked"
QT_MOC_LITERAL(7, 138, 29), // "on_radioButton_custom_clicked"
QT_MOC_LITERAL(8, 168, 17), // "on_radio0_clicked"
QT_MOC_LITERAL(9, 186, 18), // "on_radio45_clicked"
QT_MOC_LITERAL(10, 205, 18), // "on_radio90_clicked"
QT_MOC_LITERAL(11, 224, 18), // "on_tank_up_clicked"
QT_MOC_LITERAL(12, 243, 20), // "on_tank_down_clicked"
QT_MOC_LITERAL(13, 264, 13), // "keyPressEvent"
QT_MOC_LITERAL(14, 278, 10), // "QKeyEvent*"
QT_MOC_LITERAL(15, 289, 5) // "event"

    },
    "ControlPanel\0on_button_set_clicked\0\0"
    "on_pushButton_up_pressed\0"
    "on_pushButton_up_released\0"
    "on_radioButton_clicked\0"
    "on_radioButton_tank_clicked\0"
    "on_radioButton_custom_clicked\0"
    "on_radio0_clicked\0on_radio45_clicked\0"
    "on_radio90_clicked\0on_tank_up_clicked\0"
    "on_tank_down_clicked\0keyPressEvent\0"
    "QKeyEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlPanel *_t = static_cast<ControlPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_button_set_clicked(); break;
        case 1: _t->on_pushButton_up_pressed(); break;
        case 2: _t->on_pushButton_up_released(); break;
        case 3: _t->on_radioButton_clicked(); break;
        case 4: _t->on_radioButton_tank_clicked(); break;
        case 5: _t->on_radioButton_custom_clicked(); break;
        case 6: _t->on_radio0_clicked(); break;
        case 7: _t->on_radio45_clicked(); break;
        case 8: _t->on_radio90_clicked(); break;
        case 9: _t->on_tank_up_clicked(); break;
        case 10: _t->on_tank_down_clicked(); break;
        case 11: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ControlPanel::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ControlPanel.data,
      qt_meta_data_ControlPanel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel.stringdata0))
        return static_cast<void*>(const_cast< ControlPanel*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
