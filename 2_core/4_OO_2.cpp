#include <iostream>
using namespace std;

class Student
{
protected: // options: public, private, protected
    string name, id;

public:
    Student &displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        return *this;
    }
    Student &updateName(string new_name)
    {
        name = new_name;
        return *this;
    }
    Student &updateId(string new_id)
    {
        id = new_id;
        return *this;
    }
};

int main()
{
    Student s1;
    s1.updateName("Jone").updateId("123");
    s1.displayInfo();
    s1.updateName("Jane").updateId("456");
    s1.displayInfo();
    return 0;
}