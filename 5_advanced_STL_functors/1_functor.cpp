// functors test
#include <iostream>
using namespace std;

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

class MyPrint
{
private:
    int p_count;
public:
    int & count = p_count; // C++11, make sure p_cout is READ_ONLY

    MyPrint()
    {
        p_count = 0;
    }
    void operator()(string s)
    {
        p_count++;
        cout << s << endl;
    }
};

void doPrint(MyPrint & mp, string test) // class as varible
{   
    mp(test);
}


int main()
{
    // functors can be instantiated as class
    // and be called as normal functions
    MyAdd myadd;
    cout << myadd(10, 10) << endl;

    // functors are more than normal functions
    // they can has their own properties
    MyPrint myprint;
    myprint("testline1");
    myprint("testline2");
    myprint("testline3");
    myprint("testline4");
    cout << "it has beed called " << myprint.count << " times." << endl;

    // functors can be used as function parameters
    doPrint(myprint, "testline5");

    return 0;
}