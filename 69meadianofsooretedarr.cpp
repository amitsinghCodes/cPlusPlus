// Meadian of two sorted arrays.
//Median definition
//If total count is odd → middle element
//If total count is even → average of the two middle elements
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2 == 1){
            return (float)nums1.at(nums1.size()/2);
        }
        else{
            float sum = (nums1.at(nums1.size()/2) + nums1.at(nums1.size()/2 - 1))/2.0;
            return sum;
        }
    }
};

int main(){
    Solution obj;
    vector<int> nums1 = {2,4,5,6}, nums2 = {2,4,7,9};       // 2 2 4 4 5 6 7 9
    double x = obj.findMedianSortedArrays(nums1, nums2);
    cout<<x;               // 4.5
    return 0;
}

