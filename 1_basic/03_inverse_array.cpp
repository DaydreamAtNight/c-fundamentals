#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int shapea = *(&a+1)-a, temp;

    for(int starta=0, enda=shapea-1;starta<enda ; starta++ ,enda--){
            temp = a[starta];
            a[starta] = a[enda];
            a[enda] = temp;
    }

    for (int i=0;i<shapea;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}