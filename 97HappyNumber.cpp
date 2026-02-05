#include<iostream>
#include<unordered_set>
#include<iomanip>       // required for boolalpha
using namespace std;
class Solution {
public:
    int nextnum(int n){
        int sum = 0;
        while(n > 0){
            int d = n % 10;
            sum += d * d;
            n = n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = nextnum(n);
        }
        if(n == 1) return true;
        else
        return false;
    }
};

int main(){
    Solution obj;
    cout<<boolalpha; // foor printing in boolean
    bool result = obj.isHappy(19); // 19 prints 1
    cout<<result;
    return 0;
}