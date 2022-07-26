// first in first out FIFO
// push at front and pop in back
// traversal    no
// empty        yes
// size         yes

#include <iostream>
#include <queue>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};

int main()
{
    queue<Person> q;

    for (int i=0; i<10; i++)
    {
        Person p("name" + to_string(i), 20+i);
        q.push(p);
    }

    for (;!q.empty();)
    {
        cout << q.front().name << " " << q.front().age << endl; // tranversal
        cout << q.back().name << " " << q.back().age << endl; // same element because pop in the other end
        cout << "size: " << q.size() << endl;
        q.pop();
    }

    return 0;
}

