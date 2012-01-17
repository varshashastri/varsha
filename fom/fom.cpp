#include <qpainter.h>
#include<iostream>
#include<qdatetime.h>
#include<qpen.h>
#include<qfont.h>
#include<qbrush.h>
#include "fom.h"
#include <qimage.h>
#include<unistd.h>
#include <qwidget.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
int brd[100];
int adjmat[9][9]={{0}};
int path1[9][9],path[9][9],vsmat[9][9],astrisk[9][9],stk[2][100],clr[9][9],arrow[9][9],small[9][9];
void throwballs(fom*);
int top=-1;int flag =0,score=0;
int test;
int pop();
int count=0;int start=0;
void push(int,int);
void reset1();
void next(int &,int &);
void getboxindex(int,int*,int*);
int issamecolor();
QPoint& fom:: getpos()
{
    return pos;
}
 fom :: fom (QWidget *parent, const char *name): QWidget(parent, name, WStaticContents)
{
//const QString  strtest="test";
  //(*parent).setCaption(strtest &);
    test=0;
    col=-1;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    curColor = black;
    zoom = 58;
    image.create(9, 9, 32);
    image.fill(qRgba(0, 0, 0, 0));
    image.setAlphaBuffer(true);
}
QSize  fom ::sizeHint() const
{
        QSize size = zoom * image.size();
	    if (zoom >= 3)
		        size += QSize(1, 1);
	        return size;
}
void  fom ::setPenColor(const QColor &newColor)
{
        curColor = newColor;
}
void  fom ::setIconImage(const QImage &newImage)
{
    if (newImage != image) 	
    {	            
	image = newImage.convertDepth(60);		          
       	image.detach();			            
	update();				  	
	updateGeometry();
    }
}
void  fom ::setZoomFactor(int newZoom)
{
        if (newZoom < 1)
	            newZoom = 1;
	    if (newZoom != zoom) 
           {
	        zoom = newZoom;
	       update();
	       updateGeometry();
            }
}
void  fom ::paintEvent(QPaintEvent *)
{QPainter painter(this);
if(test==1){painter.fillRect(0, 0,9*zoom, zoom*9, darkGray);}
else{
        painter.setPen(QPen(colorGroup().foreground(),2));

	    if (zoom >= 3) {
		       
		        painter.setPen(QPen(colorGroup().foreground(),2));
		 for (int i = 0; i <=image.width(); ++i)
		painter.drawLine(zoom * i, 0,zoom * i, zoom * image.height());
				        for (int j = 0; j <=image.height(); ++j)
				               painter.drawLine(0, zoom * j,zoom * image.width(), zoom * j);
					    }
	        for (int i = 0; i < image.width(); ++i) {
		            for (int j = 0; j < image.height(); ++j)
				            drawImagePixel(&painter, i, j);
			        }
              for(int i=0;i<9;i++)
                 for(int j=0;j<9;j++)
                    {if(clr[i][j]!=0)
                      drawboxwidball(j*zoom,i*zoom,clr[i][j]);}
}
}
void  fom ::drawImagePixel(QPainter *painter, int i, int j)
{
        QColor color;
	    QRgb rgb = image.pixel(i, j);
        if (qAlpha(rgb) == 0)
             color = colorGroup().base();
    else
        color.setRgb(rgb);
        if (zoom >= 3) {

           painter->fillRect(zoom * i + 1, zoom * j + 1,zoom - 1, zoom - 1, darkGray);
      } 
	else 
	{
            painter->fillRect(zoom * i, zoom * j,zoom, zoom, darkGray);
       	}
}

void  fom ::mousePressEvent(QMouseEvent *event)
{check();

    QPoint pos1,pos2;
    reset1();
for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
	if(small[i][j]==1)
	{
	    small[i][j]=0;
	    drawboxwidnoball(j*zoom,i*zoom);
	}
    if(start==0)
    {
	throwballs(this);start=1;}
        if (event->button() == LeftButton&&flag==0)
	{ pos1=event->pos();
	 if(brd[(pos1.x()/zoom)*9+pos1.y()/zoom+1]==0)return;
	      flag=1;
	  p1=r=r1=pos1.y()/zoom;
	  q1=c=c1=pos1.x()/zoom;
	   count++;
	}
    else if (event->button() == RightButton&&flag==1)
    { 
       	pos2=event->pos();
       	if(   brd[(pos2.x()/zoom)*9+pos2.y()/zoom+1]==1)return;
	
	flag=0;
	p2=r2=pos2.y()/zoom;
        q2=c2=pos2.x()/zoom;
	count++;
	
    }
    	else return;	
    	if(count==2)
	{int colr;
            p1=r1;  q1=c1;p2=r2;  q2=c2;
            count=0;
	    vsassign();
	    int v=vstrv();
	    if(v!=0)
	    {   colr=clr[r][c];
		while(p2!=p1||q2!=q1)
		{  vsassign();
		    v=vstrv();
		    erase(q1*zoom,p1*zoom,colr);
                   clr[r][c]=0;
		    path[p1][q1]=0;
		    path1[p1][q1]=1;
		    vsmat[p1][q1]=100;    
		    next(p1,q1);
	       	    drawboxwidball(q1*zoom,p1*zoom,colr);
                    clr[p1][q1]=0;
		    path[p1][q1]=0;
		    vsmat[p2][q2]=100;
		    path1[p1][q1]=0;
		}
		clr[p1][q1]=colr;
	    }
	else cout<<"no!";
    throwballs(this);
issamecolor();}else return;
}
 void fom ::mouseMoveEvent(QMouseEvent *event)
{
        if (event->state() & LeftButton)
	{pos=event->pos();
	}
	    else if (event->state() & RightButton)
	    {pos=event->pos();
	    }
}

QColor getcolorname(int c)
{
 switch(c)
{
case 1:return Qt::red;break;
case 2:return Qt::darkGreen;break;
case 3:return Qt::blue;break;
case 4:return Qt::magenta;break;
case 5:return Qt::yellow;break;
default:return Qt::gray;break;
}
}
void  fom ::setImagePixel(const QPoint &pos, bool opaque,int col)
{
    int i,j;
        i = pos.x() / zoom;    
	j = pos.y() / zoom;
	QPainter painter(this);
	QColor color=colorGroup().base();
	if (image.rect().contains(i, j)) 
	{
	    if (opaque){ painter.setPen(QPen(Qt::black, 1));
		painter.setBrush(QBrush(getcolorname(col), Qt::SolidPattern));
		painter.drawEllipse(i*(zoom)+zoom/4,  j*(zoom) +zoom/4,zoom/2, zoom/2);
	    }
	    else
		painter.fillRect(zoom * i + 1, zoom * j + 1,zoom - 1, zoom - 1, darkGray);					   
	    image.setPixel(i, j, qRgba(0, 0, 0, 0));
	}
}

void fom::check()
{int i,j,cnt=0;
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
       {
             if(clr[i][j]>0)cnt++;
       }
if(cnt>78)
{
        QPainter painter(this);
	QColor color=colorGroup().base(); 
         painter.fillRect(0, 0,9*zoom, zoom*9, darkGray);
         QString str="Score=";QString str1 = QString::number(score);
         QPen p(black,1);
          str.append(str1); painter.setPen(p);
          painter.drawText(4*zoom+10,5*zoom,str);  
          painter.drawText(4*zoom+3,4*zoom,"GameOver!");
          test=1;
   }
}	
void fom::drawsmall(const QPoint&pos,int col)
{       QPen p(getcolorname(col),3);
	p.setCapStyle(RoundCap);
	int i,j;
        i = pos.x() / zoom;
        j = pos.y() / zoom;		 
        QPainter painter(this);
       
        if (image.rect().contains(i, j))
	{ 
	    small[j][i]=1;
	    painter.fillRect(zoom * i + 1, zoom * j + 1,zoom - 1, zoom - 1, darkGray);
	    image.setPixel(i, j, qRgba(0, 0, 0, 0));
            painter.setPen(p);
          painter.setBrush(QBrush(getcolorname(col), Qt::Dense4Pattern));
   if((path[j-1][i]==1)&&j>0)
   {           painter.drawLine((i)*zoom+zoom/2,(j)*zoom+15,(i+1)*zoom-zoom/2,(j+1)*zoom-15);
          
          painter.drawLine((i)*zoom+zoom/2,(j)*zoom+15,(i)*zoom+35,(j+1)*zoom-35);
          painter.drawLine((i)*zoom+zoom/2,(j)*zoom+15,(i+1)*zoom-35,(j+1)*zoom-35);
   }
 if(path[j+1][i]==1&&(j+1)<9)
   { 
          painter.drawLine((i)*zoom+zoom/2,(j)*zoom+15,(i+1)*zoom-zoom/2,(j+1)*zoom-15);        
          painter.drawLine((i+1)*zoom-zoom/2,(j+1)*zoom-15,(i)*zoom+35,(j)*zoom+33);
          painter.drawLine((i+1)*zoom-zoom/2,(j+1)*zoom-15,(i)*zoom+23,(j)*zoom+33);
   }
if((path[j][i+1]==1)&&(i+1)<9)
{
       painter.drawLine((i)*zoom+15,(j)*zoom+zoom/2,(i+1)*zoom-15,(j+1)*zoom-zoom/2);
       painter.drawLine((i+1)*zoom-15,(j+1)*zoom-zoom/2,i*zoom+35,j*zoom+35);
       painter.drawLine((i+1)*zoom-15,(j+1)*zoom-zoom/2,(i)*zoom+35,(j)*zoom+23);
  }
if((path[j][i-1]==1)&&(i)>0)
{
    painter.drawLine((i)*zoom+15,(j)*zoom+zoom/2,(i+1)*zoom-15,(j+1)*zoom-zoom/2);
    painter.drawLine((i)*zoom+15,(j)*zoom+zoom/2,i*zoom+25,j*zoom+35);
    painter.drawLine((i)*zoom+15,(j)*zoom+zoom/2,i*zoom+25,j*zoom+23);
}
}
}
void fom::initi()
{
    for(int i=0;i<=8;i++)
	for(int j=0;j<=8;j++)
	{astrisk[i][j]=0;
	    if(path1[i][j]==1)
		vsmat[i][j]=-1;
	    else vsmat[i][j]=100;
	}
}
void assignsurr(int i,int j)
{
    if((i-1)>=0&&vsmat[i-1][j]==-1)
	vsmat[i-1][j]=vsmat[i][j]+1;
    if((i+1)<=8&&vsmat[i+1][j]==-1)
	vsmat[i+1][j]=vsmat[i][j]+1;
    if((j-1)>=0&&vsmat[i][j-1]==-1)
	vsmat[i][j-1]=vsmat[i][j]+1;
    if((j+1)<=8&&vsmat[i][j+1]==-1)
	vsmat[i][j+1]=vsmat[i][j]+1;
    astrisk[i][j]=1;
}
int fom::issamecolor()
{
int i,j,k;

 for(i=0;i<9;i++)
 for(j=0;j<1;j++)
{
 if((clr[i][j]!=0)&&(clr[i][j]==clr[i][j+1])&&(clr[i][j+1]==clr[i][j+2])&&(clr[i][j+2]==clr[i][j+3])&&(clr[i][j+3]==clr[i][j+4])&&(clr[i][j+4]==clr[i][j+5])&&(clr[i][j+5]==clr[i][j+6])&&(clr[i][j+6]==clr[i][j+7])&&(clr[i][j+7]==clr[i][j+8]))

      {
       score+=250;
       for(k=0;k<9;k++)
       {
       drawboxwidnoball((j+k)*zoom,i*zoom);
       }
       return 1;
       }
       else continue;
      }
 for(i=0;i<9;i++)
 for(j=0;j<2;j++)
{
 if((clr[i][j]!=0)&&(clr[i][j]==clr[i][j+1])&&(clr[i][j+1]==clr[i][j+2])&&(clr[i][j+2]==clr[i][j+3])&&(clr[i][j+3]==clr[i][j+4])&&(clr[i][j+4]==clr[i][j+5])&&(clr[i][j+5]==clr[i][j+6])&&(clr[i][j+6]==clr[i][j+7]))

      {
       score+=200;
       for(k=0;k<8;k++)
       {
       drawboxwidnoball((j+k)*zoom,i*zoom);
       }
       return 1;
       }
       else continue;
      }
     for(i=0;i<9;i++)
      for(j=0;j<3;j++)
      {
	  if((clr[i][j]!=0)&&(clr[i][j]==clr[i][j+1])&&(clr[i][j+1]==clr[i][j+2])&&(clr[i][j+2]==clr[i][j+3])&&(clr[i][j+3]==clr[i][j+4])&&(clr[i][j+4]==clr[i][j+5])&&(clr[i][j+5]==clr[i][j+6]))
      {
       score+=150;
       for(k=0;k<7;k++)
       {
       drawboxwidnoball((j+k)*zoom,i*zoom);
       
       }
       return 1;
      }
       else continue;
    }
   for(i=0;i<9;i++)
    for(j=0;j<4;j++)
    {
      if((clr[i][j]!=0)&&(clr[i][j]==clr[i][j+1])&&(clr[i][j+1]==clr[i][j+2])&&(clr[i][j+2]==clr[i][j+3])&&(clr[i][j+3]==clr[i][j+4])&&(clr[i][j+4]==clr[i][j+5]))
      {
       score+=100;
       for(k=0;k<6;k++)
       {       
       drawboxwidnoball((j+k)*zoom,i*zoom);
       }
       return 1;
       }
       else continue;
    }
   for(i=0;i<9;i++)
    for(j=0;j<5;j++)
    {

      if((clr[i][j]!=0)&&(clr[i][j]==clr[i][j+1])&&(clr[i][j+1]==clr[i][j+2])&&(clr[i][j+2]==clr[i][j+3])&&(clr[i][j+3]==clr[i][j+4]))
      {
       score+=50;
       for(k=0;k<5;k++)
       {
       
      drawboxwidnoball((j+k)*zoom,(i)*zoom);

       }
       return 1;
       }
       else continue;
}
for(i=0;i<9;i++)
for(j=0;j<1;j++)
{
if((clr[j][i]!=0)&&(clr[j][i]==clr[j+1][i])&&(clr[j+1][i]==clr[j+2][i])&&(clr[j+2][i]==clr[j+3][i])&&(clr[j+3][i]==clr[j+4][i])&&(clr[j+4][i]==clr[j+5][i])&&(clr[j+5][i]==clr[j+6][i])&&(clr[j+6][i]==clr[j+7][i])&&(clr[j+7][i]==clr[j+8][i]))

  {
  score+=250;
    for(k=0;k<9;k++)
    {
          drawboxwidnoball(i*zoom,(j+k)*zoom);
      
      }

  return 1;
  }
    else continue;
}

for(i=0;i<9;i++)
for(j=0;j<2;j++)
{
if((clr[j][i]!=0)&&(clr[j][i]==clr[j+1][i])&&(clr[j+1][i]==clr[j+2][i])&&(clr[j+2][i]==clr[j+3][i])&&(clr[j+3][i]==clr[j+4][i])&&(clr[j+4][i]==clr[j+5][i])&&(clr[j+5][i]==clr[j+6][i])&&(clr[j+6][i]==clr[j+7][i]))

  {
  score+=200;
    for(k=0;k<8;k++)
    {
 drawboxwidnoball(i*zoom,(j+k)*zoom);
      
      }

  return 1;
  }
    else continue;
}

for(i=0;i<9;i++)
for(j=0;j<3;j++)
{
if((clr[j][i]!=0)&&(clr[j][i]==clr[j+1][i])&&(clr[j+1][i]==clr[j+2][i])&&(clr[j+2][i]==clr[j+3][i])&&(clr[j+3][i]==clr[j+4][i])&&(clr[j+4][i]==clr[j+5][i])&&(clr[j+5][i]==clr[j+6][i]))

  {
  score+=150;
    for(k=0;k<7;k++)
    {

     drawboxwidnoball(i*zoom,(j+k)*zoom);
      
      }

  return 1;
   }
    else continue;
}

for(i=0;i<9;i++)
for(j=0;j<4;j++)
{
if((clr[j][i]!=0)&&(clr[j][i]==clr[j+1][i])&&(clr[j+1][i]==clr[j+2][i])&&(clr[j+2][i]==clr[j+3][i])&&(clr[j+3][i]==clr[j+4][i])&&(clr[j+4][i]==clr[j+5][i]))
  {
  score+=100;
    for(k=0;k<6;k++)
    {
  
    drawboxwidnoball(i*zoom,(j+k)*zoom);
      
      }
  return 1;
   }
  else continue;
}
for(i=0;i<9;i++)
for(j=0;j<5;j++)
   {
      if((clr[j][i]!=0)&&(clr[j][i]==clr[j+1][i])&&(clr[j+1][i]==clr[j+2][i])&&(clr[j+2][i]==clr[j+3][i])&&(clr[j+3][i]==clr[j+4][i]))
  {
  score+=50;
    for(k=0;k<5;k++)
    {
     
   drawboxwidnoball(i*zoom,(j+k)*zoom);
      
      }
  return 1;
   }
    else continue;   }return 0;
}

 void reset1()
{     int i,j;
    for( i=0;i<=8;i++)
    {
	for(j=0;j<=8;j++)
	{arrow[i][j]=0;
          if(clr[i][j]>0)
	    adjmat[i][j]=path[i][j]=0;
	    else adjmat[i][j]=path1[i][j]=1;
	}
    }
    for(i=0;i<2;i++)
	for(j=0;j<100;j++)
	    stk[i][j]=-2;
    top=-1;
}
void next(int &p,int &q)
{
    if(path[p+1][q]==1&&(p+1)<=8)
    {
	p++;     return;
    }
    if(path[p-1][q]==1&&(p-1)>=0)
    {p--;return;
    }
    if(path[p][q+1]==1&&(q+1)<=8)
    {q++;return;}
    if(path[p][q-1]==1&&(q-1)>=0)
    {q--;return;}
}
int fom::nextmin(int &i,int &j)
{
    int p,q,min=100,flag=0;
    for(p=0;p<9;p++)
	for(q=0;q<9;q++)
	{
	    if(vsmat[p][q]!=100&&astrisk[p][q]==0&&vsmat[p][q]!=-1)
	    {
		flag=1;
		if(vsmat[p][q]<min)
		{
		    min=vsmat[p][q];
		    i=p;
		    j=q;
		}
	    }
	}
    if(flag==1)
    {
	return 0;
    }
    else
	return -1;
}
void fom::vsassign()
{
    int i,j;
    initi();
    i=r;j=c;
    vsmat[i][j]=0;
    int x;
    do
    {
	assignsurr(i,j);
	x=nextmin(i,j);
    }while(x!=-1);
}
int fom::nxtpos()
{
    int ret=-1;
    while(r1>=0&&r1<=8&&c1>=0&&c1<=8)
    {
	if(vsmat[r1+1][c1]==vsmat[r1][c1]+1&&r1+1<=8)
	{ ret=(r1+1)*10+c1;break;}
	if(vsmat[r1][c1+1]==vsmat[r1][c1]+1&&c1+1<=8)
	{ ret=r1*10+c1+1;break;}
	if(vsmat[r1-1][c1]==vsmat[r1][c1]+1&&r1-1>=0)
	{ret=(r1-1)*10+c1;break;}
	if(vsmat[r1][c1-1]==vsmat[r1][c1]+1&&c1-1>=0)
	{ret=r1*10+c1-1;break;}
	break;   }
	if(r1>=0&&r1<=8&&c1>=0&&c1<=8&&ret>=0) return ret;
	else  return -1;
}
void push(int a ,int b)
{
    top++;
    stk[0][top]=a;
    stk[1][top]=b;
}
int pop()
{
    int t;
    if(stk[0][top]==-2)
    {t=stk[1][top];
	stk[1][top]=-2;top--; }

    else
    {t=stk[0][top];
	stk[0][top]=-2; }
	return t;
}
int alzrs()
{
    int i,j,flag=0;
    for(i=0;i<=8;i++)
	 {
	     for(j=0;j<=8;j++)
		     {
	  		 if(adjmat[i][j]==1)
			 {
			    flag=1;
			     break;
			 }
		     }
	     if(adjmat[i][j]==1)
	     {
		 flag=1;
		 break;
	     }
	 }
    if(flag==1)return 1;
    else return 0;
}
int fom::vstrv()                                                
{  int next;//,i,j;
    if((adjmat[r1][c1]==0)&&(adjmat[r2][c2]==1))
    {
	 while(!((r1==r2)&&(c1==c2))||!alzrs())
	       {
		      next=nxtpos();

		         if(next!=-1)
			 {
			     push(r1,c1);
			     adjmat[r1][c1]=0;
			     path[r1][c1]=1;
			     r1=next/10;
			     c1=next%10;
			 }
			 else if(next==-1&&top==-1)return 0;
			 else
			 
			 {
			     path[r1][c1]=0;
			     adjmat[r1][c1]=0;
	    		     vsmat[r1][c1]=0;   
			     r1=pop();
			     c1=pop();
			     adjmat[r1][c1]=1;
			 }
	       }
    }
    if(r1==r2&&c1==c2)
    {path[r2][c2]=1;
	return 1;}
	return 0;
}
void getboxindex(int boxno,int*p,int*q)
{
      *p=(boxno-1)/9;
        *q=(boxno-1)%9;
}
void throwballs(fom*ptr)
{
    int i1=-1,i2=-1,i3=-1,p,q,col1,col2,col3,zoom=58;
srand(time(0));

while((i1==i2)||(i2==i3)||(i3==i1))
{
    i1=rand()%81+1;
    i2=rand()%81+1;
     i3=rand()%81+1;
      if((brd[i1]==1)||(brd[i2]==1)||(brd[i3]==1))
    {
	i1=i2=i3=-1;
	continue;
    }
}
col1=rand()%5+1;
col2=rand()%5+1;
col3=rand()%5+1;
getboxindex(i1,&p,&q);
if(arrow[q][p]!=1)
ptr->drawboxwidball(p*zoom,q*zoom,col1);
getboxindex(i2,&p,&q);
if(arrow[q][p]!=1)
ptr->drawboxwidball(p*zoom,q*zoom,col2);
getboxindex(i3,&p,&q);
if(arrow[q][p]!=1)
ptr->drawboxwidball(p*zoom,q*zoom,col3);
}
void fom::erase(int p,int q,int col)
{
arrow[q/zoom][p/zoom]=1;
QPoint pt;
pt.setX(p);
pt.setY(q);
adjmat[q/zoom][p/zoom]=1;
brd[(p/zoom)*9+q/zoom+1]=0;
drawsmall(pt,col);
path1[q/zoom][p/zoom]=0;
}
void fom::drawboxwidnoball(int p,int q)
{
    QPoint pt;
    pt.setX(p);
    pt.setY(q);
    adjmat[q/zoom][p/zoom]=1;
    brd[(p/zoom)*9+q/zoom+1]=0;
    setImagePixel(pt,false,0);
    path1[q/zoom][p/zoom]=0;
    clr[q/zoom][p/zoom]=0;
}
void fom::drawboxwidball(int p,int q,int col)
{   QPoint pt;
    pt.setX(p);
    pt.setY(q);
    adjmat[q/zoom][p/zoom]=0;
    clr[q/zoom][p/zoom]=col;
    path1[q/zoom][p/zoom]=0;
    setImagePixel(pt,true,col);
    brd[(p/zoom)*9+q/zoom+1]=1;
}
#include<qapplication.h>
int main(int argc, char *argv[])
{
QApplication app(argc, argv);
fom *icon = new  fom ;
app.setMainWidget(icon);
(*icon).setCaption("Five or More (Varsha's Creations-2008)");
icon->show();
return app.exec();
}
/////<<----------------->> A Program by Varsha Shastri <<---------------------->>

