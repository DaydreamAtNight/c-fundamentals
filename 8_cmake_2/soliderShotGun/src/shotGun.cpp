#include "shotGun.h"

shotGun::shotGun()
{
    this->_bulletNumber = 15;
}

shotGun::shotGun(int bulletNumber)
{
    this->_bulletNumber = bulletNumber;
}

void shotGun::shoot()
{
    if (_bulletNumber-- <= 0)
    {
        cout << "no bullet!" << endl;
        _bulletNumber = 0;
    }
    else
    {
        cout << "Bang!" << endl;
    }
}