#include<iostream>
using namespace std;
struct Node
{ int data;
  Node *next;
  Node *prev;
};

class dlist
{ Node *a;
  int count;
  public:
   dlist();
   bool insert(int);
   bool insertatfront(int);
   void display();
   bool Deletelast(int &);
   bool Deletefirst(int &);
   bool Delete(int);
   bool search(int);
   bool insertorder(int);
   
};

dlist::dlist()
{a=NULL;
 count=0;
}

bool dlist::insert(int x)
{ Node *n;
  n=new Node;
  if(n==NULL)
  { 
  	return false;
  }
  n->data=x;
  n->next=NULL;
  n->prev=NULL;
  if(a==NULL)
  { 
  	a=n;
    	count++;
    	return true;
  }
  else
  {  
  	Node *t;
  	t=a;
  	while(t->next!=NULL)
  	{ 
  		t=t->next;
  	}
   	t->next=n;
   	n->prev=t;
   	count++;
   	return true;
   }
}

void dlist::display()
{ 
	if(a==NULL)
   	{ 
   		cout<<"list is empty";
     		return;
   	}
  	Node *t;
  	t=a;
  	while(t!=NULL)
  	{
   		cout<<t->prev<<"  ";
   		cout<<t->data<<"  ";
   		cout<<t->next<<"  ";
   		cout<<endl;
   		t = t->next;
  	}
}

bool dlist::Deletelast(int &x)
{ if(a==NULL)
   { return false;}
  Node *t;
  t=a;
  while(t->next!=NULL)
  { t=t->next;}
    t->prev->next=NULL;
    x=t->data;
    count--;
    return true;
}

bool dlist::Delete(int x)
{ if(a==NULL)
   { return false;}
  Node *t;
  t=a;
  while(t!=NULL)
  { if(x==t->data)
    { if(t->prev==NULL)
      { a=t->next;
        if(t->next!=NULL)
        {t->next->prev=NULL;}
      }
      else if(t->next==NULL)
      {t->prev->next=NULL;}
      else
      { t->prev->next=t->next;
        t->next->prev=t->prev;
      }
      delete(t);
      count--;
      return true;
     }
     t=t->next;
    }
    return false;
}

bool dlist::insertorder(int x)
{ Node *n;
  n=new Node;
  if(n==NULL)
  { return false;}
  n->data=x;
  n->next=NULL;
  n->prev=NULL;
  if(a==NULL)
  { a=n;
    count++;
    return true;
  }
  Node *t;
  t=a;
  while(t!=NULL)
  { if(n->data<=t->data)
    { n->next=t;
      n->prev=t->prev;
      if(t->prev==NULL)
      { a=n;}
      else
      {
      	t->prev->next=n;
      }
      t->prev=n;
      count++;
      return true;
    }
     else if(t->next==NULL)
    { t->next=n;
      n->prev=t;
      count++;
      return true;
    }
   
    t=t->next;
  }
}

bool dlist::insertatfront(int x)
{ Node *n;
  n=new Node;
  if(n==NULL)
  { return false;}
  n->data=x;
  n->next=NULL;
  n->prev=NULL;
  if(a==NULL)
   {a=n;}
  else
  {Node *t;
   t=a;
   n->next=a;
   a=n;
   t->prev=n;
  }
   count++;
   return true;
}

bool dlist::search(int x)
{ if(a==NULL)
  { return false;}
  Node *t;
  t=a;
  while(t!=NULL)
  { if(t->data==x)
    {return true;}
    t=t->next;
  }
  return false;
}

bool dlist::Deletefirst(int &x)
{ if(a==NULL)
  { return false;}
  Node *t;
  t=a;
  if(t->next!=NULL)
  {a=t->next;
   t->next->prev=NULL;
  }
  else
  {a=t->next;}
  x=t->data;
  delete(t);
  count--;
}

int main()
{ dlist m;
  int choice;int x;
  do
  {cout<<"\n1.inserting element\n2.display dlist\n3.delete last element\n4.delete first value\n";
   cout<<"5.delete certain value\n6.insert at front\n7.insert in order\n8.searching a element\n";
   cout<<"\nenter the choice=";
   cin>>choice;
   cout<<endl;
   if(choice==1)
   { 
     cout<<"enter a inserting value=";
     cin>>x;
     cout<<endl;
     bool b=m.insert(x);
     if(b)
     {cout<<"insertion is success"<<endl;}
     else
     {cout<<"insertion is failure"<<endl;}
   }
   else if(choice==2)
   { m.display();}
   else if(choice==3)
   { bool b=m.Deletelast(x);
     if(b)
     {cout<<"deletion is success"<<endl;
      cout<<"the deleted value="<<x<<endl;
     }
     else
     {cout<<"deletion is failure"<<endl;}
   }
   else if(choice==4)
   {bool b=m.Deletefirst(x);
    if(b)
     {cout<<"deletion is success"<<endl;
      cout<<"the deleted value="<<x<<endl;
     }
     else
     {cout<<"deletion is failure"<<endl;}
   }
   else if(choice==5)
   {cout<<"enter the delete value=";
    cin>>x;
    bool b=m.Delete(x);
    if(b)
     {cout<<"deletion is success"<<endl;}
     else
     {cout<<"deletion is failure"<<endl;}
   }
   else if(choice==6)
   { cout<<"enter a inserting value=";
     cin>>x;
     cout<<endl;
     bool b=m.insertatfront(x);
     if(b)
     {cout<<"insertion is success"<<endl;}
     else
     {cout<<"insertion is failure"<<endl;}
   }
   else if(choice==7)
   { cout<<"enter a inserting value=";
     cin>>x;
     cout<<endl;
     bool b=m.insertorder(x);
     if(b)
     {cout<<"insertion is success"<<endl;}
     else
     {cout<<"insertion is failure"<<endl;}
   }
   else if(choice==8)
   { cout<<"enter the searching value=";
     cin>>x;
     bool b=m.search(x);
     if(b)
     {cout<<"searching value found"<<endl;}
     else
     {cout<<"searching value not found"<<endl;}
    }
  }
  while(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7||choice==8);
}










