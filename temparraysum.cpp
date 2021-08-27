#include<iostream>
using namespace std;
template<class T>
T sum(T a[],int n)
{
int i;
T s=0;
for(i=0;i<n;i++)
{
s=s+a[i];
}
return s;
}
int main()
{
int r1;
int s1[]={4,7,8};
r1=sum(s1,3);
cout<<r1<<endl;
float s2[]={4.5,2.0,3.8};
float r2;
r2=sum(s2,3);
cout<<r2<<endl;
return 0;
}
