#include <iostream>
using namespace std;

int arrAdd(int *arr,int *ptr){
    for (int i = 0; i < *ptr; i++)
    {
        arr[i] += 5;
    }
    for (int i = 0; i < *ptr; i++)
    {
        cout<<arr[i]<<",";
        
    }
    
}

int main()
{   int size = 5;
    int *ptr = &size;
    int myArr[size];
    cout<< "Enter elements";
    for (int i = 0; i < size; i++)
    {
        cin>>myArr[i];
        
    }
    arrAdd(myArr,ptr);
    
    
}