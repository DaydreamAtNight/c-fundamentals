// algorithm libs contain 
// <algorithm>   --- biggest, large range, include traverse, swap, find, copy ...
// <numeric>     --- small,  template function for simple + - * /
// <functional>  --- buld in template class (functors）

// this file first introduce traverse
// for_each(iterator begin, iterator end, _func);
// transform

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void printFunction(T & v)
{
    cout << v << " ";
}

template <class T>
class printFunctor
{
public:
    void operator()(T v)
    {
        cout << v << " ";
    }
};

template <class T>
class return_self
{
public:
    T operator()(T v)
    {
        return v;   // can be more complex
    }
};

int main()
{
    vector<int> v = {2,5,4,3,6,7,8};
    for_each(v.begin(),v.end(), printFunction<int>);
    cout << endl;
    for_each(v.begin(),v.end(), printFunctor<int>());
    cout << endl;

    vector<int> v_cp;
    v_cp.resize(v.size());
    transform(v.begin(), v.end(), v_cp.begin(), return_self<int>());
    for_each(v_cp.begin(),v_cp.end(), printFunctor<int>());

}
