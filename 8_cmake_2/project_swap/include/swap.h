#pragma once
#include <iostream>
using namespace std;

class Swap
{
private:
    /* data */
    int _a;
    int _b;

public:
    Swap(int a, int b)
    {
        this->_a = a;
        this->_b = b;
    }

    void runSwap();
    void printResult();
};
