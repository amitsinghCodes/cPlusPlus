#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums.size()/2;
        map<int,int> freq;
        for(auto x : nums){
            freq[x]++;
        }
        int best = 0;
        for(auto x : nums){
            if(freq[x] > maj && freq[x] > best){
                best = x;
            }
        }
        return best;
    }
};

int main(){
    vector<int> num = {4,6,6,5,2,2,2,4,5,6,6,6,6,6,4,6,6};
    Solution obj;
    int result = obj.majorityElement(num);
    cout<<"majority element is :"<< result;
    return 0;
}