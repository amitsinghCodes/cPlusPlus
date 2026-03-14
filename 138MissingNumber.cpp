#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorVal = nums.size();

        for(int i = 0; i < nums.size(); i++){
            xorVal ^= i ^ nums[i];
        }

        return xorVal;
    }
};

int main() {

    vector<int> nums = {3,0,1};

    Solution obj;

    cout << "Missing number: " << obj.missingNumber(nums);

    return 0;
}