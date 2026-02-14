#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) return {};

        // Sort by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end   = intervals[i][1];

            int& lastEnd = result.back()[1];

            if (start <= lastEnd) {
                lastEnd = max(lastEnd, end);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    Solution obj;
    vector<vector<int>> merged = obj.merge(intervals);

    cout << "Merged Intervals:\n";

    for (int i = 0; i < merged.size(); i++) {
        cout << "[" << merged[i][0] << "," << merged[i][1] << "] ";
    }

    return 0;
}
