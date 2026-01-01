#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numb,q,place;
    cin>>numb;
    bool result = false;
    vector<int> arrays,quereis;
    for(int i = 0; i<numb; i++)
    {
        cin>>arrays[i];
    }
        cin>>q;
        for(int i = 0; i<numb; i++)
    {
        cin>>quereis[i];
    }
    
    for(int i=0;i<q;i++){
    for(int k =0;k<numb;k++){
        if(quereis[i] == arrays[k]){
        result  =true;
        place = k+1;
    break;}
    }
    if(result == true)
    cout<<"Yes "<<place<<endl;
    else
    cout<<"No "<<place<<endl;}
    
    return 0;
}
