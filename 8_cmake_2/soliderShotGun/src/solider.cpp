#include "solider.h"

solider::solider()
{
    _name = "Nobody";
    _gun = new shotGun();
}

solider::solider(int bulletNumber)
{
    _gun = new shotGun(bulletNumber);
}

solider::solider(string name)
{
    _name = name;
    _gun = new shotGun();
}

solider :: solider(string name, int bulletNumber)
{
    _name = name;
    _gun = new shotGun(bulletNumber);
}

solider::~solider()
{
    delete _gun;
    if (_gun != NULL)
    {
        _gun = NULL;
    }
}

void solider::fire()
{
    cout << "solider [" << _name << "\t ] shots one bullet: ";
    _gun->shoot();
    _soliderBulletLeft =  _gun->_bulletLeft;
}