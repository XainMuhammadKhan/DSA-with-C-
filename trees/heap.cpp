#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void MinHeapify(int arr[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, size, smallest);
    }
}

void buildMinHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        MinHeapify(arr, size, i);
    }
}

void insert(int arr[], int size) {
    if (size == 0) {
        cout << "Enter Value: ";
        cin >> arr[0];
        size++;
        return;
    }
    cout << "Enter Value: ";
    cin >> arr[size];
    int i = size;
    size++;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteRoot(int arr[], int& size) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    swap(arr[0], arr[size - 1]);
    size--;
    heapify(arr, size, 0);
}

void heapSort(int arr[], int size) {
    buildHeap(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter Array Length: ";
    cin >> n;
    int arr[n];
    int size = 0;
    int choice;
    do {
        cout << endl << "Enter 1 to Insert" << endl << "Enter 2 for Max Heap" << endl << "Enter 3 for Heap Sort" << endl << "Enter 4 for Min Heap" << endl << "Enter 5 for Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                insert(arr, size);
                break;
            case 2:
                buildHeap(arr, size);
                cout << "Max Heap Array: ";
                printArray(arr, size);
                break;
            case 3:
                heapSort(arr, size);
                cout << "Heap Sorted: ";
                printArray(arr, size);
                break;
            case 4:
                buildMinHeap(arr, size);
                cout << "Min Heap Array: ";
                printArray(arr, size);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
