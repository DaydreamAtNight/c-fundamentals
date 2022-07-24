#include <iostream>
using namespace std;

class baseClass1
{
public:
    baseClass1()
    {
        m_a = 1;
    }
    int m_a;
};

class baseClass2
{
public:
    baseClass2()
    {
        m_a = 2;
        m_b = 3;
    }
    int m_a, m_b;
};

class childClass : public baseClass1, public baseClass2 // multiple inheritence is not recommanded in the real life
{
public:
    childClass()
    {
        m_c = 4;
        m_d = 5;
    }
    int m_c, m_d;
};

int main()
{
    childClass c;
    cout << c.m_b << endl;
    cout << c.m_c << endl;
    // cout << c.m_a << endl; // error: member 'm_a' found in multiple base classes of different types
    cout << c.baseClass1::m_a << endl;

    return 0;
}