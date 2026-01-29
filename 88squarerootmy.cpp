#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while(r * r > x){
            r = (r + x/r) / 2;
        }
        return (int)r;
    }
};

int main(){
    Solution obj;
    int result = obj.mySqrt(9);
    cout<<result;
    return 0;
}