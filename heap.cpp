#include<iostream>
using namespace std;

class heap
{ public:
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

  void buildmaxheap(int a[],int n)
  { int i;
    for(i=n/2;i>=1;i--)
    { maxheapify(a,n,i);}
  }

  void heapsort(int a[],int n)
  { buildmaxheap(a,n);
    while(n>1)
    {int t=a[1];
     a[1]=a[n];
     a[n]=t;
     
     n=n-1;
     
     maxheapify(a,n,1);
    }
  }
};

int main()
{
 int n,i;
 int a[40];
 cout<<"enter no of values=";
 cin>>n;
 cout<<"enter a array values="<<endl;
 for(i=1;i<n+1;i++)
 { cin>>a[i];
  }
 heap h;
 h.heapsort(a,n);
 cout<<"values after sorting="<<endl;
 for(i=1;i<n+1;i++)
 { cout<<a[i]<<"  ";}
}


