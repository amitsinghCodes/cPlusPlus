#include <iostream>
#include <vector>
using namespace std;
int main() {
    string a = "mashishma";
    vector<int>freq(256,0);
    char best = ' ';
    for(char c : a){
        freq[c]++;
    }
    for(char c : a){
        if(freq[c] == 1)
        best = c;
        break;
    }
    cout<<best<<endl;
    return 0;
}