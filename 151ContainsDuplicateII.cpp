#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.count(nums[i]) && i - lastIndex[nums[i]] <= k) {
                return true;
            }
            lastIndex[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    Solution obj;
    cout << (obj.containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;

    return 0;
}