#include <iostream>
#include <algorithm>
#define ARRAY_SIZE 1000000000
#define ARRAY_VALUE 1231
using namespace std;

int main()
{
    int *arr = new int[ARRAY_SIZE];
    std::fill_n(arr, ARRAY_SIZE, ARRAY_VALUE);
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        // do some relatively long operation
        arr[i] = arr[i] / arr[i] + arr[i] / 5 - 14;
    }
    return 0;
}

// g++-11 2_1_arrayOperation.cpp
// time ./a.out # evaluate run time 
// ./a.out  4.76s user 0.86s system 93% cpu 6.029 total
// 
// g++-11 2_1_arrayOperation.cpp -O2
// time ./a.out
// ./a.out  0.01s user 0.00s system 90% cpu 0.015 total