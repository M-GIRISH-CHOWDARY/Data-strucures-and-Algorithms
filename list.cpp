struct Node
{
 int data;
 Node *next;
};
#include<iostream>
using namespace std;

class list
{ Node *a;
  int count;
  public:
   list();
   bool insert(int);
   bool search(int);
   void display();
   bool insertbeg(int);
   bool insertp(int,int);
   bool Deletelast(int&);
   bool Deletefirst(int&);   
};

list::list()
{ a=NULL;
  count=0;
}

bool list::insert(int x)
{ Node *n;
  n=new Node;
  if(n==NULL)
  { return false;}
  n->data=x;
  n->next=NULL;
  if(a==NULL)
  {a=n;}
  else
  {Node *t;
   t=a;
  while(t->next!=NULL)
  {t=t->next;}
  t->next=n;
  }
  count++;
  return true;
}

bool list::search(int x)
{ if(a==NULL)
  {cout<<"Empty"<<endl;}
   int c=x;
   Node *t;
   t=a;
   while(t!=NULL)
   {if(t->data==c)
    {return true;}
    t=t->next;
   }
  return false;
}

void list::display()
{ if(a==NULL)
  {cout<<"Empty"<<endl;}
  Node *t;
  t=a;
  cout<<"the elements in list=\n";
  while(t!=NULL)
  {cout<<t->data<<endl;
   t=t->next;
  }
  cout<<"total elements in list="<<count<<endl;
}

bool list::insertbeg(int x)
{ Node *n;
  n=new Node;
  if(n==NULL)
  { return false;}
  n->data=x;
  n->next=NULL;
  if(a==NULL)
  {a=n;}
  else
  {
   n->next=a;
   a=n;
  }
  count++;
  return true;
}

bool list::insertp(int x,int p)
{ int e=p;
  if(e<1 ||e>(count+1))
  {return false;}
  if(e==1)
  {return(insertbeg(x));}
  Node *n;
  n=new Node;
  if(n==NULL)
  { return false;}
  n->data=x;
  n->next=NULL;
  Node *t;int cnt;
  t=a;cnt=1;
  while(cnt!=(e-1))
  {t=t->next;
   cnt++;
  }
  n->next=t->next;
  t->next=n;
  count++;
  return true;
}

bool list::Deletelast(int &x)
{ if(a==NULL)
  {return false;}
  Node *p;
  Node *t;
  t=a;
  p=NULL;
  while(t->next!=NULL)
  {p=t;
   t=t->next;
  }
  if(p!=NULL)
  {p->next=NULL;
   x=t->data;
   delete(t);
   count--;
   return true;
  }
  else
  {a=NULL;
   x=t->data;
   count=0;
   delete(t);
   return true;
  }
}

bool list::Deletefirst(int &x)
{ if(a==NULL)
  { return false;}
  Node *t;
  t=a;
  a=t->next;
  x=t->data;
  delete(t);
  count--;
  return true;
}

int main()
{ list l;int choice;
  
  do
  { cout<<"1.insert a value\n2.search a value\n3.to display a list\n4.insert at begining\n";
    cout<<"5.insert at position\n6.delete at last\n7.delete st first"<<endl;
    cout<<"enter the choice=";
    cin>>choice;
    cout<<endl;
     if(choice==1) 
     {int x;
      cout<<"enter the element=";
      cin>>x;
      bool q=l.insert(x);
      if(q)
      {cout<<"success inserting element"<<endl;}
      else
      {cout<<"failed inserting element"<<endl;}
     }
    else if(choice==2)
    {int x;
     cout<<"enter the searching value=";
     cin>>x;
     bool w=l.search(x);
     if(w)
     {cout<<"found"<<endl;}
     else
     {cout<<"not found"<<endl;}
    }
    else if(choice==3)
    { l.display();}
    else if(choice==4)
    { int x;
      cout<<"enter the element=";
      cin>>x;
      bool q=l.insertbeg(x);
      if(q)
      {cout<<"success inserting element"<<endl;}
      else
      {cout<<"failed inserting element"<<endl;}
    }
    else if(choice==5)
    { int x,p;
      cout<<"enter the element=";
      cin>>x;
      cout<<"enter the postion=";
      cin>>p;
      bool e=l.insertp(x,p);
     if(e)
     {cout<<"success inserting element"<<endl;}
     else
     {cout<<"failed inserting element"<<endl;}
    }
    else if(choice==6)
    {int x;
     bool c=l.Deletelast(x);
     if(c)
     {cout<<"success in deleting"<<endl;
      cout<<"the deleted value="<<x<<endl;
     }
     else
     {cout<<"failed in deleting"<<endl;}
    }
    else if(choice==7)
    { int x;
      bool c=l.Deletefirst(x);
      if(c)
      {cout<<"success in deleting"<<endl;
      cout<<"the deleted value="<<x<<endl;
      }
      else
      {cout<<"failed in deleting"<<endl;}
    }
  }
  while(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7);
}






