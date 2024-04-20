#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << queue[front++] << endl;
    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; ++i) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "Enter 1 to enqueue" << endl << "Enter 2 to dequeue" << endl << "Enter 3 to Display" << endl << "Enter 4 to Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
