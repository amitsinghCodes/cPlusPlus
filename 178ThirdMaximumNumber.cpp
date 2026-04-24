#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        if (s.size() < 3) return *s.rbegin();

        auto it = s.rbegin();
        advance(it, 2);
        return *it;
    }
};

int main() {
    vector<int> nums = {2, 2, 3, 1};
    vector<int> nums2 = {1,2};
    Solution sol;
    cout << sol.thirdMax(nums) << endl;
    cout << sol.thirdMax(nums2) << endl;

    return 0;
}