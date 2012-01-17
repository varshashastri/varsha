/****************************************************************************
** fom meta object code from reading C++ file 'fom.h'
**
** Created: Sat Jul 23 09:19:40 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *fom::className() const
{
    return "fom";
}

QMetaObject *fom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_fom( "fom", &fom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString fom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "fom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString fom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "fom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* fom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[3] = {
 	{ "QColor","penColor", 0xa000103, &fom::metaObj, 0, -1 },
	{ "QImage","iconImage", 0xf000103, &fom::metaObj, 0, -1 },
	{ "int","zoomFactor", 0x10000103, &fom::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"fom", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 3,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_fom.setMetaObject( metaObj );
    return metaObj;
}

void* fom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "fom" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool fom::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool fom::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool fom::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setPenColor(v->asColor()); break;
	case 1: *v = QVariant( this->penColor() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setIconImage(v->asImage()); break;
	case 1: *v = QVariant( this->iconImage() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setZoomFactor(v->asInt()); break;
	case 1: *v = QVariant( this->zoomFactor() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool fom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
