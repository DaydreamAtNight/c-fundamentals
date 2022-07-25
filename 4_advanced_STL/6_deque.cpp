// deque denores double endded queue
#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

template <class T>
void printQue(string name, const T v)
{
    cout << name << " = ";
    for (typename T::const_iterator it = v.begin(); it != v.end(); it++) // const_iterator is nessary for const deque
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <class T>
void lineQue(T &v, int size)
{
    for (int i=0; i<size; i++) // const_iterator is nessary for const deque
    {
        v.push_back(i+1);
    }
}

int main()
{
    //constructor
    cout << "--------- constructor ----------" << endl;
    deque<int> dq1;
    lineQue(dq1, 10);
    deque<int> dq2(10, 100);
    deque<int> dq3(dq1.begin(), dq1.end());
    deque<int> dq4(dq1);
    printQue("dq1", dq1);
    printQue("dq2", dq2);
    printQue("dq3", dq3);
    printQue("dq4", dq4);

    //value assignment
    cout << "--------- value assignment ----------" << endl;
    dq1 = dq2;
    dq1.assign(dq2.begin(), dq2.end());
    dq1.assign(10,100);
    printQue("dq1", dq1);

    // size
    cout << "--------- size ----------" << endl;
    // there is no concept of capcity in deque, the capcity is unlimited
    cout << "dq1's size = " << dq1.size() << endl;
    cout << "dq1's max_size = " << dq1.max_size() << endl;
    cout << "dq1's empty = " << dq1.empty() << endl;
    dq1.resize(15); // resize dq1 to 15 elements, all other elements are 0
    printQue("resize dq1 to 15 ", dq1);
    dq1.resize(9); // resize dq1 to 9 elements
    printQue("resize dq1 to 9 ", dq1);
    dq1.resize(15,30); // resize dq1 to 15 elements, all other elements are 30
    printQue("resize dq1 to 15, fill with 30 ", dq1);

    // element access
    cout << "--------- element access ----------" << endl;
    cout << "dq1[7] = " << dq1[7] << endl;
    dq1[7] = 100;
    cout << "dq1[7] = " << dq1[7] << endl;
    cout << "dq1.at(7) = " << dq1.at(7) << endl;
    cout << "dq1.front() = " << dq1.front() << endl;
    cout << "dq1.back() = " << dq1.back() << endl;

    // modifiers
    cout << "--------- modifiers ----------" << endl;
    dq1.push_back(100);
    printQue("push_back 100 to dq1 ", dq1);
    dq1.push_front(200);
    printQue("push_front 200 to dq1 ", dq1);
    dq1.pop_back();
    printQue("pop_back from dq1 ", dq1);
    dq1.pop_front();
    printQue("pop_front from dq1 ", dq1);
    dq1.insert(dq1.begin(), 300);
    printQue("insert 300 to dq1 at begining ", dq1);
    dq1.insert(dq1.end(), 5,  400);
    printQue("insert 5 400 to dq1 at end ", dq1);
    dq1.insert(dq1.begin()+3, dq2.begin(), dq2.begin()+3);
    printQue("insert dq2[0,2] to dq1 at 3 ", dq1);
    dq1.insert(dq1.begin()+3, {500,600,700}); // --std=c++11
    printQue("insert {500,600,700} to dq1 at begining+3 ", dq1);
    dq1.erase(dq1.begin()+3, dq1.begin()+6);
    printQue("erase from dq1 at begining+3 to begining+6 ", dq1);
    // dq1.clear();
    // printQue("clear dq1 ", dq1);

    // sort
    cout << "--------- sort ----------" << endl;
    sort(dq1.begin(), dq1.end());
    printQue("sort dq1 ", dq1);
    // it can be used to containers like vector, list, deque, set, multiset, multimap, unordered_set, unordered_multiset, unordered_multimap
    // that support the random access iterators

    return 0;
}