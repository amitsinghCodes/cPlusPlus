#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(int n, int open, int close, string curr, vector<string>& ans) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            solve(n, open + 1, close, curr + "(", ans);
        }

        if (close < open) {
            solve(n, open, close + 1, curr + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, 0, 0, "", ans);
        return ans;
    }
};

int main() {
    int n = 3;

    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}