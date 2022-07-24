#include<iostream>
#include"11_generic_array.hpp"
using namespace std;

template <class T1, class T2>
class customData
{
    T1 m_d1;
    T2 m_d2;
public:
    customData(){} // this default constructor is a must
    // The compiler does not generate such a default constructor anymore, because your class has a user defined constructor that takes 2 parameters.

    customData(T1 d1, T2 d2)
    {
        this->m_d1 = d1;
        this->m_d2 = d2;
    }
    T1 getD1()
    {
        return m_d1;
    }

    T2 getD2()
    {
        return m_d2;
    }
};

class customData2
{
    int m_d1;
    string m_d2;
public:
    customData2(){}

    customData2(int d1, string d2)
    {
        this->m_d1 = d1;
        this->m_d2 = d2;
    }
    int getD1()
    {
        return m_d1;
    }

    string getD2()
    {
        return m_d2;
    }
};


void test_int()
{
    GenericArray<int> a(100);
    for (int i = 0; i < 20; i++)
    {
        a.add(i+1);
    }

    for (size_t i = 0; i < a.getSize(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    GenericArray<int> b(a);

    cout << "size of a " << a.getSize() << endl;
    cout << "capacity of a " << a.getCapacity() << endl;

    cout << "size of b " << b.getSize() << endl;
    cout << "capacity of b " << b.getCapacity() << endl;

    b.add(21);
    b.add(22);
    a=b;

    cout << "size of a " << a.getSize() << endl;
    cout << "capacity of a " << a.getCapacity() << endl;
    
    cout << "size of b " << b.getSize() << endl;
    cout << "capacity of b " << b.getCapacity() << endl;    
}

void test_custom()
{
    
    GenericArray< customData<int, char> > g_array(100);
    for(int i=0; i<10; i++)
    {
        g_array.add(customData<int, char>(i, 'a'));
    }

    for(size_t i=0; i<g_array.getSize(); i++)
    {
        cout << g_array[i].getD1() << " " << g_array[i].getD2() << endl;
    }
}

void test_custom2()
{
    
    GenericArray< customData2 > g_array2(100);
    for(int i=0; i<10; i++)
    {
        g_array2.add(customData2(i, "a"));
    }

    for(size_t i=0; i<g_array2.getSize(); i++)
    {
        cout << g_array2[i].getD1() << " " << g_array2[i].getD2() << endl;
    }

}
int main()
{
    // test_int();
    test_custom();
    // test_custom2();

    return 0;
}
