#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find first unique character
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    cout << "Input: " << s1 << " -> Output: " << sol.firstUniqChar(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << sol.firstUniqChar(s2) << endl;
    cout << "Input: " << s3 << " -> Output: " << sol.firstUniqChar(s3) << endl;

    return 0;
}