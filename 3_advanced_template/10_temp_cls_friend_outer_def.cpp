#include <iostream>
using namespace std;

template <class nameType, class ageType>
class Person;                               // forward declaration if not error: no template named 'Person'

template <class nameType, class ageType>   // friend function defore the template class
void print_person(Person<nameType, ageType> & person)
{
    cout << person.m_name << " " << person.m_age << endl;
}


template <class nameType, class ageType>
class Person
{
    // friend void print_person(Person<nameType, ageType> & person); // clang: error: linker command failed with exit code 1 (use -v to see invocation)
    friend void print_person<>(Person<nameType, ageType> & person); // error: no candidate function template was found for dependent friend function template specialization


    nameType m_name;
    ageType m_age;

public:
    Person (nameType name, ageType age);
};

template <class nameType, class ageType>
Person<nameType, ageType>::Person (nameType name, ageType age)
{
    m_name = name;
    m_age = age;
}



int main()
{
    Person<string,int> p("John",20);
    print_person(p);
    return 0;
}