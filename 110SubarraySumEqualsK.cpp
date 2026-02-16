#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};
/*
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;               // empty prefix

        int prefix = 0;
        int count = 0;

        for (int x : nums) {
            prefix += x;

            // how many previous prefixes = prefix - k ?
            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }
*/
int main(){
    Solution obj;
    vector<int> nums = {1,1,1}; int k = 2;
    cout<<obj.subarraySum(nums, k);
    return 0;
}