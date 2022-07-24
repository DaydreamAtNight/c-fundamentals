#include <iostream>
using namespace std;

int *pointer()
{
    int a = 10;
    return &a;
}

int main()
{
    int *p = pointer();
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}