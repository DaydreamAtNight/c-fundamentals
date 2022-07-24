// implements a generic array featuring:
// - compatible custom types
// - save in HEAP memory
// - capacity is an arg of constructor
// - dynamic capacity
// - copy constructor to prevent shallow copy (because of the HEAP memory)
// - add/remove elements at the end of the array
// - get/set element at index
// - get size/capacity of array

#include<iostream>
using namespace std;

template <class T>
class GenericArray
{
private:
    T * m_array;
    int m_size;
    int m_capacity;

public:
    GenericArray(int capacity);
    GenericArray(const GenericArray<T> & other);
    ~GenericArray();
    GenericArray<T> & operator=(const GenericArray<T> & other);
    T & operator[](int index);
    int getSize();
    int getCapacity();
    void add(T element);
    void remove(int index);
};

// ------------------------------------------------------------

template <class T>
GenericArray<T>::GenericArray(int capacity)
{
    m_size = 0;
    m_capacity = capacity;
    m_array = new T[m_capacity];
}

template <class T>
GenericArray<T>::GenericArray(const GenericArray<T> & other)
{

    m_size = other.m_size;
    m_capacity = other.m_capacity;

    // deep copy m_array
    m_array = new T[m_capacity];
    for (int i = 0; i < other.m_size; i++)
    {
        m_array[i] = other.m_array[i];
    }
}

template <class T>
GenericArray<T>::~GenericArray()
{

    if (m_array != NULL)
    {
        delete[] m_array;
        m_array = NULL;
    }
}

template<class T>
GenericArray<T> & GenericArray<T>::operator=(const GenericArray<T> & other)
{
    if (m_array != NULL)
    {
        delete[] m_array;
        m_array = NULL;
    }

    if (this != &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        // deep copy m_array
        m_array = new T[m_capacity];
        for (int i = 0; i < other.m_size; i++)
        {
            m_array[i] = other.m_array[i];
        }
    }
    return *this;
}

template<class T>
T & GenericArray<T>::operator[](int index)
{
    if (index < 0 || index >= m_size)
    {
        throw "Index out of bounds";
    }
    return m_array[index];
}


template <class T>
int GenericArray<T>::getSize()
{
    return m_size;
}

template <class T>
int GenericArray<T>::getCapacity()
{
    return m_capacity;
}

template <class T>
void GenericArray<T>::add(T element)
{
    if (m_size == m_capacity)
    {
        cout << "Array is full, capacity doubled" << endl;
        m_capacity *= 2;
        T * newArray = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            newArray[i] = m_array[i];
        }
        delete[] m_array;
        m_array = newArray;
    }
    m_array[m_size] = element;
    m_size++;
}

template <class T>
void GenericArray<T>::remove(int index)
{
    for (int j = index; j < m_size - 1; j++)
    {
        m_array[j] = m_array[j + 1];
    }

}

