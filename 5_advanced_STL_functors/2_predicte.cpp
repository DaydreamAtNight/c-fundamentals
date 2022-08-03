// The predicate is a functor that returns a bool

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BiggerThanFive
{
public:
    bool operator()(int arg)
    {
        return arg>5;
    }
};

int main()
{
    vector<int> v1;
    for (int i=0; i<10; i++)
    {
        v1.push_back(i+1);
    }

    // find first element bigger than 5
    // _IIter find_if<_IIter, _Predicate>(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    // find_if(v1.begin(), v1.end(),BiggerThanFive); // error: 'BiggerThanFive' does not refer to a value
    vector<int> :: iterator itt = find_if(v1.begin(), v1.end(), BiggerThanFive()); // need a object here instead of a class name as before
    if (itt == v1.end())
    {
        cout << "does not find an element that is bigger than 5";
    }
    else
    {
        cout << "There exists element bigger than 5 in v1: " << endl;
        cout << "the first position is " << itt-v1.begin() << " with value: " << *itt << endl;
    }

    return 0;
}
