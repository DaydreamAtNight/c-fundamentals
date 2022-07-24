#include "9_temp_cls_func_files.h"

template <class nameType, class ageType>
Person<nameType, ageType>::Person (nameType name, ageType age)
{
    m_name = name;
    m_age = age;
}

template <class nameType, class ageType>
void Person<nameType, ageType>::print_person()
{
    cout << m_name << " " << m_age << endl;
}
