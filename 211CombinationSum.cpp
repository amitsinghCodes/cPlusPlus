#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int index,
               vector<int>& candidates,
               int target,
               vector<int>& path,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (index >= candidates.size()) {
            return;
        }

        if (candidates[index] <= target) {

            path.push_back(candidates[index]);

            solve(index,
                  candidates,
                  target - candidates[index],
                  path,
                  ans);

            path.pop_back();
        }

        solve(index + 1,
              candidates,
              target,
              path,
              ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(0, candidates, target, path, ans);

        return ans;
    }
};

int main() {

    vector<int> candidates = {2,3,6,7};
    int target = 7;

    Solution sol;

    vector<vector<int>> ans =
        sol.combinationSum(candidates, target);

    for (auto v : ans) {

        cout << "[ ";

        for (int x : v) {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}