#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define srand (10086);

// aimed to group employees {A,B,C,D,E}
// each employee has two properties, name and salary
// these employess are randomly divided into 3 positions: UIDesign, frontEnd, backEnd
// salaries of these employees are also randomly assigned
// design a multimap with key(position index) and value(Employee object) to save all thess informations

template <class T>
class Employee
{
public:
    T m_name;
    int m_salary;

    Employee(const T & name, const int & salary = 0)
    {
        m_name = name;
        m_salary = salary;
    }

    friend ostream& operator<<(ostream& os, const Employee& employee)
    {
        os << employee.m_name << " " << employee.m_salary << ',';
        return os;
    }

};

template <class T>
void printList(string st, const T v)
{
    cout << st;
    for (typename T::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <class T1, class T2>
void printMap(string st, const multimap<T1, T2> &v)
{
    cout << st << endl;
    for (typename multimap<T1, T2>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << ": " <<  it->second << " ";
    }
    cout << endl;
}


int main()
{
    vector<Employee<char> > employees;
    multimap<int, Employee<char> > position_employee;
    
    for (int i=0; i<10; i++)
    {
        employees.push_back(Employee<char>(char(65+i),((rand()%41)+60)*100));
        position_employee.insert(make_pair(rand()%3,employees[i]));
    }
    printList("employees = ", employees);
    printMap("position_employee = ", position_employee);

    return 0;
}