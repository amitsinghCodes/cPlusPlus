#include<iostream>

using namespace std;

int main(){
    int *digit = new int(44444);
    int *sum = new int(0);
    while(*digit>0){
        *sum += *digit%10;
        *digit = *digit/10;
    }

    cout << *sum;

    return 0;
}