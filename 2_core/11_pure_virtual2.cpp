// simiulate a workflow of a computer
// contains CPU, GPU, and memory
#include <iostream>
using namespace std;

// componentes of a computer
class abstractCPU
{
public:
    virtual void calculate() = 0;
};
class abstractGPU
{
public:
    virtual void display() = 0;
};
class abstractMemory
{
public:
    virtual void store() = 0;
};

// brands of components
class intelCPU : public abstractCPU
{
public:
    void calculate() { cout << "intel CPU calculating" << endl; }
};
class amdCPU : public abstractCPU
{
public:
    void calculate() { cout << "amd CPU calculating" << endl; }
};
class intelGPU : public abstractGPU
{
public:
    void display() { cout << "intel GPU displaying" << endl; }
};
class nividiaGPU : public abstractGPU
{
public:
    void display() { cout << "nividia GPU displaying" << endl; }
};
class intelMemory : public abstractMemory
{
public:
    void store() { cout << "intel Memory storing" << endl; }
};
class amdMemory : public abstractMemory
{
public:
    void store() { cout << "amd Memory storing" << endl; }
};

// computer assemble
class computer
{
protected:
    abstractCPU *m_cpu;
    abstractGPU *m_gpu;
    abstractMemory *m_memory;

public:
    computer(abstractCPU *cpu, abstractGPU *gpu, abstractMemory *memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }

    ~computer()
    {
        delete m_cpu;
        delete m_gpu;
        delete m_memory;
        m_cpu = NULL;
        m_gpu = NULL;
        m_memory = NULL;
    }

    void assemble()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_memory->store();
    }
};

int main()
{
    // assemble a computer
    computer *computer_asseble1 = new computer(new amdCPU, new nividiaGPU, new amdMemory);
    computer *computer_asseble2 = new computer(new intelCPU, new intelGPU, new intelMemory);
    computer *computer_asseble3 = new computer(new intelCPU, new nividiaGPU, new intelMemory);
    computer_asseble1->assemble();
    cout << "===================" << endl;
    computer_asseble2->assemble();
    cout << "===================" << endl;
    computer_asseble3->assemble();
    delete computer_asseble1;
    computer_asseble1 = NULL;
    delete computer_asseble2;
    computer_asseble2 = NULL;
    delete computer_asseble3;
    computer_asseble3 = NULL;
    return 0;
}
