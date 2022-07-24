#include <iostream>
#include <math.h>
using namespace std;

class Circle
{
public: // options: public, private, protected
    int radius;
    float getPerimeter()
    {
        return 2 * M_PI * radius;
    }
};

int main()
{
    Circle c1;
    c1.radius = 10;
    cout << c1.getPerimeter() << endl;
}
