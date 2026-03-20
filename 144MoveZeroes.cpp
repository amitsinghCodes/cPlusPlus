#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        for(auto x : nums){
            if(x != 0){
                nums[start++] = x;
            }
        }
        for(int i = start; i < nums.size(); i++){
            nums[i] = 0;
        }
        cout<<"swaped 0s : ";
        for(auto x : nums){
            cout<<x<<" ";
        }
    }
};

int main(){
    Solution obj;
    vector<int> nums = {0,1,0,3,12};
    obj.moveZeroes(nums);
    return 0;
}


/*
void moveZeroes(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
*/