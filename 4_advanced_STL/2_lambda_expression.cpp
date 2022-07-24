#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// show g++ standard c++ version, type in the terminal:
// g++ -dM -E -x c++  /dev/null | grep __cplusplus

bool cmp(int a, int b)
{
    return  a < b;
}

int main()
{
    vector<int> myvec{3,2,5,6,4,3,6}; // vector initialisation, also in c++11
    // vector myvec{3,2,5,6,4,3,6}; // alto deduction data type, available in c++17
    vector<int> lbvec(myvec);

    sort(myvec.begin(), myvec.end(), cmp);  // before c++ 11
    cout << "predicate function:" << endl;
    for (int it : myvec)                    // range-based for loop, also is a C++11 extension [-Wc++11-extensions]
        cout << it << ' ';
    cout << endl;

    sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';
    cout << endl;
}