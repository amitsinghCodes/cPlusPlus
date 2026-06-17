#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {

        if (n <= 0)
            return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};

int main() {

    Solution sol;

    cout << boolalpha;

    cout << sol.isPowerOfThree(27) << endl; // true
    cout << sol.isPowerOfThree(0) << endl;  // false
    cout << sol.isPowerOfThree(9) << endl;  // true
    cout << sol.isPowerOfThree(45) << endl; // false

    return 0;
}