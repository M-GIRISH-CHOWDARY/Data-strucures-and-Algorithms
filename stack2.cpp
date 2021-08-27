#include<iostream>
using namespace std;
template<typename T>
class stack
{
 T *a;
 int size;
 int top;
 public:
 stack(int);
 bool push(T);
 bool pop(T &);
 bool peek(T &);
 bool isEmpty();
 bool isFull();
 void makeEmpty();
};
template<typename T>
stack<T>::stack(int n)
{
 size=n;
 top=-1;
 a=new T[n];
}
template<typename T>
bool stack<T>::isEmpty()
{
 if(top==-1)
 return true;
 else
 return false;
}
template<typename T>
bool stack<T>::isFull()
{
 if(top==size-1)
 return true;
 else
 return false;
}
template<typename T>
bool stack<T>::push(T x)
{
 if(!(isFull()))
 {
  top++;
  a[top]=x;
  return true;
 }
 else
 return false;
}
template<typename T>
bool stack<T>::pop(T &x)
{
 if(!(isEmpty()))
 {
  x=a[top];
  top--;
  return true;
 }
 else
{
 x=-1;
 return false;
}
}
template<typename T>
bool stack<T>::peek(T &x)
{
 if(!isEmpty())
 {
  x=a[top];
  return true;
 }
 else
 {
  x=-1;
  return false;
 }
}
template<typename T>
void stack<T>::makeEmpty()
{
 top=-1;
}
int main()
{
 int n,x,y,ch;
 cout<<"Enter size of stack"<<endl;
 cin>>n;
 stack<int> s(n);
 bool r;
 do
 {
  cout<<"1.push"<<endl<<"2.pop"<<endl<<"3.peek"<<endl<<"4.Check if Stack empty"<<endl<<"5.Check stack for full"<<endl;
 cin>>ch;
  switch(ch)
  {
   case 1: cin>>x;
          r=s.push(x);
          if(r)
          cout<<"Success";
          else
          cout<<"Stack overflow";
          break;
   case 2:r=s.pop(x);
         if(r)
         cout<<"Popped data: "<<x;
         else
         cout<<"Stack empty";
         break;
   case 3:r=s.peek(x);
         if(r)
         cout<<"Peek element: "<<x;
         else
          cout<<"Stack empty";break;
   case 4:r=s.isEmpty();
          if(r)
         cout<<"Stack empty";
         else
         cout<<"Stack is not empty";break;
   case 5:r=s.isFull();
         if(r)
         cout<<"Stack is filled";
         else
         cout<<"Stack contains some elements";
  }
  cout<<"Press 0 to Stop"<<endl;
 }while(ch!=0);
}

