#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int total = (i + 1) * (n - i);
            int oddCount = (total + 1) / 2;
            sum += arr[i] * oddCount;
        }

        return sum;
    }
};

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};

    Solution sol;
    cout << sol.sumOddLengthSubarrays(arr) << endl;

    return 0;
}