#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n - 1;
        while (nums[j] <= nums[i]) j--;

        swap(nums[i], nums[j]);

        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(){
    vector<int> num = {1,2,4,5};
    Solution obj;
    vector<int> start = num;
    vector<vector<int>> all;
    do {
       all.push_back(num);
       obj.nextPermutation(num);
       } while (num != start);

    cout << "Stored permutations:\n";
    for (auto &v : all) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }

    return 0;

}