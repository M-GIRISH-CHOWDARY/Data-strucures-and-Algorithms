#include<iostream>
using namespace std;
int main()
{
int i,j,temp,a[20],n,flag;
cout<<"enter no.of elements";
cin>>n;
for(i=0;i<n;i++)
{
flag=0;
cin>>a[i];
}
for(i=0;i<n-1,flag==0;i++)
{
flag=1;
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
    {
     flag=0;
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }
}
}
cout<<"elements sorted successfully:\n";
cout<<"sorted list in ascendig order:\n";
for(int i=0;i<n;i++)
{
cout<<a[i]<<"";
}
}


