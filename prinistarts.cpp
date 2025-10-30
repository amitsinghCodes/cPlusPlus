#include<iostream>
using namespace std;

int main(){
    int n = 3;
    for(int i = 1;i<=n ;i++){
        for(int k = i;k< n;k++){
            cout<<" ";
        }
        for(int j = 1; j <= (i * 2)- 1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}