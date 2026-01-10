#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int reversal = 0;
        while(x != 0){
        int digit = x % 10;
        x /= 10;
        if(reversal > INT_MAX / 10 || reversal == INT_MAX / 10 && digit > 7)
        return 0;
        if(reversal < INT_MIN / 10 || reversal == INT_MIN / 10 && digit < -8)
        return 0;
        reversal = reversal * 10 + digit;
        }
        return reversal;
    }
};

int main(){
    Solution obj;
    int x = obj.reverse(-236);
    cout<<x;
    return 0;
}