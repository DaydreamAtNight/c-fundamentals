// two ways to create a pair object:
//     pair<type, type> p(value1, value2);
//     pair<type, type> p = make_pair(value1, value2);

#include <iostream>
using namespace std;

int main()
{
    pair <int, int> p(1, 2);
    pair <int, int> p2 = make_pair(3, 4);
    
    cout << "p.first = " << p.first << endl;
    cout << "p.second = " << p.second << endl;
    cout << "p2.first = " << p2.first << endl;
    cout << "p2.second = " << p2.second << endl;
}