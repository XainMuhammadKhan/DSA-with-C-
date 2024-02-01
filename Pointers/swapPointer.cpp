#include <iostream>
using namespace std;

int swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    // cout <<"\n";
    // cout <<*a;
    // cout <<"\n";
    // cout <<*b;
    // cout <<"\n";
    return *a;
}

int main(){
    int x =5,y=6;
    cout<<x;
    cout<<"\n";
    cout<<y;
    swap(&x,&y);
    cout <<"\n";
    cout <<x;
    cout <<"\n";
    cout <<y;
}
