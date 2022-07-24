// introduce to STL vector
// container: vector
// algorithm: for_each
// iterator: vector<int>::iterator

// use vector to store standard data type
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

inline void print_element(int element)
{
    cout << element << endl;
}

void test_vector()
{
    vector<int> v;
    
    for(int i; i<10; i++)
    {
        v.push_back(i);
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
    for_each(v.begin(), v.end(), [](int element){
        cout << element << endl;
    });

}

int main()
{
    test_vector();
    return 0;
}
 