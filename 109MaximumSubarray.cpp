#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int best = nums[0], current = nums[0];
        for(int i = 1; i < (int)nums.size(); i++){
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }
        return best;
    }
};
//Kadane’s Algorithm (O(n))
int main(){
    Solution obj;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = obj.maxSubArray(nums);
    cout<<result;
    return 0;
}