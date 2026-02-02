#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) ans = mid;
                hi = mid - 1;      // go left
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) ans = mid;
                lo = mid + 1;      // go right
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstPos(nums, target), lastPos(nums, target) };
    }
};

int main(){
    Solution obj;
    vector<int>nums = {5,7,7,8,8,10};
    vector<int> ans = obj.searchRange(nums,8);
    for(auto x : ans){
        cout<< x<< " ";
    }
    return 0;
}