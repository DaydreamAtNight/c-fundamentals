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