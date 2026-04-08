#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    Solution obj;
    cout<<obj.fib(10);
    return 0;
}

/*
// exponential time
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
*/

/*
 int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prev2 = 0; // F(0)
        int prev1 = 1; // F(1)

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
*/