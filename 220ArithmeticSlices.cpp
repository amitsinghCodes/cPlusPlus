#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int curr = 0;
        int total = 0;

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                curr++;
                total += curr;
            } else {
                curr = 0;
            }
        }

        return total;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;
    cout << sol.numberOfArithmeticSlices(nums) << endl;

    return 0;
}