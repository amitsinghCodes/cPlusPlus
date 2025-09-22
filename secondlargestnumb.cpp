// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    
    int arr[5] = {1,4,6,3,8};
    
    int first, second,largest;
    int zisee = sizeof(arr)/sizeof(arr[0]);
   
        if(arr[0]<arr[1]){
            first = arr[1];
            second = arr[0];
        }
        else
        {
            first = arr[0];
            second = arr[1];
        }
         largest = arr[0];
         for(int i = 2;i<zisee; i++){
             if(arr[i]>first){
                 second = first;
                 first = arr[i];
             }
             else if(arr[i]>second && arr[i]!= first){
                 second = arr[i];
             }
            
    }
    
    cout<<largest<<first <<second;
    
    

    return 0;
}