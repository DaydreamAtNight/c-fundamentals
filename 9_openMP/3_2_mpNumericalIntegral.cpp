#include <iostream>
#include <math.h>
#include <omp.h>
using namespace std;

double deJongFunction(double x, double y)
{
    double result = 0.002;
    for (int i = -2; i < 3; i++)
    {
        for (int j = -2; j < 3; j++)
        {
            result += 1.0 / (5 * (i + 2) + j + 3 + pow((x - 16 * j), 6) + pow((y - 16 * i), 6));
        }
    }
    return 1.0 / result;
}


double integralFunction(double xLim[2], double yLim[2], double precision)
{
    int threads = omp_get_max_threads();

    double xInterval = (xLim[1] - xLim[0]) / (double)threads;
    double result = 0;

#pragma omp parallel for
    for (int ii = 0; ii < threads; ii++)
    {
        double x_sub[] = {xLim[0]+ii * xInterval, xLim[0]+(ii + 1) * xInterval};
        double sum = 0;
        for (double i = x_sub[0]; i < +x_sub[1] - precision / 2; i += precision)
        {
            for (double j = yLim[0]; j < +yLim[1]+precision/2; j += precision)
            {
                sum += deJongFunction((2 * i + precision) / 2, (2 * j + precision) / 2) * precision * precision;
            }
        }
#pragma omp critical
        result += sum;
    }
    return result;
}

int main()
{
    double xLim[] = {-2, 2};
    double yLim[] = {-2, 2};
    cout << "result = " << integralFunction(xLim, yLim, 5e-4) << endl;
    return 0;
}

// g++-11 -fopenmp 3_2_mpNumericalIntegral.cpp
// result = 459.476
// ./a.out  58.17s user 0.22s system 743% cpu 7.856 total

// with -O2
// result = 459.476
// ./a.out  47.99s user 0.20s system 737% cpu 6.538 total