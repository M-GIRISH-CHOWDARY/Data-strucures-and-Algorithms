#include<iostream>
using namespace std;
int main()
{
int i,j,temp,a[20],n;
cout<<"enter total no.of elements";
cin>>n;
cout<<"enter numbers";
int flag=0;
for(i=0;i<n;i++)
{
	cin>>a[i];
}

for(i=0;i<n,flag==0;i++)
{
flag=1;
{
if(a[j]<a[j+1])
{
  flag=0;

  temp=a[j];
   j=i-1;
}         
}
}
                               

while(j>=0 && a[j]>temp)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=temp;

cout<<"sorted elements after inserting ";
for(i=0;i<n;i++)
{
cout<<a[i]<<"";
}
}



