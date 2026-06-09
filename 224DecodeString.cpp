#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(curr);

                num = 0;
                curr = "";
            }

            else if (ch == ']') {

                int repeat = countStack.top();
                countStack.pop();

                string temp = curr;

                curr = stringStack.top();
                stringStack.pop();

                while (repeat--) {
                    curr += temp;
                }
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};

int main() {

    Solution sol;

    cout << sol.decodeString("3[a]2[bc]") << endl;
    cout << sol.decodeString("3[a2[c]]") << endl;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;

    return 0;
}