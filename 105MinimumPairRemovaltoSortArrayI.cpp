#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {  
        int ops = 0;

        auto nonDecreasing = [&](const vector<int>& a) {
            for (int i = 1; i < (int)a.size(); ++i)
                if (a[i] < a[i - 1]) return false;
            return true;
        };

        while ((int)nums.size() > 1 && !nonDecreasing(nums)) {
            long long bestSum = (long long)nums[0] + nums[1];
            int idx = 0;

            for (int i = 1; i < (int)nums.size() - 1; ++i) {
                long long s = (long long)nums[i] + nums[i + 1];
                if (s < bestSum) {          // "<" keeps leftmost on ties automatically
                    bestSum = s;
                    idx = i;
                }
            }

            nums[idx] = (int)bestSum;
            nums.erase(nums.begin() + idx + 1);
            ++ops;
        }

        return ops;
    }
};

int main(){
    Solution obj;
    vector<int> vecn = {5,2,3,1};
    int result = obj.minimumPairRemoval(vecn);
    cout<<result;
    return 0;
}