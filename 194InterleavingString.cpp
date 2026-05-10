#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size())
            return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {

            for (int j = 0; j <= n; j++) {

                // take character from s1
                if (i > 0 &&
                    s1[i - 1] == s3[i + j - 1]) {

                    dp[i][j] =
                        dp[i][j] || dp[i - 1][j];
                }

                // take character from s2
                if (j > 0 &&
                    s2[j - 1] == s3[i + j - 1]) {

                    dp[i][j] =
                        dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

int main() {

    Solution sol;

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    bool ans = sol.isInterleave(s1, s2, s3);
    cout<<boolalpha;

    cout << ans << endl;

    return 0;
}