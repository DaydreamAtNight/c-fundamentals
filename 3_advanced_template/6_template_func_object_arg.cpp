// demonstration on how to use objectg of a templatete class as a function argument

#include <iostream>
using namespace std;

template <class nameType, class ageType>
class Person
{
public:
    nameType m_name;
    ageType m_age;

    Person (nameType name, ageType age)
    {
        m_name = name;
        m_age = age;
    }

    void print_person()
    {
        cout << m_name << " " << m_age << endl;
    }
};

// method 1
void print_person_func1(Person<string, int> &p)
{
    p.print_person();
}

// method 2
template<class T1, class T2>
void print_person_func2(Person<T1, T2> &p)
{
    p.print_person();
    // check type of template class
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
}

// method 3
template<class T>
void print_person_func3(T &p)
{
    p.print_person();
    // check type of template class
    cout << typeid(T).name() << endl;
}

int main()
{
    Person<string, int> p1("John", 20);
    print_person_func1(p1); // most useful
    cout<<"----------------------------------------------------"<<endl;
    print_person_func2(p1);
    cout<<"----------------------------------------------------"<<endl;
    print_person_func3(p1);
}