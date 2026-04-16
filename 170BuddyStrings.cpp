#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        if (s == goal) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
                if (freq[c - 'a'] > 1) return true;
            }
            return false;
        }

        vector<int> diff;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        return diff.size() == 2 &&
               s[diff[0]] == goal[diff[1]] &&
               s[diff[1]] == goal[diff[0]];
    }
};

int main() {
    Solution sol;

    cout << sol.buddyStrings("ab", "ba") << endl; // 1 (true)
    cout << sol.buddyStrings("ab", "ab") << endl; // 0 (false)
    cout << sol.buddyStrings("aa", "aa") << endl; // 1 (true)

    return 0;
}