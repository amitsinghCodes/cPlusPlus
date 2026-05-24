#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    cout << sol.hammingWeight(11) << endl;   // 3
    cout << sol.hammingWeight(128) << endl;  // 1
    cout << sol.hammingWeight(7) << endl;    // 3

    return 0;
}