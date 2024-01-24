#include <iostream>
using namespace std;

int main() {
    int flag = 0;
    int arr[10] = {11, 21, 28, 32, 35, 49, 57, 78, 112, 175};
    int toBeFound;

    cout << "Enter value to be searched: ";
    cin >> toBeFound;

    int left = 0;
    int len = sizeof(arr) / sizeof(int);
    int right = len - 1;
    int midIndex;

    for (int i = 0; left <= right; i++) {
        midIndex = (left + right) / 2;

        if (arr[midIndex] == toBeFound) {
            flag = 1;
            break;
        } else if (arr[midIndex] < toBeFound) {
            left = midIndex + 1;
        } else {
            right = midIndex - 1;
        }
    }

    if (flag)
        cout << "Element found at index " << midIndex;
    else
        cout << "Element not found" ;

    return 0;
}
