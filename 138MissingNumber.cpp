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

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        for(int i = 0; i <= nums.size(); i++)
            if(!s.count(i))
                return i;

        return -1;
    }
};
*/

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int expected = n * (n + 1) / 2;

        int actual = 0;
        for(int x : nums)
            actual += x;

        return expected - actual;
    }
};
*/