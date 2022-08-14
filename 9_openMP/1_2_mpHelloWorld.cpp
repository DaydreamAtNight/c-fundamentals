#include <iostream>
using namespace std;

int main()
{
    #pragma omp parallel
    {
        cout << "Hello World" << endl;
    }
    return 0;
}

// there is a race condition while printing

// compile with 
// export OMP_NUM_THREADS=8
// g++-11 -fopenmp 1_2_mpHelloWorld.cpp -o hello_cpp