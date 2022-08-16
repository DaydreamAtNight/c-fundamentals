#include <iostream>
#include "shotGun.h"
using namespace std;

class solider
{
private:
    string _name;
    shotGun *_gun;
    int _soliderBulletLeft;

public:
    string &_soliderName = _name;
    int &_BulletLeft = _soliderBulletLeft;

    solider();
    solider(string name);
    solider(int bulletNumber);
    solider(string name, int bulletNumber);
    ~solider();

    void fire();
};