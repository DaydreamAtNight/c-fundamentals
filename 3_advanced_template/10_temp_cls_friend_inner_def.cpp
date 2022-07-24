#include <iostream>
using namespace std;

template <class nameType, class ageType>
class Person
{
    friend void print_person(Person<nameType, ageType> & person) // easy, highly recommanded
    {
        cout << person.m_name << " " << person.m_age << endl;
    }

    nameType m_name;
    ageType m_age;

public:
    Person (nameType name, ageType age)
    {
        m_name = name;
        m_age = age;
    }
};


int main()
{
    Person<string,int> p("John",20);
    print_person(p);
    return 0;
}