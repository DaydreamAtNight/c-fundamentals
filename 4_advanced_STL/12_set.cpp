// set is a type of associative container based on Binary Tree
// automatic sorting the data
// set doesn't allow same data
// another conainter -- multiset supports same data
// set and multiset are all included in <set>

#include <iostream>
#include <set>
using namespace std;

template <class T>
void print_set(string st, const T v)
{
    cout << st;
    for (typename T::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <class T1, class T2>
class customCompare
{
public:
    // bool operator()(const T1& a, const T2& b) // warning: the specified comparator type does not provide a viable const call operator [-Wuser-defined-warnings]
    bool operator()(const T1& a, const T2& b) const // functor overloading the "()" operator
    {
        return a > b;
    }
};

int main()
{
    // constructor
    cout << "--------- constructor ----------" << endl;
    set<int> st1;
    set<int> st2 = {4,3,2,30,2,44,5,8,9,10};    // c++ 11
    print_set("st2 = ", st2);                   // output: 2 3 4 5 8 9 10 30 44, only one '2' is kept
    multiset<int> st3 = {4,3,2,30,2,44,5,8,9,10};
    print_set("st3 = ", st3);                   // output: 2 2 3 4 5 8 9 10 30 44, extra '2' is kept
    set<int> st4(st2.begin(), st2.end());       // copy constructor
    print_set("st4 = ", st4); 
    set<int> st5=st2;                          // copy constructor
    print_set("st5 = ", st5); 
    
    // only insert is supported in set
    cout << "--------- insert ----------" << endl;
    st1.insert(5);
    st1.insert(2);
    st1.insert(1);
    st1.insert(3);
    print_set("st1 = ", st1);                   // st1 = 1 2 3 5  auto sorting

    // capacity
    cout << "--------- capacity ----------" << endl;
    cout << "st1's size = " << st1.size() << endl;
    cout << "st1's max_size = " << st1.max_size() << endl;
    cout << "st1's empty = " << st1.empty() << endl;
    
    // swap
    cout << "--------- swap ----------" << endl;
    print_set("st1 = ", st1);
    print_set("st2 = ", st2);
    st1.swap(st2);
    // st1.swap(st3);      //  error: non-const lvalue reference to type 'std::set<int>' cannot bind to a value of unrelated type 'multiset<int>'
    print_set("st1 = ", st1);
    print_set("st2 = ", st2);

    // erase
    cout << "--------- erase ----------" << endl;
    print_set("st2 = ", st2);
    st2.erase(st2.begin());
    print_set("st2 = ", st2);
    st2.erase(3);                           // same as remove() in list
    print_set("st2 = ", st2);
    // st2.erase(st2.begin()+1, st2.end());  // error, not random access iterator, only bidirectional iterator is allowed
    st2.erase(st2.begin(), st2.end());          // erase all elements
    print_set("st2 = ", st2);

    // count and find
    cout << "--------- count and find ----------" << endl;
    print_set("st1 = ", st1);
    print_set("st3 = ", st3);
    cout << "st1.count(2) = " << st1.count(2) << endl;
    cout << "st3.count(2) = " << st3.count(2) << endl;   
    cout << "*st1.find(2) = " << *st1.find(2) << endl;    // find return a iterator, *iterator is the value of the iterator

    // difference between set and multiset
    cout << "--------- set and multiset ----------" << endl;
    // when insert set, a pair object is used
    pair<set<int>::iterator, bool> ifget = st1.insert(2); // pair<iterator,bool> insert(value_type&& __v)
    cout << ifget.second << endl;
    ifget = st1.insert(7); // pair<iterator,bool> insert(value_type&& __v)
    cout << ifget.second << endl;
    print_set("st1 = ", st1);
    st3.insert(2); // iterator insert(value_type&& __v), no pair object is used

    // change default sorting method, using functors (仿函数)
    // functors reload the "( )" operator
    // functors are objects that have a call operator, and can be used in a function call
    // here, functors are used to define the sorting method of a set
    cout << "--------- change default sorting method ----------" << endl;
    set<int> st6 = {4,3,2,30,2,44,5,8,9,10}; // default sorting method is "less"
    print_set("st6 = ", st6);

    set<int,customCompare<int, int>> st7 = {4,3,2,30,2,44,5,8,9,10};
    print_set("st7 = ", st7);
}
