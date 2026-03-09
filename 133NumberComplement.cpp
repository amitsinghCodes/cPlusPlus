#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long mask = 1;

        while(mask <= num){
            mask <<= 1;
        }

        mask = mask - 1;

        return mask ^ num;
    }
};

int main() {
    Solution obj;

    int num;
    cout << "Enter number: ";
    cin >> num;

    int result = obj.findComplement(num);

    cout << "Complement = " << result << endl;

    return 0;
}