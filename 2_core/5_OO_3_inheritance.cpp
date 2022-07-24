// /there are 3 properties in c++ oops: encapsulation, inheritance, polymorphism
// encapsulation: is the process of wrapping up the data and code in a single unit.
// inheritance: is the process of creating a new class that inherits the properties of another class.
// here only focus on inheritance and how it deal with memerber functions with the same name
#include <iostream>
using namespace std;

class baseClass
{
public:
    void func()
    {
        cout << "baseClass::func()" << endl;
    }

    void func(int a)
    {
        cout << "baseClass::func(int a)" << endl;
    }
};

class childClass : public baseClass
{
public:
    void func()
    {
        cout << "childClass::func()" << endl;
    }
};

int main()
{
    childClass c;
    c.func();
    // c.func(1); // error: too many arguments to function call, expected 0, have 1; did you mean 'baseClass::func'?
    c.baseClass::func(1); // error: too many arguments to function call, expected 0, have 1; did you mean 'baseClass::func'?
    return 0;
}