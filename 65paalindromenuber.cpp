#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int ar[100];
        int length = 0;

        while (x) {
            ar[length++] = x % 10;
            x /= 10;
        }

        int i = 0, j = length - 1;
        while (i < j) {
            if (ar[i] != ar[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution obj;
    cout << obj.isPalindrome(-343); 
    return 0;
}
