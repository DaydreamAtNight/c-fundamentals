#include <iostream>
#include <omp.h>
#include <unistd.h>
using namespace std;

#define THREAD_NUM 4
int main()
{
    omp_set_num_threads(THREAD_NUM); // set number of threads in "parallel" blocks
    #pragma omp parallel
    {
        // do this to avoid race condition while printing
        usleep(50 * omp_get_thread_num()); 
        // each thread can also get its own number
        cout << "thread: [" << omp_get_thread_num() << "/" << omp_get_num_threads()-1 <<"]"<< endl;
        cout << "Hello World!" << endl;
    }
    return 0;
}


// compile with 
// g++-11 -fopenmp 1_3_mpHelloWorld_better.cpp -o hello_cpp_better