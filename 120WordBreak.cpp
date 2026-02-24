#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> str(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<bool>dp(n + 1, false);
        dp[0] = true;

        int maxLen = 0;
        for(auto &w : wordDict) maxLen = max((int)w.size(), maxLen);

        for(int i = 1; i <= n; i++){
            for(int len = 1; len <= maxLen && len <= i; len++){
                int j = i - len;
                if(!dp[j]) continue;

                if(str.find(s.substr(j, len)) != str.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution obj;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool result = obj.wordBreak(s, wordDict);

    cout << "Can be segmented? ";
    cout << (result ? "True" : "False") << endl;

    return 0;
}