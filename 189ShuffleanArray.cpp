#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> arr = original;
        int n = arr.size();

        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }

        return arr;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution obj(nums);

    vector<int> shuffled = obj.shuffle();
    for (int x : shuffled) cout << x << " ";
    cout << endl;

    vector<int> resetArr = obj.reset();
    for (int x : resetArr) cout << x << " ";
    cout << endl;

    return 0;
}