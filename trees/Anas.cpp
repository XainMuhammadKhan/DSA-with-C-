#include<iostream>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    return head; 
}
insertBeginning(Node* head, int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = head;
    head = node;
    return head; 
}

delete(Node* head,int x) {
    Node* temp = head;
    if (temp!= NULL && temp->data == x) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!=NULL) {
    {
        temp = temp->next;
        if (temp->next!= NULL && temp->data == x) {

    }
    
    
}}} 
void Traversal(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL; // Initialize head to NULL
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);
    Traversal(head);
    return 0;
}
