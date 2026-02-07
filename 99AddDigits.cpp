#include<iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        if(num % 10 == num){
            return num;
        }
        /* while(num >= 10){
            int sum = 0;
            while(num > 0){
                sum += num % 10;
                num = num/10;
            }
            num = sum;
        } */
        return 1 + (num - 1) % 9;
        return num;
    }
};

int main(){
    Solution obj;
    int result = obj.addDigits(38);
    cout<< result;
    return 0;
}