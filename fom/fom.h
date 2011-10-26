#ifndef fom_H
#define fom_H
#include <qimage.h>
#include <qwidget.h>
class fom : public QWidget
{
        Q_OBJECT
	        Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
		    Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage)
		        Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor)
    public:
			    fom(QWidget *parent = 0, const char *name = 0);
		        void setPenColor(const QColor &newColor);
	    QColor penColor() const { return curColor; }
        void setZoomFactor(int newZoom);
    int zoomFactor() const { return zoom; }
     void setIconImage(const QImage &newImage);
     const QImage &iconImage() const { return image; }
     QSize sizeHint() const;
void mousePressEvent(QMouseEvent *event);
void mouseMoveEvent(QMouseEvent *event);
void paintEvent(QPaintEvent *event);
void check();
QPoint& getpos();
void drawboxwidball(int,int,int);
void drawImagePixel(QPainter *painter, int i, int j);
void setImagePixel(const QPoint &pos, bool opaque,int);
void setnos();
void setdata(int,int );                  
void drawboxwidnoball(int,int);
int getcol()
{  return col;}
void setcolor(int c)
{
   col=c;
    }
void erase(int,int,int);
void drawsmall(const QPoint&,int);
void initi();
void vsassign();
int nxtpos();
void display();
int nxtpos1();                    
void setsmall(const QPoint & pos);
int vstrv();
int nextmin(int&,int&);
void drawsmallball(int,int);
    private: 
     QColor curColor;
     QImage image;
		                      QPoint pos;
				                int zoom;
						           int r1,c1,r2,c2,num,col,r,c,p1,q1,p2,q2;

int issamecolor();
};
   #endif

