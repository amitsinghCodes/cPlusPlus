#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {

        int remainingBytes = 0;

        for (int num : data) {

            if (remainingBytes == 0) {

                if ((num >> 7) == 0) {
                    continue;
                }
                else if ((num >> 5) == 0b110) {
                    remainingBytes = 1;
                }
                else if ((num >> 4) == 0b1110) {
                    remainingBytes = 2;
                }
                else if ((num >> 3) == 0b11110) {
                    remainingBytes = 3;
                }
                else {
                    return false;
                }
            }
            else {

                if ((num >> 6) != 0b10)
                    return false;

                remainingBytes--;
            }
        }

        return remainingBytes == 0;
    }
};

int main() {

    Solution sol;

    vector<int> data1 = {197,130,1};
    vector<int> data2 = {235,140,4};

    cout << sol.validUtf8(data1) << endl; // 1
    cout << sol.validUtf8(data2) << endl; // 0

    return 0;
}