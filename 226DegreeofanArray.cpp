#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> count;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int degree = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (!first.count(nums[i]))
                first[nums[i]] = i;

            last[nums[i]] = i;

            count[nums[i]]++;

            degree = max(degree, count[nums[i]]);
        }

        int ans = nums.size();

        for (auto &p : count) {

            int num = p.first;

            if (p.second == degree) {
                ans = min(ans, last[num] - first[num] + 1);
            }
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1,2,2,3,1};

    Solution sol;

    cout << sol.findShortestSubArray(nums) << endl;

    return 0;
}