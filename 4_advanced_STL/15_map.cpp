// map is the third useful container in cpp after vector and list
// all elements in map are key-value <pair>s 
// map is a sorted container, so the key can be sorted
// similar to set, it is based on Binary Tree
// very similar to dict in python
// map different key
// multimap, same key supported
// unordered_map, unordered_set, unordered_multimap, unordered_multiset are also available

#include<iostream>
#include<map>
using namespace std;

template<class T>
void print_map(const string st, const T &m)
{
    cout << st << endl;
    for (typename T::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

bool more_compare(const int &m1, const int &m2)
{
    return m1 > m2;
}

class moreCompare
{
public:
    bool operator()(const int& m1, const int& m2) const
    {
        return m1 > m2;
    }
};


int main()
{
    // constructor
    cout << "--------- constructor ----------" << endl;
    map<int, string> m1; // key is int, value is string
    map<int, string> m2 = {{1, "a"}, {2, "b"}, {3, "c"}}; // c++ 11
    
    // insert
    m1.insert(pair<int, string>(1, "one"));
    m1[3] = "three";
    m1[2] = "two";

    // constructor
    map<int, string> m3(m1); // copy constructor
    map<int, string> m4 = m2;

    print_map("m1 = ",m1);
    print_map("m2 = ",m2);
    print_map("m3 = ",m3);
    print_map("m4 = ",m4);

    // capacity
    cout << "--------- capacity ----------" << endl;
    cout << "m1's size = " << m1.size() << endl;
    cout << "m1's max_size = " << m1.max_size() << endl;
    cout << "m1's empty = " << m1.empty() << endl;

    // swap
    cout << "--------- swap ----------" << endl;
    print_map("m1 = ",m1);  
    print_map("m2 = ",m2);
    m1.swap(m2);
    print_map("m1 = ",m1);
    print_map("m2 = ",m2);

    // insert
    cout << "--------- insert ----------" << endl;
    m2.insert(pair<int, string>(4, "four"));
    print_map("m2 = ",m2);
    m2.insert(make_pair(5, "five")); // better
    print_map("m2 = ",m2);
    m2.insert(map<int, string>::value_type(6, "six"));
    print_map("m2 = ",m2);
    m2[7] = "seven"; // not recommanded, always used to get access to the value
    print_map("m2 = ",m2);

    // erase
    cout << "--------- erase ----------" << endl;
    m2.erase(3); // erase the element with key 3
    print_map("m2.erase(3) =  ",m2);
    m2.erase(m2.begin()); // erase the first element
    print_map("m2.erase(m2.begin()) =  ",m2);
    m2.erase(m2.begin(), --m2.end()); // erase the whole map except the last element
    // m2.erase(m2.begin(), m2.end()-3); // Error, not random access iterator
    print_map("m2.erase(m2.begin(), m2.end()) =  ",m2);
    // m2.clear(); // erase the whole map
    // print_map("m2.clear() =  ",m2);
    
    // find and count
    cout << "--------- find and count ----------" << endl;
    print_map("m3 = ",m3);
    cout << "m3.find(2) = " << m3.find(2)->second << endl; // return iterator to the element with key 3
    cout << "m3.find(4) = " << m3.find(7)->second << endl; // because find return the .end pointer

    cout << "m3.count(2) = " << m3.count(2) << endl; // return the number of element with key 2, 0 or 1

    // sort
    cout << "--------- sort ----------" << endl;
    map<int, string> m5 = {{1, "a"}, {2, "b"}, {3, "c"}}; // _Compare = less
    // map<int, string, more_compare> m6 = {{1, "a"}, {2, "b"}, {3, "c"}}; 
    // map<int, string, [](int a, int b) -> bool { return a > b; } > m7 = {{1, "a"}, {2, "b"}, {3, "c"}}; 
    map<int, string, moreCompare> m8 = {{1, "a"}, {2, "b"}, {3, "c"}}; 

    print_map("m5 = ",m5);
    // print_map("m6 = ",m6);
    // print_map("m7 = ",m7);
    print_map("m8 = ",m8);

}