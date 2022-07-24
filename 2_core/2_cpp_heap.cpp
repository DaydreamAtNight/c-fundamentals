#include <iostream>
using namespace std;

int *pointer()
{
    int *pp = new int[10];
    for (int i = 0; i < 10; i++)
    {
        pp[i] = i;
    }
    return pp;
}

int main()
{
    int *p = pointer();
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    delete[] p;
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}