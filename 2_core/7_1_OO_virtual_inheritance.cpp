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

class baseClass1 : public baseBaseClass
{
};

class baseClass2 : public baseBaseClass
{
};

class childClass : public baseClass1, public baseClass2
{
}; // multiple inheritence is not recommanded in the real life

int main()
{
    childClass c;
    // c.m_a = 18; //  error: non-static member 'm_a' found in multiple base-class subobjects of type 'baseBaseClass':
    c.baseClass1::m_a = 18; //  error: non-static member 'm_a' found in multiple base-class subobjects of type 'baseBaseClass':
    c.baseClass2::m_a = 18; //  error: non-static member 'm_a' found in multiple base-class subobjects of type 'baseBaseClass':

    // only need one member varible m_a is needed, a waste of memory

    // virtual inheritance is useful in this situation.
    // virtual base pointer bvptr is inherited, making the data in both the base classes be the same.

    return 0;
}