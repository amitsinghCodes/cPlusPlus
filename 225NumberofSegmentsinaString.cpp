#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    string s = "Hello, my name is John";

    cout << sol.countSegments(s) << endl;

    return 0;
}