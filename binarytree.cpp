#include<iostream>
using namespace std;
struct Node
{
 int data;
 Node *left;
 Node *right;
};
class bst
{ Node *r;
  public:
   bst();
   bool insert(int);
   bool Delete(int);
   bool findmin(int&);
   bool findmax(int&);
   void display(int);
  private:
   bool Deletere(Node*&,int);
   void inorder(Node*,int);
};

bst::bst()
{ r=NULL;}

bool bst::insert(int x)
{ Node *n;
  n=new Node;
  if(n==NULL) 
  { return false;}
  n->data=x;
  n->left=NULL;
  n->right=NULL;
  if(r==NULL)
  { 
    r=n;
    return true;
  }
  Node *t,*p;
  p=NULL;
  t=r;
  while(t!=NULL)
  { p=t;
    if(x<=t->data)
    {t=t->left;}
    else
    {t=t->right;}
  }
  if(x<=p->data)
  {p->left=n;}
  else
  {p->right=n;}
  return true;
}

bool bst::findmin(int &x)
{ if(r==NULL)
  { return false;}
  Node *t;
  t=r;
  while(t->left!=NULL)
  {t=t->left;}
  x=t->data;
  return true;
}

bool bst::findmax(int &x)
{ if(r==NULL)
  { return false;}
  Node *t;
  t=r;
  while(t->right!=NULL)
  {t=t->right;}
  x=t->data;
  return true;
}

bool bst::Delete(int x)
{ return Deletere(r,x);}

bool bst::Deletere(Node *&r,int x)
{ Node *t;
  int tmp;
  if(r==NULL)
  { return false;}
  if(x==r->data)
  { if(r->left==NULL)
     { t=r;
       r=r->right;
       delete(t);
       return true;
     }
    else if(r->right==NULL)
     { t=r;
       r=r->left;
       delete(t);
       return true;
     }
    else
     { t=r->right;
       while(t->left!=NULL)
        { t=t->left;}
       tmp=r->data;
       r->data=t->data;
       t->data=tmp;
       return Deletere(t,t->data);
     }
  }
  else if(x<r->data)
  { return Deletere(r->left,x);}
  else if(x>r->data)
  { return Deletere(r->right,x);}
}
 
void bst::display(int n)
{ return inorder(r,n);}

void bst::inorder(Node *r,int n)
{ if(r==NULL)
  {return;}
  inorder(r->left,n);
	if(r->data==n)
	{
		cout<<"Found";
	}
  inorder(r->right,n);
}

int main()
{ bst m;
  int choice;
  int x;
  do
  { cout<<"\n1.insert a element\n2.delete a element\n3.find a minimum\n4.find a maximum\n5.display\n";
    cout<<"enter the choice=";
    cin>>choice;
    cout<<endl;
    if(choice==1)
    { cout<<"enter the value=";
      cin>>x;
      cout<<endl;
      bool b=m.insert(x);
      if(b)
      {cout<<"insertion is success\n";}
      else
      {cout<<"insertion is failure\n";}
    }
    
    else if(choice==2)
    { cout<<"enter the delete value=\n";
      cin>>x;
      cout<<endl;
      bool b=m.Delete(x);
      if(b)
      {cout<<"deletion is successful\n";}
      else
      {cout<<"deletion is failure\n";}
    }
    
    else if(choice==3)
    { bool b=m.findmin(x);
      if(b)
      {cout<<"the minimum value="<<x<<endl;}
      else
      {cout<<"minimum value not found\n";}
    }  
      
   else if(choice==4)
    { bool b=m.findmax(x);
      if(b)
      {cout<<"the maximum value="<<x<<endl;}
      else
      {cout<<"maximum value not found\n";}
    }
   
   else if(choice==5)
   {m.display(32);}
  /* else if(choice==6)
   {
   	cin>>x; bool b;
   	b=m.search(x);
   	if(b)
   	cout<<"found";
   	else
   	cout<<"not found";
   }*/
  }
    
    while(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6);
}  
      

