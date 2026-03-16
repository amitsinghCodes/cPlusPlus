#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {

    vector<int> arr = {7,1,14,11};

    Solution obj;

    if(obj.checkIfExist(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}