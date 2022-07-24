// template to sort a list of elements using selection sort
#include<iostream>
using namespace std;

template<class T>
void selection_sort(T arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

template<class T>
void print_array(T arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr1[] = {3,5,2,6,8,4,1,2,2};
    double arr2[] = {3,5,2,6,8,4,1,2,2};
    selection_sort(arr1, 9);
    print_array(arr1, 9);
    selection_sort(arr2, 9);
    print_array(arr2, 9);
    return 0;
}