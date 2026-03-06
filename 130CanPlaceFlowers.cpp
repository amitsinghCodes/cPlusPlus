#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                int left = (i == 0) ? 0 : flowerbed[i - 1];
                int right = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];

                if (left == 0 && right == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }

            if (count >= n) return true;
        }

        return count >= n;
    }
};

int main() {
    Solution obj;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    if (obj.canPlaceFlowers(flowerbed, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}