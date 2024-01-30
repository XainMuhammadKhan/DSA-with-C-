#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, i;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string opt;
    cout << "Enter method option: ";
    cin >> opt;

    if (opt == "a")
    {
        bubbleSort(arr, n);
        cout << "Array after bubble sort: ";
        printArray(arr, n);
    }
    else if (opt == "b")
    {
        selectionSort(arr, n);
        cout << "Array after selection sort: ";
        printArray(arr, n);
    }
    else if (opt == "c")
    {
        insertSort(arr, n);
        cout << "Array after insertion sort: ";
        printArray(arr, n);
    }
    else
    {
        cout << "Invalid option. Exiting." << endl;
        return 1; // Exiting with an error code
    }

    return 0;
}
