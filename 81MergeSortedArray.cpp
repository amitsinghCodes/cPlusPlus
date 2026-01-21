#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for (int i = 0; i < m; i++) temp.push_back(nums1[i]);
        nums1 = temp;
        for(auto num : nums2){
            nums1.push_back(num);
        }
        sort(nums1.begin(), nums1.end());
        for(auto x : nums1){
        cout<<x << " ";
    }
    }
    
};

int main(){
    Solution obj;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;
    obj.merge(nums1,m,nums2,n);
    return 0;
}