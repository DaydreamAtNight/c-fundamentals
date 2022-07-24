// use vector to store custom data type
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class foo
{
    int m_a;
    string m_b;

    public:
    foo(){}

    foo(int a, string b)
    {
        m_a = a;
        m_b = b;
    }
    int get_a()
    {
        return m_a;
    }
    string get_b()
    {
        return m_b;
    }

    friend ostream& operator<<(ostream& os, const foo& foo_d)
    {
        os << foo_d.m_a << " " << foo_d.m_b;
        return os;
    }

};

inline void print_element(int element)
{
    cout << element << endl;
}

void test_vector()
{
    vector<foo> v;
    
    for(int i; i<10; i++)
    {
        v.push_back( foo (i, "foo") );
    }

    // get access to the elements in vector

    // 1. iterator
    // vector<int>::iterator itBegin=v.begin();
    // vector<int>::iterator itEnd=v.end();
    // while(itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // 2. iterator
    // for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // 3. for_each
    // for_each(v.begin(), v.end(), print_element);

    // 4. for_each with lambda function, requires complie with c++11, g++ -std=c++11  your_file.cpp
    for_each(v.begin(), v.end(), [](foo element){
        cout << element << endl;
    });

}

int main()
{
    test_vector();
    return 0;
}
 