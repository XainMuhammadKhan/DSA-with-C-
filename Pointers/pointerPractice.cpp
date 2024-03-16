#include <iostream>
using namespace std;

int main(){
    // a data type that holds address of other data types
    //&:address of operator

    int a = 3;
    int * b = &a; 
    cout<<"The address of a is: "<<b<<endl;
    cout<<"The address of a is: "<<&a<<endl;

// * --> (value at) derefrence operator
cout<<"The value of a is: "<<*b<<endl;
cout<<"The value of a is: "<<*&a<<endl;

// pointer for pointer variable
    int ** c = &b;
    cout<<&b<<endl;
    cout<<c<<endl;
    cout<<*c<<endl;
    cout<<**&b<<endl;
    return 0;
}