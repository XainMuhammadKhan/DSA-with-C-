#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;

void Push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = value;
}

void Pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << stack[top--] << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements are: ";
    for (int i = top; i >= 0; --i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "Enter 1 to Push" << endl << "Enter 2 to Pop" << endl << "Enter 3 to Display" << endl << "Enter 4 to Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                Push(value);
                break;
            case 2:
                Pop();
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
