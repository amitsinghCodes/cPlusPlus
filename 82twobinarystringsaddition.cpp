#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0; 
        int n = a.size() - 1;
        int m = b.size() - 1;
        string ans;

        while(n >= 0 || m >= 0 || carry){
            int sum = carry;

            if(n >= 0){sum += (a[n--] - '0');}
            if(m >= 0){sum += (b[m--] - '0');}

            ans.push_back((sum % 2) + '0');
            carry = sum/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    string str1 = "1101", str2 = "1010", str;
    str = obj.addBinary(str1,str2);
    for(auto c : str){
        cout<< c;
    }
    return 0;
}