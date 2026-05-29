#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    bool check(string num, long long a, long long b, int start) {

        while (start < num.size()) {

            long long c = a + b;
            string s = to_string(c);

            if (num.substr(start, s.size()) != s)
                return false;

            start += s.size();

            a = b;
            b = c;
        }

        return true;
    }

    bool isAdditiveNumber(string num) {

        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {

            // leading zero check for first number
            if (num[0] == '0' && i > 1)
                break;

            long long first = stoll(num.substr(0, i));

            for (int j = 1; max(i, j) <= n - i - j; j++) {

                // leading zero check for second number
                if (num[i] == '0' && j > 1)
                    break;

                long long second = stoll(num.substr(i, j));

                if (check(num, first, second, i + j))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    Solution sol;

    string num1 = "112358";
    string num2 = "199100199";
    string num3 = "12345";

    cout << sol.isAdditiveNumber(num1) << endl; // 1 (true)
    cout << sol.isAdditiveNumber(num2) << endl; // 1 (true)
    cout << sol.isAdditiveNumber(num3) << endl; // 0 (false)

    return 0;
}