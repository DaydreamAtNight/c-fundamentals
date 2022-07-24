#include<iostream>
using namespace std;
int main()
{
    int a[]={12,34,5,23,67,85,2,4,66,7};
    int temp;

    int shapea = *(&a+1)-a;

    for (int i=0;i<shapea-1;i++){
        for (int j=0;j<shapea-1-i;j++){
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for (int i=0;i<shapea;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}