#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c | 32;  // bit trick
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s1 = "Hello";
    string s2 = "LOVELY";
    string s3 = "here";

    cout << "Input: " << s1 << " -> Output: " << sol.toLowerCase(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << sol.toLowerCase(s2) << endl;
    cout << "Input: " << s3 << " -> Output: " << sol.toLowerCase(s3) << endl;

    return 0;
}