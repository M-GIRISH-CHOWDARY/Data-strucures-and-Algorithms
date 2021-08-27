#include<iostream>
using namespace std;
class Stack
{
 int *a;
 int size;
 int top;
public:
 Stack(int);
 bool push(int);
 bool pop(int&);
 bool peep(int&);
 bool isEmpty();
 bool isFull();
 void makeEmpty();
};
Stack ::Stack(int n)
{size=n;
 top=-1;
 a=new int[n];
}
bool Stack::isEmpty()
 {if(top==-1)
    return true;
  else
    return false;
 }
bool Stack::isFull()
 { if(top==(size-1))
     return true;
   else
     return false;
 }
bool Stack::push(int x)
 {if(!isFull())
   {top++;
    a[top]=x;
    return true;
   }
  return false;
 }
bool Stack::pop(int &x)
 {if(!isEmpty())
   {x=a[top];
    top--;
    return true;
   }
   return false;
 }
bool Stack::peep(int &x)
 {if(!isEmpty())
   {x=a[top];
     return true;
   }
  return false;
 }
void Stack::makeEmpty()
 {
   top=-1;
 }

int main()
{
 Stack s(4);
 bool r;int x,y;

 do
 {cout<<"1.push,2.pop,3.peep,4.makeempty"<<endl;
  cin>>y;
  if(y==1)
   {cout<<"enter the element=";
    cin>>x;
    cout<<endl;
    r=s.push(x);
    if(r)
    {cout<<"success"<<endl;}
    else
    {cout<<"stack overflow"<<endl;}
   }
  else if(y==2)
   {r=s.pop(x);
    if(r)
    {cout<<"success"<<endl;
     cout<<"the deleted element is="<<x;
     cout<<endl;
    }
    else
    {cout<<"stack is empty"<<endl;}
   }
  else if(y==3)
   {r=s.peep(x);
    if(r)
    {
     cout<<"success"<<endl;
     cout<<"the top element in stack="<<x;
     cout<<endl;
    }
    else
    {cout<<"stack is empty"<<endl;}
   }
  else if(y==4)
   {s.makeEmpty();}
 }
while( (y==1)||(y==2)||(y==3)||(y==4));


}




























































