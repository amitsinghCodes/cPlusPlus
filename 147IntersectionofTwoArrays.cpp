#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>result;
        for(auto x : nums1){
            for(auto y : nums2){
                if(x == y){
                    result.insert(x);
                }
            }
        }
        vector<int> ans(result.begin(), result.end());
        return ans;
    }
};
/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int x : nums2) {
            if (s.count(x)) {
                result.insert(x);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
*/
int main(){
    Solution obj;
    vector<int>nums1 = {4,9,5};
    vector<int>nums2 = {9,4,9,8,4};
    vector<int>result = obj.intersection(nums1, nums2); cout<<"Intersection of two integer arrays : ";
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}