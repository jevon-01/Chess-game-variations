/****************************************************************************
** Meta object code from reading C++ file 'ChessBoardArray.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ChessBoardArray.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChessBoardArray.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSbackendSCOPESquareENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSbackendSCOPESquareENDCLASS = QtMocHelpers::stringData(
    "backend::Square",
    "isClickedOnVoid",
    "",
    "shared_ptr<Square>",
    "ptrSquare",
    "hasPiece",
    "squareIsEmpty",
    "pieceToMove",
    "checkToEat",
    "checkSquare"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbackendSCOPESquareENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       5,    0,   53,    2, 0x06,    3 /* Public */,
       6,    0,   54,    2, 0x06,    4 /* Public */,
       7,    0,   55,    2, 0x06,    5 /* Public */,
       8,    0,   56,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   57,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject backend::Square::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSbackendSCOPESquareENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbackendSCOPESquareENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbackendSCOPESquareENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Square, std::true_type>,
        // method 'isClickedOnVoid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<shared_ptr<Square>, std::false_type>,
        // method 'hasPiece'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'squareIsEmpty'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pieceToMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkToEat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkSquare'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void backend::Square::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Square *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->isClickedOnVoid((*reinterpret_cast< std::add_pointer_t<shared_ptr<Square>>>(_a[1]))); break;
        case 1: _t->hasPiece(); break;
        case 2: _t->squareIsEmpty(); break;
        case 3: _t->pieceToMove(); break;
        case 4: _t->checkToEat(); break;
        case 5: _t->checkSquare(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Square::*)(shared_ptr<Square> );
            if (_t _q_method = &Square::isClickedOnVoid; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (_t _q_method = &Square::hasPiece; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (_t _q_method = &Square::squareIsEmpty; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (_t _q_method = &Square::pieceToMove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (_t _q_method = &Square::checkToEat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *backend::Square::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *backend::Square::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbackendSCOPESquareENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int backend::Square::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void backend::Square::isClickedOnVoid(shared_ptr<Square> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void backend::Square::hasPiece()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void backend::Square::squareIsEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void backend::Square::pieceToMove()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void backend::Square::checkToEat()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSbackendSCOPEChessBoardArrayENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSbackendSCOPEChessBoardArrayENDCLASS = QtMocHelpers::stringData(
    "backend::ChessBoardArray",
    "signalUncolor",
    "",
    "playerPlayed",
    "movePieceSlot",
    "potential",
    "uncolorSquares",
    "gameModeChanged",
    "index"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbackendSCOPEChessBoardArrayENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    1,   55,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject backend::ChessBoardArray::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSbackendSCOPEChessBoardArrayENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbackendSCOPEChessBoardArrayENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbackendSCOPEChessBoardArrayENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChessBoardArray, std::true_type>,
        // method 'signalUncolor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playerPlayed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movePieceSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'potential'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'uncolorSquares'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void backend::ChessBoardArray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessBoardArray *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalUncolor(); break;
        case 1: _t->playerPlayed(); break;
        case 2: _t->movePieceSlot(); break;
        case 3: _t->potential(); break;
        case 4: _t->uncolorSquares(); break;
        case 5: _t->gameModeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChessBoardArray::*)();
            if (_t _q_method = &ChessBoardArray::signalUncolor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChessBoardArray::*)();
            if (_t _q_method = &ChessBoardArray::playerPlayed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *backend::ChessBoardArray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *backend::ChessBoardArray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbackendSCOPEChessBoardArrayENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int backend::ChessBoardArray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void backend::ChessBoardArray::signalUncolor()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void backend::ChessBoardArray::playerPlayed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
