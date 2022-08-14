#include <stdio.h>
#include <omp.h>
int main(void){
    #pragma omp parallel 
    {
        printf("Hello World! \n");
    }

    return 0;
}

// compile with 
// export OMP_NUM_THREADS=8
// gcc-11 -fopenmp 1_1_mpHelloWorld.c -o hello