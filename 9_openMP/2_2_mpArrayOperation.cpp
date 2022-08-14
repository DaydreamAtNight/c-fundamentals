#include <iostream>
#include <algorithm>
#include <omp.h>

#define ARRAY_SIZE 1000000000
#define ARRAY_VALUE 1231
using namespace std;

int main()
{
    omp_set_num_threads(4);
    int *arr = new int[ARRAY_SIZE];
    fill_n(arr, ARRAY_SIZE, ARRAY_VALUE);

#pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // do some relatively long operation
        arr[i] = arr[i] / arr[i] + arr[i] / 5 - 14;
    }

    return 0;
}

// g++-11 -fopenmp 2_2_mpArrayOperation.cpp
// time ./a.out # evaluate run time
// with no mp:
// ./a.out  4.76s user 0.86s system 93% cpu 6.029 total
// with mp
// ./a.out  5.00s user 0.91s system 155% cpu 3.809 total


// g++-11 -fopenmp 2_2_mpArrayOperation.cpp -O2
// time ./a.out
// with no mp:
// ./a.out  0.01s user 0.00s system 90% cpu 0.015 total
// with mp:
// ./a.out  1.19s user 0.87s system 161% cpu 1.280 total