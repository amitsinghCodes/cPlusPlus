#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        vector<int> count(nums.size(), 0);

        for(auto x : nums) {

            count[x]++;

            if(count[x] > 1)
                return x;
        }

        return -1;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,3,4,2,2};
    cout<<obj.findDuplicate(nums);
    return 0;
}