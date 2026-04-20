#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }
        
        unordered_set<int> occurrences;
        for (auto& [val, freq] : count) {
            if (occurrences.count(freq)) {
                return false;
            }
            occurrences.insert(freq);
        }
        return true; 
    }
};

int main(){
    Solution obj;
    cout<<boolalpha;
    vector<int> arr = {1,1,2,2,1,3};
    cout<<obj.uniqueOccurrences(arr);
    return 0;
}