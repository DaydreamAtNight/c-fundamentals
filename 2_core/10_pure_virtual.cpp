#include <iostream>
using namespace std;

// simulate a process of beverage machine

class abstractBeverage
{
protected:
    virtual void prepare() = 0;
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    virtual void pourInCup() = 0;

public:
    void start()
    {
        prepare();
        brew();
        addCondiments();
        pourInCup();
    }
};

class milkTea : public abstractBeverage
{
    virtual void prepare()
    {
        cout << "prepare milkTea" << endl;
    }
    virtual void brew()
    {
        cout << "brew tea" << endl;
    }
    virtual void addCondiments()
    {
        cout << "add milk, sugar and bubble" << endl;
    }
    virtual void pourInCup()
    {
        cout << "pour milkTea in cup" << endl;
    }
};

class coffee : public abstractBeverage
{
    virtual void prepare()
    {
        cout << "prepare coffee" << endl;
    }
    virtual void brew()
    {
        cout << "brew coffee" << endl;
    }
    virtual void addCondiments()
    {
        cout << "add milk and sugar" << endl;
    }
    virtual void pourInCup()
    {
        cout << "pour coffee in cup" << endl;
    }
};

void make_beverage(abstractBeverage *b)
{
    b->start();
    delete b; // warning: delete called on 'abstractBeverage' that is abstract but has non-virtual destructor
}

int main()
{
    make_beverage(new milkTea);
    cout << "===========================" << endl;
    make_beverage(new coffee);
}