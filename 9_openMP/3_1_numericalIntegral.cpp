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
    // double xInterval = abs((xLim[0] - xLim[1]));
    // double yInterval = abs((yLim[0] - yLim[1]));
    double result = 0;

    for (double i = xLim[0]; i < xLim[1]+precision/2; i += precision)
    {
        for (double j = yLim[0]; j < yLim[1]+precision/2; j += precision)
        {
            result += deJongFunction((2 * i + precision) / 2, (2 * j + precision) / 2) * precision * precision;
        }
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

// g++-11 3_1_numericalIntegral.cpp
// time ./a.out
// result = 459.623
// ./a.out  36.60s user 0.16s system 99% cpu 36.897 total

// with -O2 flag:
// result = 459.623
// ./a.out  29.90s user 0.06s system 99% cpu 29.974 total