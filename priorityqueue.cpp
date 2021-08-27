#include<iostream>
using namespace std;

class pqueue
{
  public:
  
 void maxheapinsert(int a[],int &n,int x)
 { n++;
   a[n]=-99999;
   heapincreasekey(a,n,n,x);
 }
 
 void heapextractmax(int a[],int &n,int &x)
 { x=a[1];
   a[1]=a[n];
   n--;
   maxheapify(a,n,1);
 }
 
 void heapmaximum(int a[],int n,int &x)
 { x=a[1];}
 
 void buildmaxheap(int a[],int n)
  { int i;
    for(i=n/2;i>=1;i--)
    { maxheapify(a,n,i);}
  }

 void heapincreasekey(int a[],int n,int i,int key)
 { int p;
   if(i>n||i<1)
   { return;}
   if(a[i]>=key)
   {return;}
   a[i]=key;
   p=i/2;
   while(p>=1&&a[p]<a[i])
   {int t=a[p];a[p]=a[i];a[i]=t;
    i=p;
    p=i/2;
   }
 }
 
 void maxheapify(int a[],int n,int i)
  { int l,r,max;
    l=2*i;
    r=2*i+1;
    max=i;
    if(l<=n && a[l]>a[max])
    { max=l;}
    if(r<=n && a[r]>a[max])
    { max=r;}
    if(max!=i)
    {int t=a[i];a[i]=a[max];a[max]=t;
     maxheapify(a,n,max);
    }
  }
};

int main()
{ int n=0,i,choice,x;
  int a[100];
  pqueue q;
  /*cout<<"enter no of values="<<endl;
  cin>>n;
  
  cout<<"enter a value to array="<<endl;
  for(i=1;i<n+1;i++)
  {cin>>a[i];}
  q.buildmaxheap(a,n);
  for(i=1;i<n+1;i++)
  { cout<<a[i]<<"  ";}*/
  
  cout<<"\n\t 1.inserting \n\t 2.extracting \n\t 3.top value"<<endl;
  
  
  do
  { cout<<"enter a choice=";
    cin>>choice;
    if(choice==1)
    { 
    
    cout<<"enter a value="<<endl;
      cin>>x;
      q.maxheapinsert(a,n,x);
      for(i=1;i<n+1;i++)
      { cout<<a[i]<<"  ";}
    }
    else if(choice==2)
    { q.heapextractmax(a,n,x);
      cout<<"the deleted value="<<x<<endl;
    }
    else if(choice==3)
    { q.heapmaximum(a,n,x);
      cout<<"the top value="<<x<<endl;
      
    }
  }
  while(choice==1||choice==2||choice==3);

}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
