#include<iostream>

using namespace  std;

int* sumofnatural(int *number){
    int *sum = new int(0);
    for(int i = 1; i<=*number;i++){
        *sum = *sum + i;
    }
    return sum;
}

int main(){
    int* number = new int(9);
    int* totalsum = sumofnatural(number);
    cout<<*totalsum;

    return 0;
}