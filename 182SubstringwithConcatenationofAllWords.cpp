#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();

        if (n < totalLen) return ans;

        unordered_map<string, int> need;
        for (string &w : words) need[w]++;

        for (int start = 0; start < wordLen; start++) {
            int left = start, count = 0;
            unordered_map<string, int> window;

            for (int right = start; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (need.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}