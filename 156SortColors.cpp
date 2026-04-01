#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
void sortColors(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}
*/

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution obj;
    obj.sortColors(nums);

    cout << "Sorted array: ";
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}