#include <iostream>
using namespace std;

class shotGun
{
private:
    int _bulletNumber;

public:
    int &_bulletLeft = _bulletNumber;

    shotGun();
    shotGun(int bulletNumber);
    void shoot();
};