#include <iostream>
#include <stdlib.h>
using namespace std;




struct Queue{

int value;
Queue *next;


};


Queue *front = nullptr;
Queue *rear=nullptr;



void enqueue(){

Queue * ptr = (Queue *)malloc(sizeof(Queue));
int val;
cout << "Enter any number";
cin >> val;

ptr->value = val;


Queue *curr = front;
if(front == nullptr){
front = ptr;
rear=ptr;
}

else{

rear->next = ptr;
rear=rear->next;


}



}





void dequeue(){

if(front == NULL){

cout << "Queue is empty" << endl;
return;


}


else{

  cout << front->value  << endl;
    Queue* curr = front;
    front = front->next;
    free(curr);


}

}





void display() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements are: ";
    Queue *curr=front;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}







int main(){



    int n;
    do {
        cout << "Enter 1 to enqueue " << endl << "Enter 2 to dequeue " << endl << "Enter 3 to Display" << endl;
        cin >> n;
        if (n == 1){
            enqueue();
        }
        else if (n == 2){
             dequeue();
        }
       else if (n == 3){
             display();
        }
        
    } while (n != 4);



}