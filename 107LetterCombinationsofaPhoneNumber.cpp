#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string path;

        function<void(int)> dfs = [&](int idx) {

            if (idx == digits.size()) {
                ans.push_back(path);
                return;
            }

            int d = digits[idx] - '0';

            for (char ch : mp[d]) {
                path.push_back(ch);
                dfs(idx + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return ans;
    }
};

int main() {

    Solution obj;

    string digits = "23";

    vector<string> result = obj.letterCombinations(digits);

    cout << "Combinations:\n";

    for (string s : result) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}
