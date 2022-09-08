//this is cod for learning different sorting
#include <iostream>
using namespace std;


//---bubble sorting---
void bubble(int arr[], const int& n)
{
    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<(n-1); j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
//-------------------

//---selection sorting---
void selection(int arr[],const int& n)
{
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        k = i;
        for(int j = i; j < n; j++)
        {
            if(arr[k]>arr[j])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}
//-----------------------

//---insertion sort---
void insertion(int arr[], const int& n)
{
    int key = 0;
    int i = 0;
    for(int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1] = arr[i];
            i -= 1;
            arr[i+1] = key;
        }
    }
    
}
//--------------------

//---quick sort---
int Partition(int* arr,const int& l, const int& r)
{
    int x = arr[r];
    int less = l;
    for(int i = l; i < r; ++i)
    {
        if(arr[i] <= x)
        {
            swap(arr[i], arr[less]);
            ++less;
        }
        
    }
    swap(arr[less],arr[r]);
    return less;
}

void QuickSortImpl(int* arr, const int& l, const int& r)
{
    if(l < r)
    {
        int q = Partition(arr, l, r);
        QuickSortImpl(arr, l, q - 1);
        QuickSortImpl(arr, q + 1, r);
    }
}

void QuickSort(int* arr, const int& size)
{
    if(size > 0)
    {
        QuickSortImpl(arr, 0, size - 1);
    }
}
//----------------

void InizializyByArray(int* arr_one, int* arr_two, const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        arr_two[i] = arr_one[i];
    }
}

void OutArray(int* arr, const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
}

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    int n = 10;
    int arr[n], temp_array[n];
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Array value before sorting: "s;
    
    OutArray(arr, n);
    
    InizializyByArray(arr, temp_array, n);
    cout << endl << "Array value after bubble sorting: "s;
    bubble(temp_array, n);
    OutArray(temp_array, n);
    
    InizializyByArray(arr, temp_array, n);
    cout << endl << "Array value after selection sorting: "s;
    selection(temp_array,n);
    OutArray(temp_array, n);
    
    InizializyByArray(arr, temp_array, n);
    cout << endl << "Array value after insertion sorting: "s;
    insertion(temp_array, n);
    OutArray(temp_array, n);
    
    InizializyByArray(arr, temp_array, n);
    cout << endl << "Array value before quick sort: "s;
    QuickSort(temp_array, n);
    OutArray(temp_array, n);
    
    
    cout << endl;
    OutArray(arr, n);
    cout << endl;
    return 0;
}
