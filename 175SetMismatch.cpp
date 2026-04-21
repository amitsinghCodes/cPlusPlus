#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                duplicate = abs(nums[i]);
            } else {
                nums[idx] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }

        return {duplicate, missing};
    }
};

int main() {
    vector<int> nums = {1,2,2,4};

    Solution sol;
    vector<int> ans = sol.findErrorNums(nums);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}