/****************************************************************************
** Form interface generated from reading ui file 'awari.ui'
**
** Created: Wed Oct 26 19:54:48 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef AWARI_H
#define AWARI_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwizard.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QWidget;
class QPushButton;
class QLabel;
class QFrame;
class QSpinBox;

class awari : public QWizard
{
    Q_OBJECT

public:
    awari( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~awari();

    QWidget* Varsha;
    QPushButton* p3;
    QLabel* playerspot_3;
    QFrame* frame4;
    QLabel* declare_2_2;
    QPushButton* c3;
    QPushButton* p5;
    QLabel* playerspot_2_2;
    QLabel* cc2;
    QLabel* pp5;
    QLabel* cc3;
    QPushButton* p4;
    QLabel* cc5;
    QLabel* textLabel1_2_2_2;
    QLabel* pp4;
    QLabel* textLabel1_2_2;
    QLabel* pp2;
    QPushButton* p2;
    QLabel* cc1;
    QLabel* cc4;
    QLabel* pp1;
    QPushButton* b2;
    QPushButton* c2;
    QLabel* textLabel1_3;
    QLabel* comp;
    QLabel* textLabel1_2;
    QLabel* textLabel1_2_3;
    QLabel* declarec;
    QLabel* pp3;
    QLabel* playerspot;
    QLabel* playerspot_2;
    QLabel* you;
    QPushButton* p1;
    QPushButton* c5;
    QPushButton* comp1st;
    QLabel* declarep;
    QSpinBox* spinBox;
    QPushButton* ok;
    QPushButton* c4;
    QPushButton* c1;
    QPushButton* b1;
    QLabel* textLabel1;

    virtual QString gettext( int i );
    virtual bool last( QValueList<int>::iterator q );
    virtual QValueList<int>::iterator getopp( QValueList<int>::iterator q );
    virtual bool checkdanger( QValueList<int>::iterator q );
    virtual bool escape();
    virtual int priority( QValueList<int>::iterator q );

public slots:
    virtual void reset();
    virtual void takeopp( QValueList<int>::iterator iter, int cnt );
    virtual void display();
    virtual void p1_clicked();
    virtual void p2_clicked();
    virtual void p3_clicked();
    virtual void p4_clicked();
    virtual void p5_clicked();
    virtual void movec5();
    virtual void movec4();
    virtual void movec3();
    virtual void movec2();
    virtual void movec1();
    virtual void movecomp();
    virtual void movecomp( QValueList<int>::iterator q );
    virtual void checkwin();
    virtual void comp1st_clicked();
    virtual void spinBox_valueChanged( int );
    virtual void ok_clicked();

protected:

protected slots:
    virtual void languageChange();

private:
    QValueList<int>::iterator iter,ip1,ip2,ip3,ip4,ip5,ib1,ic1,ic2,ic3,ic4,ic5,ib2;
    QValueList<int> list;
    int count;
    QString p;
    QString c;

    QPixmap image0;

    void init();

};

#endif // AWARI_H
