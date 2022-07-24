#include <iostream>
using namespace std;
int main()
{
    float a[3], min=1e10;
    cin >> a[0]  >> a[1] >> a[2];  
    for(int i=0; i<3; i++)
        if (a[i]<min) min=a[i];
    
    cout << "min = " << min << endl;
} 
