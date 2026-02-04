#include<iostream>
#include<vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> sum;

        for(auto &it : items1) {sum[it[0]] += it[1];}
        for(auto &it : items2) {sum[it[0]] += it[1];}

        vector<vector<int>> result;
        for(auto &p : sum){
            result.push_back({p.first, p.second});
        }
        return result;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> items1 = {{1,1}, {4,5}, {3,8}};
    vector<vector<int>> items2 = {{3,1}, {1,5}};

    vector<vector<int>> result = obj.mergeSimilarItems(items1, items2);

    cout << "Merged Items:\n";
    for (auto &row : result) {
        cout << "[" << row[0] << ", " << row[1] << "]\n";
    }

    return 0;
}