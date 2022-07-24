#include <iostream>
using namespace std;

class Person1
{
public:
    string m_name;
    int m_age;

    Person1()
    {
        m_name = "Marry";
        m_age = 32;
    }

    void print_person1()
    {
        cout << m_name << " " << m_age << endl;
    }
};

class Person2
{
public:
    string m_name;
    int m_age;

    Person2()
    {
        m_name = "John";
        m_age = 35;
    }

    void print_person2()
    {
        cout << m_name << " " << m_age << endl;
    }
};

template <class T>
class ShowPerson
{
    T person_obj;

public:
    void show_person1()
    {
        person_obj.print_person1();
    }

    void show_person2()
    {
        person_obj.print_person2();
    }
};

int main()
{
    ShowPerson <Person1> show_person1;
    show_person1.show_person1();

    ShowPerson <Person2> show_person2;
    show_person2.show_person2();

    // this works because the member function in template class is created only when being called
}