// how to reload the template with a specific type
#include <iostream>
using namespace std;

class Person
{
public:
    string m_name;
    int m_age;

    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
};

template<class T>
void func(T & a, T & b)
{
    cout << a << " " << b << endl;
}

// template overload
template<> void func(Person & a, Person & b)
{
    cout << a.m_name << " " << a.m_age << endl;
    cout << b.m_name << " " << b.m_age << endl;
}


int main()
{
    Person p1("John", 20);
    Person p2("Mary", 21);
    func(p1, p2); 
    // if no template overload, it will error:
    // error: invalid operands to binary expression ('std::ostream' (aka 'basic_ostream<char>') and 'Person')
    // note: in instantiation of function template specialization 'func<Person>' requested here
    // this error can also be solved by operator overloading, or by using a normal function to overload the template
    return 0;
}