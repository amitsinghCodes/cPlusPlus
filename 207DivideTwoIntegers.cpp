#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long dvd = abs((long)dividend);
        long dvs = abs((long)divisor);
        int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

        long quotient = 0;

        while (dvd >= dvs) {
            long temp = dvs;
            long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        return (int)(sign * quotient);
    }
};

int main() {
    Solution sol;

    // Test Case 1: 10 / 3 = 3
    cout << "10 / 3 = " << sol.divide(10, 3) << "  (expected 3)" << endl;

    // Test Case 2: 7 / -3 = -2
    cout << "7 / -3 = " << sol.divide(7, -3) << "  (expected -2)" << endl;

    // Test Case 3: Overflow edge case INT_MIN / -1
    cout << "INT_MIN / -1 = " << sol.divide(INT_MIN, -1) << "  (expected " << INT_MAX << ")" << endl;

    // Test Case 4: Negative dividend, positive divisor
    cout << "-10 / 3 = " << sol.divide(-10, 3) << "  (expected -3)" << endl;

    // Test Case 5: Both negative
    cout << "-10 / -3 = " << sol.divide(-10, -3) << "  (expected 3)" << endl;

    // Test Case 6: Dividend = 0
    cout << "0 / 5 = " << sol.divide(0, 5) << "  (expected 0)" << endl;

    // Test Case 7: Divisor = 1
    cout << "15 / 1 = " << sol.divide(15, 1) << "  (expected 15)" << endl;

    // Test Case 8: Divisor = -1
    cout << "15 / -1 = " << sol.divide(15, -1) << "  (expected -15)" << endl;

    return 0;
}