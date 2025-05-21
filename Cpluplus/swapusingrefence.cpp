#include<iostream>

using namespace std;

void swap(int * a, int* b){
    int temp = *a;
    *a = * b;
    *b = temp;
}

void swap2(int  a, int b){
    int temp = a;
    a =  b;
    b = temp;
}


int main(){

    int x = 10, y = 9, n = 5, m = 6;
    cout << "x = " << x << " y = " << y << endl;
    cout << "n = " << n << " m = " << m << endl;
    swap(&x, &y);
    swap2(n,m);
    cout << "x = " << x << " y = " << y << endl;
    cout << "n = " << n << " m = " << m << endl;
    return 0;
}