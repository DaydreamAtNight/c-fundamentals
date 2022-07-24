// calulator designed in polymorphism

#include <iostream>
using namespace std;

class abstructAalculator
{
protected:
    int m_A, m_B, m_result;

public:
    abstructAalculator &set_a(int a)
    {
        m_A = a;
        return *this;
    }
    abstructAalculator &set_b(int b)
    {
        m_B = b;
        return *this;
    }
    virtual abstructAalculator &cal() { return *this; }
    int get_result()
    {
        return m_result;
    }
};

class addCalculator : public abstructAalculator
{
public:
    addCalculator &cal()
    {
        m_result = m_A + m_B;
        return *this;
    }
};

class subtructCalculator : public abstructAalculator
{
public:
    subtructCalculator &cal()
    {
        m_result = m_A - m_B;
        return *this;
    }
};

class multiplyCalculator : public abstructAalculator
{
public:
    multiplyCalculator &cal()
    {
        m_result = m_A * m_B;
        return *this;
    }
};

void cal_reference_f(abstructAalculator &c)
{
    c.cal();
}

void calculator_reference()
{
    subtructCalculator c;
    cal_reference_f(c.set_a(10).set_b(20));
    cout << c.get_result() << endl;
}

void calculator_pointer()
{
    abstructAalculator *c = new subtructCalculator();
    cout << c->set_a(10).set_b(20).cal().get_result() << endl;
    if (c != NULL)
    {
        delete c;
        c = NULL;
    }
}

int main()
{
    calculator_reference();
    // calculator_pointer();
    return 0;
}
