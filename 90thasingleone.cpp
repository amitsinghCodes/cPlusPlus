#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto n : nums){
            freq[n]++;
        }
        for(auto n : nums){
            if(freq[n] == 1)
            return n;
        }
        return 0;
    }
};

int main(){
    vector<int>nums = {1,2,4,5,6,8,6,5,4,2,1,9,9};
    Solution obj;
    int ans = obj.singleNumber(nums);
    cout<< ans;
    return 0;
}