#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> oddevencount(int arr[]);

int main(){
    int numarr[7]  = {1,2,3,4,5,6,7};
 vector<int> v1;
    v1 = oddevencount(numarr);


    return 0;
}

vector<vector<int>> oddevencount(int arr[]){
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    int ecount =0, ocount=0, evarr[arrsize], odarr[arrsize];
    for(int i= 0;i<arrsize;i++){
        if (arr[i]%2 == 0){
            ecount++;
        }
        else ocount++;
    }

    return  ecount + ocount + evarr + odarr;

}