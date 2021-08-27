#include<iostream>
using namespace std;

class sorting
{ public: 
  void insertionsort(int a[],int n)
  { int i,j,key;
    for(j=0;j<=n-1;j++)
    { key=a[j];
      i=j-1;
      while(i!=-1 && a[i]>key)
      { a[i+1]=a[i];
        i--;
      }
      a[i+1]=key;
    }
  }
  
 void mergesort( int a[],int p,int r)
 { if(p>=r)
   { return;}
   int m;
   m=(p+r)/2;
   mergesort(a,p,m);
   mergesort(a,m+1,r);
   merge(a,p,m,r);
 }
 private:
 void merge(int a[],int p,int q,int r)
 { int n1,n2,i,j,k;
   n1=q-p+1;
   n2=r-q;
   int *l,*d;
   l=new int[n1+1];
   d=new int[n2+1];
   for(i=0,j=0,k=p;k<=r;k++)
   { if(k<=q)
     {l[i]=a[k];
	i++;
     }
     else
    {d[j]=a[k];
      j++;
    }
   }
   l[i]=999999;
   d[j]=999999;
   for(i=0,j=0,k=p;k<=r;k++)
   { if(l[i]<=d[j])
     {a[k]=l[i];
      i++;
     }
     else
     {a[k]=d[j];
	j++;
     }
   }
 }
public:
void quicksort(int a[],int s,int e)
{ int m;
   if(s>=e)
   {return;}
  m=partition(a,s,e);
  quicksort(a,s,m-1);
  quicksort(a,m+1,e);
}
 
private: 

int partition(int a[],int s,int e)
{ 
	int key;
    key=a[e];
    int i,j,t;
    for(i=s-1,j=s;j<=e;j++)
    {
  		if(a[j]<=key)
   		{
	    	i++;
    		t=a[i];
			a[i]=a[j];
			a[j]=t;
    	}
    } 
  return i;
} 
public:
void shellsort(int a[],int n)
{ int key,i,j,g;
  for(g=n/2;g>=1;g=g/2)
  { for(i=g;i<n;i++)
    { key=a[i];
      for(j=i;j-g>=0;j=j-g)
        { if(a[j-g]>key)
          { a[j]=a[j-g];}
          else
          {break;}
        }
      a[j]=key;
    }
  }
}

};

int main()
{ int n,choice;
  sorting s1;
  int a[40];
  cout<<"enter no of values"<<endl;
  cin>>n;
  cout<<"enter a values="<<endl;
  for(int i=0;i<n;i++)
  { cin>>a[i];
  }
  cout<<endl;
  int s,e;
  s=0;e=n-1;
  do
  { cout<<" 1.insertion sort \t2.mergesort \t 3.quicksort \t 4.shellsort"<<endl;
    cout<<"enter a choice=";
    cin>>choice;
    if(choice==1)
    {  s1.insertionsort(a,n);
       cout<<"array after sorting is"<<endl;
       for(int i=0;i<n;i++)
       { cout<<a[i]<<" ";
       }cout<<endl;
    }
    else if(choice==2)
    {  s1.mergesort(a,s,e);
       cout<<"array after sorting is"<<endl;
       for(int i=0;i<n;i++)
       { cout<<a[i]<<" ";
       }cout<<endl;
    }
    else if(choice==3)
    {  s1.quicksort(a,s,e);
       cout<<"array after sorting is"<<endl;
       for(int i=0;i<n;i++)
       { cout<<a[i]<<" ";
       }cout<<endl;
    }
    else if(choice==4)
    {  s1.shellsort(a,n);
       cout<<"array after sorting is"<<endl;
       for(int i=0;i<n;i++)
       { cout<<a[i]<<" ";
       }cout<<endl;
    }
  }

 while(choice==1||choice==2||choice==3||choice==4);
}
    



































