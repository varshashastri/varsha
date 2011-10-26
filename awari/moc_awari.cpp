/****************************************************************************
** awari meta object code from reading C++ file 'awari.h'
**
** Created: Wed Oct 26 19:55:25 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "awari.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *awari::className() const
{
    return "awari";
}

QMetaObject *awari::metaObj = 0;
static QMetaObjectCleanUp cleanUp_awari( "awari", &awari::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString awari::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "awari", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString awari::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "awari", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* awari::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWizard::staticMetaObject();
    static const QUMethod slot_0 = {"reset", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "iter", &static_QUType_ptr, "QValueList<int>::iterator", QUParameter::In },
	{ "cnt", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"takeopp", 2, param_slot_1 };
    static const QUMethod slot_2 = {"display", 0, 0 };
    static const QUMethod slot_3 = {"p1_clicked", 0, 0 };
    static const QUMethod slot_4 = {"p2_clicked", 0, 0 };
    static const QUMethod slot_5 = {"p3_clicked", 0, 0 };
    static const QUMethod slot_6 = {"p4_clicked", 0, 0 };
    static const QUMethod slot_7 = {"p5_clicked", 0, 0 };
    static const QUMethod slot_8 = {"movec5", 0, 0 };
    static const QUMethod slot_9 = {"movec4", 0, 0 };
    static const QUMethod slot_10 = {"movec3", 0, 0 };
    static const QUMethod slot_11 = {"movec2", 0, 0 };
    static const QUMethod slot_12 = {"movec1", 0, 0 };
    static const QUMethod slot_13 = {"movecomp", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ "q", &static_QUType_ptr, "QValueList<int>::iterator", QUParameter::In }
    };
    static const QUMethod slot_14 = {"movecomp", 1, param_slot_14 };
    static const QUMethod slot_15 = {"checkwin", 0, 0 };
    static const QUMethod slot_16 = {"comp1st_clicked", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"spinBox_valueChanged", 1, param_slot_17 };
    static const QUMethod slot_18 = {"ok_clicked", 0, 0 };
    static const QUMethod slot_19 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reset()", &slot_0, QMetaData::Public },
	{ "takeopp(QValueList<int>::iterator,int)", &slot_1, QMetaData::Public },
	{ "display()", &slot_2, QMetaData::Public },
	{ "p1_clicked()", &slot_3, QMetaData::Public },
	{ "p2_clicked()", &slot_4, QMetaData::Public },
	{ "p3_clicked()", &slot_5, QMetaData::Public },
	{ "p4_clicked()", &slot_6, QMetaData::Public },
	{ "p5_clicked()", &slot_7, QMetaData::Public },
	{ "movec5()", &slot_8, QMetaData::Public },
	{ "movec4()", &slot_9, QMetaData::Public },
	{ "movec3()", &slot_10, QMetaData::Public },
	{ "movec2()", &slot_11, QMetaData::Public },
	{ "movec1()", &slot_12, QMetaData::Public },
	{ "movecomp()", &slot_13, QMetaData::Public },
	{ "movecomp(QValueList<int>::iterator)", &slot_14, QMetaData::Public },
	{ "checkwin()", &slot_15, QMetaData::Public },
	{ "comp1st_clicked()", &slot_16, QMetaData::Public },
	{ "spinBox_valueChanged(int)", &slot_17, QMetaData::Public },
	{ "ok_clicked()", &slot_18, QMetaData::Public },
	{ "languageChange()", &slot_19, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"awari", parentObject,
	slot_tbl, 20,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_awari.setMetaObject( metaObj );
    return metaObj;
}

void* awari::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "awari" ) )
	return this;
    return QWizard::qt_cast( clname );
}

bool awari::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reset(); break;
    case 1: takeopp((QValueList<int>::iterator)(*((QValueList<int>::iterator*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    case 2: display(); break;
    case 3: p1_clicked(); break;
    case 4: p2_clicked(); break;
    case 5: p3_clicked(); break;
    case 6: p4_clicked(); break;
    case 7: p5_clicked(); break;
    case 8: movec5(); break;
    case 9: movec4(); break;
    case 10: movec3(); break;
    case 11: movec2(); break;
    case 12: movec1(); break;
    case 13: movecomp(); break;
    case 14: movecomp((QValueList<int>::iterator)(*((QValueList<int>::iterator*)static_QUType_ptr.get(_o+1)))); break;
    case 15: checkwin(); break;
    case 16: comp1st_clicked(); break;
    case 17: spinBox_valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 18: ok_clicked(); break;
    case 19: languageChange(); break;
    default:
	return QWizard::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool awari::qt_emit( int _id, QUObject* _o )
{
    return QWizard::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool awari::qt_property( int id, int f, QVariant* v)
{
    return QWizard::qt_property( id, f, v);
}

bool awari::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
