#include <iostream>
using namespace std;

int main(){
    int *ptr,a,b;
    a = 20;
    ptr = &a;
    b = *ptr;
    cout<<b;
    cout<<"\n";
    cout<<&b;
    cout<<"\n";
    cout<<&*ptr;
    cout<<"\n";
    cout<<&a;
}
