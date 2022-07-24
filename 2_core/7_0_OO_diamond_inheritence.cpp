#include <iostream>
using namespace std;

class baseBaseClass
{
public:
    baseBaseClass()
    {
        m_a = 1;
    }
    int m_a;
};

class baseClass1 : virtual public baseBaseClass
{
};

class baseClass2 : virtual public baseBaseClass
{
};

class childClass : public baseClass1, public baseClass2
{
}; // multiple inheritence is not recommanded in the real life

int main()
{
    childClass c;
    c.m_a = 18;

    cout << &c.m_a << endl
         << &c.baseClass1::m_a << endl
         << &c.baseClass2::m_a << endl;
    cout << c.m_a << endl
         << c.baseClass1::m_a << endl
         << c.baseClass2::m_a << endl;

    // virtual inheritance is useful in this situation.
    // virtual base pointer is inherited, making the data in both the base classes be the same.

    return 0;
}