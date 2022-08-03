#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

// test 
// negate, plus
// greater
// logical_not<T>


template <class T>
void print_vec(string st, const T v)
{
    cout << st;
    for (typename T::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    negate<int> n;
    plus<int> p;

    cout << n(50) << endl;
    cout << p(1,2) << endl;


    vector<int> v1 = {1, 8, 5, 6, 2, 4, 3, 6, 9, 7, 10};
    sort(v1.begin(), v1.end(), greater<int>()); // usd build in stl greater functor
    print_vec("v1 after sort = ", v1);


    vector<bool> v_bool = {true, false, true, true, false, false};
     print_vec("v_bool1 = ", v_bool);
    vector<bool> v_bool2;
    v_bool2.resize(v_bool.size()); //  32498 segmentation fault  if not resize
    transform(v_bool.begin(), v_bool.end(), v_bool2.begin(), logical_not<bool>());
    print_vec("v_bool2 after transform = ", v_bool2);


}