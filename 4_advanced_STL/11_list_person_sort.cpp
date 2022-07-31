// try to construct a linked list of custom Person class objects
// then sorted with age as primaray critera, height as secondary critera
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Person
{
private:
    string* m_name;
    int* m_age;
    int* m_height;

public:
    // constructors
    Person()
    {
        m_name = new string("");
        m_age = new int(0);
        m_height = new int(0);
    };

    Person(string name, int age, int height)
    {
        // cout << "constructor" << endl;
        m_name = new string(name);
        m_age = new int(age);
        m_height = new int(height);
    };

    Person(Person& p)
    {
        // cout << "copy" << endl;
        this -> m_name = new string(p.get_name());
        this -> m_age = new int(p.get_age());
        this -> m_height = new int(p.get_height());
    };

    // deconstructor
    ~Person()
    {
        // cout << "deconstructor" << endl;
        if (m_name != NULL)
        {
            delete m_name;
            m_name = NULL;
        }

        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }

        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
    }
    
    // member functions
    string get_name()
    {
        return *m_name;
    }

    int get_age()
    {
        return *m_age;
    }

    int get_height()
    {
        return *m_height;
    }

};

class PersonNoNew
{
    string m_name;
    int m_age;
    int m_height;  
    
public:
    PersonNoNew(string name, int age, int height)
    {
        m_name = name;
        m_age = age;
        m_height = height;
    };

    // member functions
    string get_name()
    {
        return m_name;
    }

    int get_age()
    {
        return m_age;
    }

    int get_height()
    {
        return m_height;
    }
};

// void test_person_class()
// {
//     Person p1("lishoushou", 25, 175);
//     cout << p1.get_name() << " "<< p1.get_age() << " " << p1.get_height() << endl;
//     Person p2("chenrourou", 6, 165);
//     cout << p2.get_name() << " "<< p2.get_age() << " " << p2.get_height() << endl;
//     Person p3(p2);
//     cout << p3.get_name() << " "<< p3.get_age() << " " << p3.get_height() << endl;
// }

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

bool sortPersonList(PersonNoNew &v1, PersonNoNew &v2)
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

void linked_list()
{
    list<PersonNoNew> person_list;

    // initialise:
    person_list.push_back(PersonNoNew("lishoushou", 25, 175)); // list and vector only valid for normal class, with out "new"
    person_list.push_back(PersonNoNew("chenrourou", 6, 165));
    person_list.push_back(PersonNoNew("chenzijing", 40, 170));
    person_list.push_back(PersonNoNew("hobbit", 140, 120));
    person_list.push_back(PersonNoNew("Hermione", 40, 155));
    person_list.push_back(PersonNoNew("harry", 40, 160));

    // print
    printPersonList("person_lsit initialize: ", person_list);

    person_list.sort(sortPersonList);

    printPersonList("person_lsit initialize: ", person_list);


}

int main()
{
    // test_person_class();
    linked_list();
    return 0;
}