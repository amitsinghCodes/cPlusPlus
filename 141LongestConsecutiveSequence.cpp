#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int length = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    length++;
                }

                if (length > longest)
                    longest = length;
            }
        }

        return longest;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution obj;
    cout << obj.longestConsecutive(nums) << endl;

    return 0;
}