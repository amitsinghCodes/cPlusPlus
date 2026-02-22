#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    int r = 3;

    int n = v.size();
        r = r % n;
    
    vector<int> temp(n);
    for(int i = 0; i < n; i++){
        temp[(i + r) % n] = v[i]; 
    }

    for(auto x : temp){
        cout<<x << " ";
    }
    return 0;
}


/*
vector<int> temp;

    // Step 1: Push last r elements
    for(int i = n - r; i < n; i++) {
        temp.push_back(v[i]);
    }

    // Step 2: Push remaining elements
    for(int i = 0; i < n - r; i++) {
        temp.push_back(v[i]);
    }

    // Print result
    for(int x : temp)
        cout << x << " ";

    return 0;
*/