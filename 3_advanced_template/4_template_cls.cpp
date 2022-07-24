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

template <class nameType=string, class ageType=int>
class PersonWithDefauolt
{
    public:
        nameType m_name;
        ageType m_age;

        PersonWithDefauolt (nameType name, ageType age)
        {
            m_name = name;
            m_age = age;
        }

        void print_person()
        {
            cout << m_name << " " << m_age << endl;
        }
};


int main()
{
    Person<string, int> p1("John", 20);
    Person<string, int> p2("Mary", 21);
    // Person<> p3("Bob", 22); // there is no auto inference for template class
    // error: use of class template 'Person' requires template arguments
    PersonWithDefauolt<> p4("Bob", 22); // default template arguments are used

    p1.print_person();
    p2.print_person();
    p4.print_person();
}