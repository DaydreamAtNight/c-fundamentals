#include<iostream>
using namespace std;

template<typename T> // same as template<class T>
void swap_var(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test_int()
{
    int a=1,b=2;
    swap_var(a,b); // auto inference for T
    cout<<a<<" "<<b<<endl;
}

void test_double()
{
    double a=1.,b=2.;
    swap_var<double>(a,b); // explicit template instantiation for T 
    cout<<a<<" "<<b<<endl;
}

int main()
{
    test_int();
    test_double();
    return 0;
}