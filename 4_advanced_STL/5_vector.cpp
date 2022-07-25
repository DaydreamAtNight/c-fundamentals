// somte vector features
#include <iostream>
using namespace std;
#include <vector>

template <class T>
void printVector(vector<T> v)
{
    // for (vector<T>::iterator it = v.begin(); it != v.end(); it++) // error: missing 'typename' prior to dependent type name 'vector<T>::iterator'
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++) // works when gives the type 'int'
    // for (auto it = v.begin(); it != v.end(); it++) // works in c++11
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // constructor
    vector<int> v1(10); //size 10, all elements are 0
    vector<int> v2(10, 1); //size 10, all elements are 1
    vector<int> v3(v2); //copy v2 to v3
    vector<int> v4(v2.begin(), v2.end()); //copy v2 to v4
    printVector<int> (v4);

    // value assignment
    vector<int> v5;
    v5 = v1;
    v5.assign(v1.begin(), v1.end()+1);
    v5.assign(10,100);
    printVector<int> (v5);

    // member functions
    cout << "--------- member functions ----------" << endl;
    cout << "v5's size = " << v5.size() << endl;
    cout << "v5's capacity = " << v5.capacity() << endl;
    cout << "v5's max_size = " << v5.max_size() << endl;
    cout << "v5's empty = " << v5.empty() << endl;
    v5.resize(15); // resize v5 to 15 elements, all other elements are 0
    cout << "resize v5 to 15 = " ;
    printVector<int> (v5);
    v5.resize(9); // resize v5 to 9 elements
    cout << "resize v5 to 9 = " ;
    printVector<int> (v5);
    v5.resize(15,30); // resize v5 to 15 elements, all other elements are 30
    cout << "resize v5 to 15, fill with 30 = " ;
    printVector<int> (v5);

    // element access
    cout << "--------- element access ----------" << endl;
    cout << "v5[7] = " << v5[7] << endl;
    cout << "v5's front = " << v5.front() << endl;
    cout << "v5's back = " << v5.back() << endl;
    cout << "v5's at(0) = " << v5.at(0) << endl;

    // insert and erase
    cout << "--------- insert and erase ----------" << endl;
    v5.push_back(100); // add 100 to the end of v5
    cout << "push_back 100 = " ;
    printVector<int> (v5);
    v5.pop_back(); // remove the last element of v5
    cout << "pop_back = " ;
    printVector<int> (v5);
    v5.insert(v5.begin(), 10); // insert 10 at the beginning of v5
    cout << "insert 10 at the beginning of v5 = " ;
    printVector<int> (v5);
    v5.insert(v5.begin()+1, 5, 20); // insert 5 20 at the second position of v5
    cout << "insert 5 20 at the second position of v5 = " ;
    printVector<int> (v5);
    v5.erase(v5.begin()+1); // erase the second element of v5
    cout << "erase the second element of v5 = " ;
    printVector<int> (v5);
    v5.erase(v5.begin()+3, v5.end()-1); // erase the first to the last-1 element of v5
    cout << "erase the first+3 to the last-1 element of v5 = " ;
    printVector<int> (v5);  
    v5.clear(); // clear v5
    cout << "clear v5 = " ;
    printVector<int> (v5);  
    
    // swap
    cout << "--------- swap ----------" << endl;
    cout << "v1 = " ;
    printVector<int> (v1); 
    cout << "v2 = " ;
    printVector<int> (v2); 
    v1.swap(v2); // swap v1 and v2
    cout << "swaping v1 and v2" << endl;
    cout << "v1 = " ;
    printVector<int> (v1); 
    cout << "v2 = " ;
    printVector<int> (v2); 

    cout << "use swap to shrink capacity" << endl;
    vector<int> v6(10000,10);
    cout << "v6's size = " << v6.size() << endl;
    cout << "v6's capacity = " << v6.capacity() << endl;
    v6.resize(3);
    cout << "after resize:" << endl;
    cout << "v6's size = " << v6.size() << endl;
    cout << "v6's capacity = " << v6.capacity() << endl; 
    vector<int>(v6).swap(v6); // swap v6 to shrink the capacity
    cout << "after swap:" << endl;
    cout << "v6's size = " << v6.size() << endl;
    cout << "v6's capacity = " << v6.capacity() << endl;

    // reserve, shrink_to_fit
    cout << "--------- reserve ----------" << endl;
    // times of allocating memories
    int num = 0;
    int *p = NULL;
    vector <int> v7;
    // v7.reserve(100000); // reserve 100 elements, comment out this line to see the difference
    for (int i = 0; i < 100000; i++)
    {
        v7.push_back(i);
        if (p!=&v7[0])
        {
            p=&v7[0];
            num++;
        }
    }
    cout << "times of allocating memories = " << num << endl;
    cout << "v7's size = " << v7.size() << endl;
    cout << "v7's capacity = " << v7.capacity() << endl;

    return 0;
}
