#include<iostream>
using namespace std;
template<class T>
T fun(T a,T b)
{
T c;
c=a+b;
return c;
}
int main()
{
int s1;
s1=fun(10,15);
cout<<s1<<endl;
float s2;
s2=fun(10.5,15.2);
cout<<s2;
}
