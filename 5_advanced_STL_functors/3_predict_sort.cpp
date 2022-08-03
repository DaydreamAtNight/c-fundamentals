// predictor with two args
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

// use functors to change the sorting rule
template <class T>
class NewCompareFunctor
{
public:
    bool operator()(T a, T b)
    {
        return a > b;
    }
};

template <class T>
bool NewCompareFunction(T a, T b)
{
    return a>b;
}

int main()
{
    vector<int> v1 = {1, 8, 5, 6, 2, 4, 3, 6, 9, 7, 10};
    print_vec("v1 before sort = ", v1);
    sort(v1.begin(), v1.end());
    print_vec("v1 after sort = ", v1);
    sort(v1.begin(), v1.end(), NewCompareFunctor<int>()); // object is needed
    sort(v1.begin(), v1.end(), NewCompareFunction<int>); // function name is needed
    sort(v1.begin(), v1.end(),[](int a, int b) -> bool { return a > b; }); // lambda function C++11
    print_vec("v1 after newsort = ", v1);

    return 0;
}