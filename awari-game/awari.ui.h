/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
******************************************************************************/
#include <qvalidator.h>
void awari::init()
{   
    setHelpEnabled(Varsha,false);
   setBackEnabled(Varsha,false);
   list.append(spinBox->value() );
   list.append(spinBox->value() );
   list.append(spinBox->value() ); 
   list.append(spinBox->value() ); 
   list.append(spinBox->value() ); 
   list.append( 0 );
   list.append( spinBox->value() );
   list.append(spinBox->value() ); 
   list.append(spinBox->value() ); 
   list.append( spinBox->value() );
   list.append(spinBox->value() ); 
   list.append( 0 );
   iter=list.begin();
   ip1=iter;
   ip2=++iter;
   ip3=++iter;
   ip4=++iter;
   ip5=++iter; 
   ib1=++iter;
   ic5=++iter;
   ic4=++iter;
   ic3=++iter;
   ic2=++iter;
   ic1=++iter;
   ib2=++iter;
  p="";
  c="";
  display();
} 
void awari::reset()
{
    cc1->setText("");
     cc2->setText("");
     cc3->setText("");
     cc4->setText("");
     cc5->setText("");
     pp1->setText("");
     pp2->setText("");
     pp3->setText("");
     pp4->setText("");
     pp5->setText("");
 } 
QString awari::gettext(int i)
{QString t;
    if(i==0)
    {
	t="";
	return t;
    }

t=QString::number(i);
return t;
}

void awari :: takeopp(QValueList<int>::iterator iter,int cnt)
{
    int val=0;
    if(iter==ib1||iter==ib2)return;
    if(iter==ip1)
    {val=*ic1;
	if(val!=0)
	{ if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{
	p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));
	p.append(" taken!");}
    }
	*ic1=0;
    }
    if(iter==ip2)
	  {
	val=*ic2;
	if(val!=0)
	{ if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));p.append(" taken!");}
    }
	*ic2=0;
    }
 if(iter==ip3)
 {
    val=*ic3;
  if(val!=0)
	{ if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));p.append(" taken!");}
    }
	*ic3=0;
}
 if(iter==ip4)  
{
     val=*ic4;
    if(val!=0)
	{ if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{ p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));p.append(" taken!");}
    }
	*ic4=0;
 }
  if(iter==ip5)  
 {
      val=*ic5;
     if(val!=0)
	{ if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{ 
	 p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));p.append(" taken!");}
    }
      *ic5=0;
  }
   if(iter==ic1)  
  {
       val=*ip1;                                                                                                                        
       if(val!=0)
	{
	   if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{
	    
	p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));
	p.append(" taken!");}
    }
       *ip1=0;
   }
    if(iter==ic2)  
   {
	val=*ip2;                                                                                                                       
      if(val!=0)
	{ if(cnt==0){c.append("\nlast piece in the empty box\n");	
	      c.append(gettext(val));c.append(" taken!");}
	  else{
	p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));
	p.append(" taken!");}
    }
      
	*ip2=0;
    }
     if(iter==ic3)  
    {
	 val=*ip3;                                                                                                                       
       if(val!=0)
	 {if(cnt==0){
	       c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	   else{
	p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));
	p.append(" taken!");}
       }
	 *ip3=0;
     }
      if(iter==ic4)  
     {
	  val=*ip4;                                                                                                                       
       if(val!=0)
	  {if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	else{
	    p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));
	p.append(" taken!");}
    }
   
	  *ip4=0;
      }
       if(iter==ic5)  
      {
	   val=*ip5;                                                                                                                       
       if(val!=0)
	{
	   if(cnt==0){c.append("\nlast piece in the empty box\n");	
	       c.append(gettext(val));c.append(" taken!");}
	   else{
       p.append("\nlast piece in the empty box\n");	
	p.append(gettext(val));
	p.append(" taken!");}
       }
      
	   *ip5=0;
       }
       if(cnt==1)
       {*ib1+=val;}
       if(cnt==0)
       {*ib2+=val;}
   }
void awari::display()
{
    declarec->setText(c);
    declarep->setText(p);
    p1->setText(gettext(*ip1));
    p2->setText(gettext(*ip2));
    p3->setText(gettext(*ip3));
    p4->setText(gettext(*ip4));
    p5->setText(gettext(*ip5));
    b1->setText(gettext(*ib1));
    c1->setText(gettext(*ic1));
    c2->setText(gettext(*ic2));
    c3->setText(gettext(*ic3));
   c4->setText(gettext(*ic4));
   c5->setText(gettext(*ic5));
   b2->setText(gettext(*ib2));  
   if(*ip1==0)p1->setEnabled(false);
   else p1->setEnabled(true);
    if(*ip2==0)p2->setEnabled(false);
   else p2->setEnabled(true);
    if(*ip3==0)p3->setEnabled(false);
   else p3->setEnabled(true);
    if(*ip4==0)p4->setEnabled(false);
   else p4->setEnabled(true);
    if(*ip5==0)p5->setEnabled(false);
   else p5->setEnabled(true);
    if(*ic1==0)c1->setEnabled(false);
   else c1->setEnabled(true);
    if(*ic2==0)c2->setEnabled(false);
   else c2->setEnabled(true);
    if(*ic3==0)c3->setEnabled(false);
   else c3->setEnabled(true);		
    if(*ic4==0)c4->setEnabled(false);
   else c4->setEnabled(true);
    if(*ic5==0)c5->setEnabled(false);
   else c5->setEnabled(true);
}    
void awari::p1_clicked()
{spinBox->setEnabled(false);ok->setEnabled(false);
    comp1st->setEnabled(false);checkwin();
        reset();
    if(*ip1==0)return;
    pp1->setText("#");
  count=count%5+1;
    iter=ip1;
    int value=*ip1;
    *ip1=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{*(++iter)+=1;
	    value--;}
    }p="moves from p1";
    if(*iter==1)
	takeopp(iter,1);
    display();
      if(!escape())
       movecomp();
}
void awari::p2_clicked()
{spinBox->setEnabled(false);ok->setEnabled(false);
    comp1st->setEnabled(false);checkwin();
    reset();
    if(*ip2==0)return;
     pp2->setText("#");
    iter=ip2;
    int value=*ip2;
    *ip2=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{*(++iter)+=1;
	    value--;}
    }p="moves from p2";
    if(*iter==1)
	takeopp(iter,1);
    display();
      if(!escape())
       movecomp();
}
void awari::p3_clicked()
{spinBox->setEnabled(false);
    comp1st->setEnabled(false); checkwin(); 
    reset();
    if(*ip3==0)return;
     pp3->setText("#");
    iter=ip3;
    int value=*ip3;
    *ip3=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
if(value!=0)
{
    *(++iter)+=1;
	value--;
    }
    }p="moves from p3";
    if(*iter==1)
	takeopp(iter,1);
    display();
      if(!escape())
       movecomp();
}
void awari::p4_clicked()
{ spinBox->setEnabled(false);ok->setEnabled(false);
    comp1st->setEnabled(false); checkwin();
    reset();
    if(*ip4==0)return;
    pp4->setText("#");
   iter=ip4;
    int value=*ip4;
    *ip4=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    (*iter)+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;}
    }p="moves from p4";
    if(*iter==1)
	takeopp(iter,1);
    display();
      if(!escape())
       movecomp();
}
void awari::p5_clicked()
{spinBox->setEnabled(false);ok->setEnabled(false);
    comp1st->setEnabled(false);checkwin();
reset();    
    if(*ip5==0)return;
    pp5->setText("#");
    iter=ip5;
    int value=*ip5;
    *ip5=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    (*iter)+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;
    }
    }p="moves from p5";
    if(*iter==1)
	takeopp(iter,1);
    display();
      if(!escape())
    movecomp();
}
void awari::movec5()
{ok->setEnabled(false);spinBox->setEnabled(false);
    checkwin();
    cc5->setText("#");
    iter=ic5;
    int value=*ic5;
    *ic5=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;
    }
    } 
    c="moves from c5";
    if(*iter==1)
	takeopp(iter,0);
    display();
 checkwin();
}
void awari::movec4()
    {ok->setEnabled(false);spinBox->setEnabled(false);
      checkwin();
      cc4->setText("#");
    iter=ic4;
    int value=*ic4;
    *ic4=0;
    while(value!=0)
    {if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;}
    }
    c="moves from c4";
    if(*iter==1)
	takeopp(iter,0);
    display();checkwin();
}
void awari::movec3()
    {ok->setEnabled(false);
    spinBox->setEnabled(false);
    checkwin();
    cc3->setText("#");
    iter=ic3;
    int value=*ic3;
    *ic3=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;
    }
    }
    c="moves from c3";
    if(*iter==1)
	takeopp(iter,0);
    display();
    checkwin();
}
void awari::movec2()
{ok->setEnabled(false);
    spinBox->setEnabled(false);
    checkwin();
    cc2->setText("#");
    iter=ic2;
    int value=*ic2;
    *ic2=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;
    }
    }
     c="moves from c2";
    if(*iter==1)
	takeopp(iter,0);
    display();checkwin();
}
void awari::movec1()
{spinBox->setEnabled(false);
    ok->setEnabled(false);checkwin();
  cc1->setText("#");
    iter=ic1;
    int value=*ic1;
    *ic1=0;
    while(value!=0)
    {
	if(iter==ib2)
	{
	    iter=list.begin();
	    *iter+=1;
	    value--;
	}
	if(value!=0)
	{
	*(++iter)+=1;
	value--;}
    }
    c="moves from c1";
    if(*iter==1)
	takeopp(iter,0);
    display();checkwin();
}

int max(int val[])
{
    
    int m=val[0],i,pos=0;
    for(i=0;i<5;i++)
    {
	if(val[i]>m)
	{m=val[i];pos=i;}
    }
    if(m==0)return -1;
    else return pos;
}
void awari:: movecomp()
{
    int val[5]={0,0,0,0,0},c;
        val[0]=priority(ic1);
        val[1]=priority(ic2);
        val[2]=priority(ic3);
        val[3]=priority(ic4);
        val[4]=priority(ic5);
        c=max(val)+1;                  
            
        if(c==1&&(*ic1!=0)){movec1();return;}
        if(c==2&&(*ic2!=0)){movec2();return;}
        if(c==3&&(*ic3!=0)){movec3();return;}
        if(c==4&&(*ic4!=0)){movec4();return;}
        if(c==5&&(*ic5!=0)){movec5();return;}
	
     if((*ic1!=0)&&!last(ic1)) {movec1();return;}
     if((*ic2!=0)&&!last(ic2)){movec2();return;}
     if((*ic3!=0)&&!last(ic3)){movec3();return;}
     if((*ic4!=0)&&!last(ic4)){movec4();return;}
     if((*ic5!=0)&&!last(ic5)){movec5();return;}
       if(*ic1!=0) {movec1();return;}
     if(*ic2!=0){movec2();return;}
     if(*ic3!=0){movec3();return;}
     if(*ic4!=0){movec4();return;}
     if(*ic5!=0){movec5();return;}
	else return;
 }
bool awari:: last(QValueList<int>::iterator q)
{
   if(q==ic1)
       if((*ip1==10)||(*ip2==9)||(*ip3==8)||(*ip4==7)||(*ip5==6))
       return true;
   if(q==ic2)
       if((*ip1==9)||(*ip2==8)||(*ip3==7)||(*ip4==6)||(*ip5==5))
       return true;
   if(q==ic3)
       if((*ip1==8)||(*ip2==7)||(*ip3==6)||(*ip4==5)||(*ip5==4))
       return true;
   if(q==ic4)
       if((*ip1==7)||(*ip2==6)||(*ip3==5)||(*ip4==4)||(*ip5==3))
       return true;
   if(q==ic5)
       if((*ip1==6)||(*ip2==5)||(*ip3==4)||(*ip4==3)||(*ip5==2))
       return true;
   else return false;
}
/*bool check(QValueList<int>::iterator q)
{
    int value;
    QValueList<int>::iterator p=ip1;
    */
void awari:: movecomp(QValueList<int>::iterator q)
{

    if(q==ic1){movec1();return;}
    if(q==ic2){movec2();return;}
    if(q==ic3){movec3();return;}
    if(q==ic4){movec4();return;}
    if(q==ic5){movec5();return;}
}

QValueList<int>::iterator awari::getopp(QValueList<int>::iterator q)
{
    if(q==ib1||q==ib2)return q;
    if(q==ic1)return ip1;
    if(q==ic2)return ip2;
    if(q==ic3)return ip3;
    if(q==ic4)return ip4;
    if(q==ic5)return ip5;
    if(q==ip1)return ic1;
    if(q==ip2)return ic2;
    if(q==ip3)return ic3;
    if(q==ip4)return ic4;
    if(q==ip5)return ic5;
    else return q;
}

bool awari::checkdanger(QValueList<int>::iterator q)	
{
    if(*q!=0)return false;
    QValueList<int> :: iterator cur,temp;
   temp=cur=ip1;
    int val;
    while(temp!=ib1&&temp!=q)
    {
	cur=temp;
	val=*temp;
	while(cur!=q&&cur!=ib1)
	{
	    cur++;
	     val--;
	}temp++;
	if(val==0&&cur==q)
	    return true;
    }
    return false;
}
bool awari::escape()
{
    int val[5]={0,0,0,0,0},i=0,m;
    QValueList<int>::iterator cur;
    cur=ip1;
    while(cur!=ib1)
    {
if(cur==ip1)i=0;if(cur==ip2)i=1;if(cur==ip3)i=2;if(cur==ip4)i=3;if(cur==ip5)i=4;
	if(checkdanger(cur))
	 if(*getopp(cur)!=0)   
	{  
	    val[i]=*getopp(cur);
	}
	cur++;
    }m=max(val);
    if(m==-1)return false;
    else{
	if(m==0)movecomp(getopp(ip1));
	if(m==1)movecomp(getopp(ip2));
	if(m==2)movecomp(getopp(ip3));
	if(m==3)movecomp(getopp(ip4));
	if(m==4)movecomp(getopp(ip5));	
	return true;
          }
}

int awari::priority(QValueList<int>::iterator q) 
{QValueList<int>::iterator cur=q;
  int prec,val;
prec=30;
  cur=q;
  val=*q;
  while(val!=0)
  {
    if(cur==ib2)
    {
     cur=ip1;
      val--;
     continue;
    }
    else{
         ++cur;
         val--;
        }
  }
  if(*cur==0)  
      prec=prec+*(getopp(cur));
  return prec;
}
void awari::checkwin()
{int p=0,c=0;
    if(*ip1==0&&*ip2==0&&*ip3==0&&*ip4==0&&*ip5==0)
    {
	p=1;
    }
    else if(*ic1==0&&*ic2==0&&*ic3==0&&*ic4==0&&*ic5==0)
    {
	c=1;
    }
    if(p==1||c==1)
    {
	if(*ib1>*ib2)
	{
	    declarep->setText("               Congadulations!\n              You Win!");
	    declarec->setText("          ");
	}
	else
	{ declarec->setText("                        Computer Wins!");
	    declarep->setText("                              You lose :(");}
	    p1->setEnabled(false);
	    p2->setEnabled(false);
	    p3->setEnabled(false);
	    p4->setEnabled(false);
	    p5->setEnabled(false);
	       c1->setEnabled(false);
	    c2->setEnabled(false);
	    c3->setEnabled(false);
	    c4->setEnabled(false);
	    c5->setEnabled(false);
	    
}
}


void awari::comp1st_clicked()
{
movec1();
comp1st->setEnabled(false);
}


void awari::spinBox_valueChanged( int )
{
    *ip1=spinBox->value();
    *ip2=spinBox->value();
    *ip3=spinBox->value();
    *ip4=spinBox->value();
    *ip5=spinBox->value();
    *ic1=spinBox->value();
    *ic2=spinBox->value();
    *ic3=spinBox->value();    
    *ic4=spinBox->value();
    *ic5=spinBox->value();
    display();
}


void awari::ok_clicked()
{
spinBox->setEnabled(false);
ok->setEnabled(false);
}

