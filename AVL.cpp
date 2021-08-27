#include<iostream>
using namespace std;

struct node
{ int data;
   node *left;
   node *right;
   int height;
 };

class avltree
{  node *R;
   public:
     avltree()
     { R=NULL;}
    void insert(int);
    void display();
  private:
    void insertof(node *&,int);
    int getheight(node *);
    void rightsingle(node *&);
    void rightdouble(node *&);
    void leftsingle(node *&);
    void leftdouble(node *&);
    int max(int,int);
    void inorder(node *);
};

void avltree::insert(int x)
{  insertof(R,x);
 }

void avltree::display()
{ inorder(R);}

int avltree::max(int a,int b)
{ return(a>b?a:b);}

int avltree::getheight(node *t)
{ return(t==NULL? -1: t->height);}

void avltree::rightsingle(node *&x)
{ node *t;
   t=x->left;
   x->left=t->right;
   t->right=x;
   x->height=max(getheight(x->left),getheight(x->right))+1;
   t->height=max(getheight(t->left),getheight(t->right))+1;
   x=t;
}

void avltree::leftsingle(node *&x)
{ node *t;
   t=x->right;
   x->right=t->left;
   t->left=x;
   x->height=max(getheight(x->left),getheight(x->right))+1;
   t->height=max(getheight(t->left),getheight(t->right))+1;
   x=t;
}

void avltree::rightdouble(node *&x)
{  leftsingle(x->left);
    rightsingle(x);
}

void avltree::leftdouble(node *&x)
{ rightsingle(x->right);
   leftsingle(x);
}

void avltree::insertof(node *&t,int x)
{ if(t==NULL)
   { t=new node;
      t->data=x;
      t->left=NULL;
      t->right=NULL;
      t->height=0;
   }
  else if(x<=t->data)
  {  insertof(t->left,x);
      if(getheight(t->left) - getheight(t->right)==2)
      { if(x<=t->left->data)
         { rightsingle(t);}
         else
         { rightdouble(t);}
      }
  }
  else
  {  insertof(t->right,x);
      if(getheight(t->right) - getheight(t->left)==2)
      { if(x<=t->right->data)
         { leftsingle(t);}
         else
         { leftdouble(t);}
      }
  }
  t->height=max(getheight(t->left),getheight(t->right))+1;
}

void avltree::inorder(node *R)
{ if(R==NULL)
   {return;}
   inorder(R->left);
   cout<<R->data<<"  "<<R->height<<endl;
   inorder(R->right);
}

int main()
{  avltree A;
    int choice;
    int x;
   do
   { cout<<"\n1.insert a value\n2.display\n";
      cout<<"enter a choice=";
      cin>>choice;
      if(choice==1)
     { cout<<"enter a insertion value=";
        cin>>x;
        A.insert(x);
        
      }
       if(choice==2)
      { A.display();}
   }
   while(choice==1||choice==2);
}







































































































