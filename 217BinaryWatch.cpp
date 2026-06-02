#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {

                int bits =
                    __builtin_popcount(h) +
                    __builtin_popcount(m);

                if (bits == turnedOn) {

                    string time = to_string(h) + ":";

                    if (m < 10)
                        time += "0";

                    time += to_string(m);

                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int turnedOn = 1;

    vector<string> ans = sol.readBinaryWatch(turnedOn);

    for (string s : ans)
        cout << s << endl;

    return 0;
}