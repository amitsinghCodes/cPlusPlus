#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxi = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];

                    double area = abs(x1 * (y2 - y3) +
                                      x2 * (y3 - y1) +
                                      x3 * (y1 - y2)) / 2.0;

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};

int main() {
    vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    
    Solution sol;
    cout << sol.largestTriangleArea(points) << endl;

    return 0;
}