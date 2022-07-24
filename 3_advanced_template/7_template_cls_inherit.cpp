#include <iostream>
using namespace std;

template <class T>
class Base
{
public:
    T m_data;
};

class child_class: public Base<int> // <> is a must, to specify the type of the template class
{
public:
    void print_child()
    {
        cout << m_data << endl;
    }
};

// alternativly, we can define a template child class
template <class T>
class child_template: public Base<T> // <> is a must, to specify the type of the template class
{
public:
    void print_child()
    {
        // cout << m_data << endl; // error: use of undeclared identifier 'm_data'; did you mean 'child_class::m_data'?
        cout << this->m_data << endl; // no error
        // see https://stackoverflow.com/questions/4643074/why-do-i-have-to-access-template-base-class-members-through-the-this-pointer?answertab=trending#tab-top
        // see https://stackoverflow.com/questions/11405/gcc-issue-using-a-member-of-a-base-class-that-depends-on-a-template-argument
        // see https://en.cppreference.com/w/cpp/language/two-phase_lookup
    
        // GCC parses templates before they are instantiated and thus finds more errors than VC
        // Short answer: in order to make x a dependent name, so that lookup is deferred until the template parameter is known
    }
};

int main()
{
    child_class child_obj1;
    child_obj1.m_data = 10;
    child_obj1.print_child();
    child_template<int> child_obj2;
    child_obj2.m_data = 20;
    child_obj2.print_child();
    return 0;
}