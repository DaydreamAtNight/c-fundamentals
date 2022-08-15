#include "swap.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Swap mySwap(10.0, 20.0);
    cout << "before swap" << endl;
    mySwap.printResult();
    mySwap.runSwap();
    cout << "after swap" << endl;
    mySwap.printResult();

    return 0;
}

// compile with
// g++ -std=c++11 main.cpp src/swap.cpp  -o swapTest -Iinclude