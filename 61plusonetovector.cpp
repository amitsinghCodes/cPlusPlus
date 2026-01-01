#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int number = digits[0];
        int outnumber;
        if(digits.size() == 1){
                number = digits[0];
            }
            else
            for(int i = 1;i< digits.size();i++){
            number = 10*number + digits[i];
        }
        outnumber = number + 1;
    
    vector<int>ret_num;
    int remainder;
    while(outnumber != 0){
        remainder = outnumber % 10;
        ret_num.push_back(remainder);
        outnumber /= 10;
    }
    return ret_num;
    }
};

int main(){
    Solution obj;
    vector<int> ar = {9};
    vector<int>x;
    x = obj.plusOne(ar);
    for(int i = x.size() -1;i>=0;i--){
        cout<<x[i];
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // start from last digit
        for (int i = (int)digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {     // simple add without carry
                digits[i]++;
                return digits;
            }
            digits[i] = 0;           // carry continues
        }
        // if all digits were 9, we need one extra digit at front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution obj;
    vector<int> ar = {1,2,3};

    vector<int> x = obj.plusOne(ar);

    for (int d : x) cout << d;
    cout << "\n";
    return 0;
}

*/