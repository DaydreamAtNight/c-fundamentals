// list is a linked list container in C++ STL libaray
#include <iostream>
#include <list>
using namespace std;

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

// template <class T>
bool descending_function(int v1, int v2)
{
    // descending order:
    return v1 > v2; 
}

int main()
{
    // constructors
    list<int> L1;
    list<int>L2={10,9,8,7,6,5,4,3,2,1}; // c++ 11
    list<int>L3(L2.begin(), L2.end());
    list<int>L4(L2);
    list<int>L5(10,1);

    // push
    for(int i=0; i<10; i++)
    {
        L1.push_back(i+1);
    }

    // assign and swap
    L2 = L1;
    L3.assign(L1.begin(), L1.end());
    L4.assign(10,1);
    L4.swap(L2);

    // print all
    cout << "--------- print ----------" << endl;
    printList("L1 = ", L1);
    printList("L2 = ", L2);
    printList("L3 = ", L3);
    printList("L4 = ", L4);
    printList("L5 = ", L5);

    // size, resize and empty
    cout << "--------- resize ----------" << endl;
    cout << "L4's size = " << L4.size() << endl;
    cout << "L4's max_size = " << L4.max_size() << endl;
    cout << "L4's empty = " << L4.empty() << endl;
    L4.resize(15); // resize L4 to 15 elements, all other elements are 0
    printList("resize L4 to 15 ", L4);
    L4.resize(9); // resize L4 to 9 elements
    printList("resize L4 to 9 ", L4);
    L4.resize(15,30); // resize L4 to 15 elements, all other elements are 30
    printList("resize L4 to 15, fill with 30 ", L4);

    // modifiers
    cout << "--------- modifiers ----------" << endl;
    L4.push_back(100);
    printList("push_back 100 to L4 ", L4);
    L4.push_front(200);
    printList("push_front 200 to L4 ", L4);
    L4.pop_back();
    printList("pop_back from L4 ", L4);
    L4.pop_front();
    printList("pop_front from L4 ", L4);
    L4.insert(L4.begin(), 300);
    printList("insert 300 to L4 at begining ", L4);
    L4.insert(L4.end(), 5,  400);
    printList("insert 5 400 to L4 at end ", L4);
    // L4.insert(L4.begin()+3, L3.begin(), L3.begin()+3); // error: Number arithmetic is possible only with random access iterators such as those in std::vector and std::deque.
    // printList("insert L3[0,2] to L4 at 3 ", L4);
    L4.insert(++L4.begin(), {500,600,700}); // --std=c++11
    printList("insert {500,600,700} to L4 at begining+1 ", L4);
    L4.remove(30);                                        // unique feature in list
    printList("remove all 30 in L4 ", L4);
    // L4.erase(L4.begin(), L4.end());
    // printList("erase L4 all", L4);
    // L4.clear();
    // printList("clear L4 ", L4);

    // data access
    // subscription [] is not supported in list
    // the iterator of list is not random access iterator as well, only bidirectional iterator, ++ or -- is valid.

    cout << "--------- element access ----------" << endl;
    // cout << L3[0] << endl; // error: type 'list<int>' does not provide a subscript operator
    // cout << L3.at(0) << endl; // error: no member named 'at' in 'std::list<int>'
    cout << "first element in L4 is: " << L4.front() << endl;
    cout << "last element in L4 is: " << L4.back() << endl;

    // reverse and sort
    cout << "--------- reverse and sort ----------" << endl;
    L4.reverse();                                   // unique feature in list
    printList("reverse L4 ", L4);
    // sort(L4.begin(),L4.end());                      // error because standard sort need random access iterator
    L4.sort();                                      // use member function
    printList("sort L4 ", L4);                      // default increase
    L4.sort(descending_function);   
    printList("descending order sort L4 ", L4);     


    return 0;
}
