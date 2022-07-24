#include <iostream>
using namespace std;

class baseClass
{
public:
    // virtual function pointer vfptr point to vftable
    virtual void func() // no virtual, no polymorphism
    {
        cout << "baseClass::func()" << endl;
    }
};

class childClass1 : public baseClass
{
public:
    void func() // rewrite the same func, rewrite is different freom reloud.
    {
        cout << "childClass1::func()" << endl;
    }
};

class childClass2 : public baseClass
{
public:
    void func() // rewrite the same func, rewrite is different from reload.
    {
        cout << "childClass2::func()" << endl;
    }
};

void test_func(baseClass &c) // baseclass, reference or point to the childClass func
{
    c.func();
}

int main()
{
    childClass1 c1;
    childClass2 c2;
    test_func(c1);
    test_func(c2);

    return 0;
}