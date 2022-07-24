#include<iostream>
using namespace std;

void swap_int(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_double(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void test_int()
{
    int a=1,b=2;
    swap_int(a,b);
    cout<<a<<" "<<b<<endl;
}

void test_double()
{
    double a=1.,b=2.;
    swap_double(a,b);
    cout<<a<<" "<<b<<endl;
}

int main()
{
    test_int();
    test_double();
    return 0;
}