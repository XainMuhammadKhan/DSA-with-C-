#include <iostream>
#include <stdlib.h>
using namespace std;




struct Stack{

int value;
Stack *next;


};


Stack *top = nullptr;

void Push(){

Stack * ptr = (Stack *)malloc(sizeof(Stack));
int val;
cout << "Enter any number";
cin >> val;

ptr->value = val;


Stack *curr = top;
if(top == nullptr){
top = ptr;

}

else{


ptr->next = top;
top = ptr;




}



}





void Pop(){

if(top == NULL){

cout << "stack is empty" << endl;
return;


}


else{

  cout << top->value  << endl;
    Stack* curr = top;
    top = top->next;
   free(curr);


}

}





void display() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements are: ";
     Stack *curr=top;
    while(curr!=NULL){
        cout << curr->value << " ";
        curr = curr->next;
    }
//    cout << endl;
}







int main(){



    int n;
    do {
        cout << "Enter 1 to Push " << endl << "Enter 2 to Pop " << endl << "Enter 3 to Display" << endl;
        cin >> n;
        if (n == 1){
            Push();
        }
        else if (n == 2){
             Pop();
        }
       else if (n == 3){
             display();
        }
        
    } while (n != 4);



}
