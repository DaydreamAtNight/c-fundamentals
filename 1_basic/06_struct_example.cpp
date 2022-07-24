#include<iostream>
using namespace std;

struct hero{
        string name;
        int age;
        char gender; // 'F' or 'M'
    };

void printHeroes(const hero hero_array[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout << hero_array[i].name << '\t' 
            << hero_array[i].gender << '\t' 
            << hero_array[i].age << endl;
    }
    cout<<endl;
}

void bubbleSortingAge(hero hero_array[], int len)
{
    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {
            if (hero_array[j].age<hero_array[j+1].age)
            {
                hero temp=hero_array[j];
                hero_array[j]=hero_array[j+1];
                hero_array[j+1]=temp;
            }
        }
    }  
}

int main(){

    hero teachers[5] = {
        {"Aliyunll",20,'M'},
        {"Rouroull",6,'F'},
        {"Shoushou",8,'M'},
        {"pingping",35,'F'},
        {"guanguan",79,'M'}
    };
    printHeroes(teachers,5);
    bubbleSortingAge(teachers,5);
    printHeroes(teachers,5);

    return 0;
}
