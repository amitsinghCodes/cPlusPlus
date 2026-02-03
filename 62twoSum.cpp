#include<iostream>
using namespace std;
#include<vector>
#include<iterator>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>x;
        bool flag = false;
        if(flag == false && nums.size() > 1)
        for(int i = 0; i < nums.size(); i++){
            if(flag == false)
            for(int j = 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    if(i != j){
                        x.push_back(i);
                    x.push_back(j);
                    flag = true;
                    }
                }
            }
       }
       else
       return nums;
       return x;
    }
};

int main(){
    Solution obj;
    vector<int> x = {2,3,4,5,6,1} ,y;
    y = obj.twoSum(x, 9);
    for(vector<int>::iterator it = y.begin(); it !=y.end(); it++){
        cout<<*it;
    }
return 0;
}

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if(mp.find(need) != mp.end()){
                return {mp[need] , i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
*/