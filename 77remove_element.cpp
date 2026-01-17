#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[count++] = nums[i]; 
            }
        }
        return count;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,4,5,5,3,9}; int val = 5;
    int ans = obj.removeElement(nums, val);
    cout<< ans;
    return 0;
}