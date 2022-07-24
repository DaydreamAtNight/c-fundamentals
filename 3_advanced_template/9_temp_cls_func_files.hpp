#include <iostream>
using namespace std;

template <class nameType, class ageType>
class Person
{
public:
    nameType m_name;
    ageType m_age;

    Person (nameType name, ageType age);
    void print_person();
};

template <class nameType, class ageType>
Person<nameType, ageType>::Person (nameType name, ageType age)
{
    m_name = name;
    m_age = age;
}

template <class nameType, class ageType>
void Person<nameType, ageType>::print_person()
{
    cout << m_name << " " << m_age << endl;
}