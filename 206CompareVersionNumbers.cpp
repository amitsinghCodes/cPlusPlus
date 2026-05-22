#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;

        while (i < version1.size() || j < version2.size()) {
            long num1 = 0, num2 = 0;

            while (i < version1.size() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            while (j < version2.size() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            i++;
            j++;
        }

        return 0;
    }
};

int main() {
    Solution sol;

    cout << sol.compareVersion("1.2", "1.10") << endl;
    cout << sol.compareVersion("1.01", "1.001") << endl;
    cout << sol.compareVersion("1.0", "1.0.0") << endl;

    return 0;
}