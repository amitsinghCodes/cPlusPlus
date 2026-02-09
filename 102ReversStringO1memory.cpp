#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
        for(auto x : s){
        cout<<x;
        }
    }
};

int main(){
    Solution obj;
    vector<char>str = {'h','e','l','l','o'};
    obj.reverseString(str);
    return 0;
}