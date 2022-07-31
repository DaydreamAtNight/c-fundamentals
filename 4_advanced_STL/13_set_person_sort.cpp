#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Person
{
    string m_name;
    int m_age;
    int m_height;  
    
public:
    Person(string name, int age, int height)
    {
        m_name = name;
        m_age = age;
        m_height = height;
    };

    // member functions
    string get_name() const
    {
        return m_name;
    }

    int get_age() const
    {
        return m_age;
    }

    int get_height() const
    {
        return m_height;
    }
};

template<class T>
void printPersonList(string st, T v)
{
    cout << st << endl;
    for (typename T::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->get_name() << " "<< it->get_age() << " " << it->get_height() << endl;
    }
    cout << endl;
}

class sortPersonList
{
public:
    bool operator()(const Person& v1, const Person& v2) const
    {
        if (v1.get_age() == v2.get_age())
        {
            return  v1.get_height() < v2.get_height(); 
        }
        else
        {
            return v1.get_age() < v2.get_age();
        }
    }
};

int main()
{
    // the compare rule is nessary for the set with custom data type
    set<Person, sortPersonList> st;
    st.insert(Person("John", 20, 180));
    st.insert(Person("Mary", 23, 170));
    st.insert(Person("Bob", 22, 160));
    st.insert(Person("Jack", 23, 150));
    st.insert(Person("Jenny", 24, 140));

    printPersonList("set<Person> st", st);
}
