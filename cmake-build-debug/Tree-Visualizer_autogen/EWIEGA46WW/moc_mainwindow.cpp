/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_RBButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_AVLButton_clicked"
QT_MOC_LITERAL(4, 53, 19), // "on_DDButton_clicked"
QT_MOC_LITERAL(5, 73, 22), // "on_SplayButton_clicked"
QT_MOC_LITERAL(6, 96, 17), // "on_Insert_clicked"
QT_MOC_LITERAL(7, 114, 21), // "on_InsertSome_clicked"
QT_MOC_LITERAL(8, 136, 29), // "on_InsertSomeLine_textChanged"
QT_MOC_LITERAL(9, 166, 4), // "arg1"
QT_MOC_LITERAL(10, 171, 19), // "on_clickDel_clicked"
QT_MOC_LITERAL(11, 191, 29), // "on_InsertLine_editingFinished"
QT_MOC_LITERAL(12, 221, 22), // "on_containsBtn_clicked"
QT_MOC_LITERAL(13, 244, 12), // "MessageClear"
QT_MOC_LITERAL(14, 257, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 279, 18) // "treeClick_checking"

    },
    "MainWindow\0on_RBButton_clicked\0\0"
    "on_AVLButton_clicked\0on_DDButton_clicked\0"
    "on_SplayButton_clicked\0on_Insert_clicked\0"
    "on_InsertSome_clicked\0"
    "on_InsertSomeLine_textChanged\0arg1\0"
    "on_clickDel_clicked\0on_InsertLine_editingFinished\0"
    "on_containsBtn_clicked\0MessageClear\0"
    "on_pushButton_clicked\0treeClick_checking"
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
       8,    1,   85,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    2,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_RBButton_clicked(); break;
        case 1: _t->on_AVLButton_clicked(); break;
        case 2: _t->on_DDButton_clicked(); break;
        case 3: _t->on_SplayButton_clicked(); break;
        case 4: _t->on_Insert_clicked(); break;
        case 5: _t->on_InsertSome_clicked(); break;
        case 6: _t->on_InsertSomeLine_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_clickDel_clicked(); break;
        case 8: _t->on_InsertLine_editingFinished(); break;
        case 9: _t->on_containsBtn_clicked(); break;
        case 10: _t->MessageClear(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->treeClick_checking((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
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
