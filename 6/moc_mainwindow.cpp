/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[426];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_actionClearLeft_triggered"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 29), // "on_actionClearRight_triggered"
QT_MOC_LITERAL(4, 71, 27), // "on_actionClearAll_triggered"
QT_MOC_LITERAL(5, 99, 30), // "on_actionReverseLeft_triggered"
QT_MOC_LITERAL(6, 130, 31), // "on_actionReverseRight_triggered"
QT_MOC_LITERAL(7, 162, 29), // "on_actionReverseAll_triggered"
QT_MOC_LITERAL(8, 192, 34), // "on_actionCopyLeftToRight_trig..."
QT_MOC_LITERAL(9, 227, 34), // "on_actionCopyRightToLeft_trig..."
QT_MOC_LITERAL(10, 262, 34), // "on_actionMoveLeftToRight_trig..."
QT_MOC_LITERAL(11, 297, 34), // "on_actionMoveRightToLeft_trig..."
QT_MOC_LITERAL(12, 332, 23), // "on_actionSwap_triggered"
QT_MOC_LITERAL(13, 356, 34), // "on_actionConcatLeftRight_trig..."
QT_MOC_LITERAL(14, 391, 34) // "on_actionConcatRightLeft_trig..."

    },
    "MainWindow\0on_actionClearLeft_triggered\0"
    "\0on_actionClearRight_triggered\0"
    "on_actionClearAll_triggered\0"
    "on_actionReverseLeft_triggered\0"
    "on_actionReverseRight_triggered\0"
    "on_actionReverseAll_triggered\0"
    "on_actionCopyLeftToRight_triggered\0"
    "on_actionCopyRightToLeft_triggered\0"
    "on_actionMoveLeftToRight_triggered\0"
    "on_actionMoveRightToLeft_triggered\0"
    "on_actionSwap_triggered\0"
    "on_actionConcatLeftRight_triggered\0"
    "on_actionConcatRightLeft_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionClearLeft_triggered(); break;
        case 1: _t->on_actionClearRight_triggered(); break;
        case 2: _t->on_actionClearAll_triggered(); break;
        case 3: _t->on_actionReverseLeft_triggered(); break;
        case 4: _t->on_actionReverseRight_triggered(); break;
        case 5: _t->on_actionReverseAll_triggered(); break;
        case 6: _t->on_actionCopyLeftToRight_triggered(); break;
        case 7: _t->on_actionCopyRightToLeft_triggered(); break;
        case 8: _t->on_actionMoveLeftToRight_triggered(); break;
        case 9: _t->on_actionMoveRightToLeft_triggered(); break;
        case 10: _t->on_actionSwap_triggered(); break;
        case 11: _t->on_actionConcatLeftRight_triggered(); break;
        case 12: _t->on_actionConcatRightLeft_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
