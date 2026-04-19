#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];

        int area = x1 * (y2 - y3) +
                   x2 * (y3 - y1) +
                   x3 * (y1 - y2);

        return area != 0;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> p1 = {{1,1},{2,3},{3,2}};
    vector<vector<int>> p2 = {{1,1},{2,2},{3,3}};

    cout << sol.isBoomerang(p1) << endl; // 1 (true)
    cout << sol.isBoomerang(p2) << endl; // 0 (false)

    return 0;
}