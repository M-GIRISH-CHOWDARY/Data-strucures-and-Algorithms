#include<iostream>
using namespace std;
class queue
{ int *a;
  int size,f,r;
  public:
   queue(int);
   bool Enq(int );
   bool Deq(int &);
   bool isEmpty();
   bool isFull();
   bool getfront(int &);
   void makeEmpty();
};

queue::queue(int n)
{ size=n;
  a=new int[n];
  f=r=-1;
}
bool queue::Enq(int x)
{ if(isFull()!=true)
  { r++;
    a[r]=x;
    if(r==0)
    { f=0;}
    return true;
  }
  return false;
}
bool queue::Deq(int &x)
{ if(isEmpty())
   {return false;}
  x=a[f];
  if(f==r)
  {makeEmpty();}
  else
  {f++;}
  return true;
}
bool queue::isEmpty()
{ if(f==-1 && r==-1)
  {return true;}
  else
  {return false;}
}
bool queue::isFull()
{ if(r==(size-1))
   {return true;}
  else
   {return false;}
}
bool queue::getfront(int &x)
{ if(isEmpty())
   {return false;}
  x=a[f];
  return true;
}
void queue::makeEmpty()
{f=r=-1;}

int main()
{
queue q(5);
int c,e;
bool b;

do
{ cout<<"1.enter element,2.delete element,3.get front element,4.make empty"<<endl;
  cout<<"enter choice"<<endl;
  cin>>c;cout<<endl;
  if(c==1)
  { cout<<"enter element="<<endl;
    cin>>e;
    b=q.Enq(e);
    if(b)
    {cout<<"success"<<endl;}
    else
    {cout<<"queue is full";}
  }
  else if(c==2)
  { b=q.Deq(e);
    if(b)
    {cout<<"success"<<endl;
     cout<<"the deleted element is="<<e<<endl;
    }
    else
    {cout<<"queue is empty";} 
  }
  else if(c==3)
  { b=q.getfront(e);
    if(b)
    {cout<<"success"<<endl;
     cout<<"the front element="<<e<<endl;
    }
    else
    {cout<<"queue is  empty";}
  }
  else if(c==4)
  { q.makeEmpty();}
}
  
  while((c==1)||(c==2)||(c==3)||(c==4));
}
   

























 
