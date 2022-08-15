#include "swap.h"
using namespace std;

void Swap::runSwap()
{
    int temp;
    temp = _a;
    _a = _b;
    _b = temp;
}

void Swap::printResult()
{
    cout << "_a = " << _a << " _b = " << _b << endl;
}