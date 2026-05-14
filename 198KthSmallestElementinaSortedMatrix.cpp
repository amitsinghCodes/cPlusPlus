#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();

        int row = n - 1;
        int col = 0;

        int count = 0;

        while (row >= 0 && col < n) {

            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            }
            else {
                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {

            int mid = low + (high - low) / 2;

            int count = countLessEqual(matrix, mid);

            if (count < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    Solution sol;

    int ans = sol.kthSmallest(matrix, k);

    cout << "Kth Smallest Element = " << ans << endl;

    return 0;
}