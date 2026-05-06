#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- && !pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int i = curr[1];
            int j = curr[2];

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution sol;
    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, k);

    for (auto &p : ans) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }

    return 0;
}