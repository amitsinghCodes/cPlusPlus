#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& path, vector<vector<int>>& ans, vector<bool>& used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            solve(nums, path, ans, used);

            // backtrack
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        solve(nums, path, ans, used);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution obj;
    vector<vector<int>> result = obj.permute(nums);

    for (auto& vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}