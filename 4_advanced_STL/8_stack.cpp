// first in last out FILO
// push and pop to manage the data in the stack
// traversal    no
// empty        yes
// size         yes

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // default constructor
    stack<int> s1;

    // push and pop
    for (int i=0; i<10; i++)
    {
        s1.push(i);
    }
    s1.pop();
    s1.pop();

    // copy constructor
    stack<int> s2(s1);

    // traversal
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    // size
    cout << "size: " << s1.size() << endl;
}

