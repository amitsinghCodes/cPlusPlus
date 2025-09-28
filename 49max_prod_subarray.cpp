#include <iostream>
using namespace std;

int max_prod(const int * ptr, int size){
    int mpro = ptr[0], rpro = ptr[0];
    
    for(int i = 0;i<size;i++){
        int cpro = ptr[i];
        for(int j = i+1;j<size;j++){
            cpro = cpro * ptr[j];
            if(cpro > mpro && cpro > ptr[i]){
                mpro = cpro;
            }
        }
        if(mpro > rpro)
        rpro = mpro;
    }
    return rpro;
}

int main() {
int arr[] = {1,2,4,-4,0,-1,9,5,2};
int size = sizeof(arr)/sizeof(arr[0]);
 cout<<max_prod(arr,size);
    return 0;
}