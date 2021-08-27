#include<iostream>
using namespace std;
template<typename T>
class test
{
T *a;
int n;
public:
void read();
void print();
test(int);
};
template<typename T>
void test<T>::read()
{
int i;
cout<<"enter elements"<<endl;
for(i=0;i<n;i++)
{
cin>>a[i];
}
}
template<typename T>
void test<T>::print()
{
int i;
for(i=0;i<n;i++)
{
cout<<a[i]<<endl;
}
}
template<typename T>
test<T>::test(int s)
{
n=s;
a=new T[n];
}
int main()
{
test<int>x(3);
x.read();
x.print();
test<float>y(3);
y.read();
y.print();
}

