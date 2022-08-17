#include <iostream>
#include <ctime>
#include <cstdlib>
#include "solider.h"
using namespace std;

void bulletsSummary(solider soldiers[], int total)
{
    cout << endl
         << "<<< Bullets Summary >>>" << endl;
    int sum = 0;
    for (int i = 0; i < total; i++)
    {
        cout << soldiers[i]._soliderName << " bullets left:\t" << soldiers[i]._BulletLeft << endl;
        sum += soldiers[i]._BulletLeft;
    }

    cout << "Total bullets left:\t" << sum << endl;
}

void freeShoot(solider soldiers[], int total)
{
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < rand() % 10; j++)
        {
            soldiers[i].fire();
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    solider goodFellows[2]{solider("Tom"), solider("Jerry", 10)};
    goodFellows[0].fire();
    goodFellows[1].fire();

    freeShoot(goodFellows, 2);
    freeShoot(goodFellows, 2);
    freeShoot(goodFellows, 2);
    bulletsSummary(goodFellows, 2);
    return 0;
}

// compile with
// clang++ --std=c++11 main.cpp src/s*  -Iinclude

// or cmake, using makefile

// tasks.json and launch.json enable the fully automatic debugging
// see https://www.bilibili.com/video/BV1fy4y1b7TC?p=23