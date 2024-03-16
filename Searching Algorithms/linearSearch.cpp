#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {55, 92, 32, 81, 72, 56, 99, 120, 22, 89};
    int flag = 0;
    int toBeFound;
    cout << "Type a number to be found: ";
    cin >> toBeFound;
    for (int i = 0; i < 10; i++)
    {
        int accquiredVal = arr[i];
        if (accquiredVal == toBeFound)
        {
            cout << "Desired Value Has Been Found!";
            flag++;
        }
        
    }
    if (flag == 0)
    {
        cout << "Desired Value doesnot exist in the defined array!";
    }
}