#include <iostream>
using namespace std;

void swap(int& x, int& y){
   int t = x;
    x = y;
    y = t;
}

int main() {
    int arr[] = {45,23,44,1,42,33,54,32,56,91,10};
    int numatpos = 6; 
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array without sort : ";
    for(int i = 0; i< size - 1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i< size; i++){
        for(int j = 0; j<size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"Numbers after sorting : ";
    for(int i = 0 ;i< size -1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"number at position "<<numatpos<<" is : "<<arr[numatpos - 1];
    return 0;
}