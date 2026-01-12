#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupanagram(vector<string> strs){
    unordered_map<string, vector<string>>mp;
    for(string s : strs){
        string key = s;
        sort( key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> ans;
    
    for(auto p : mp){
        ans.push_back(move(p.second));
    }
    return ans;
}

int main() {
    vector<string> strs = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> x = groupanagram(strs);
    for(auto p : x){
        for(auto m : p){
        cout<<m<<" ";
    }
    cout<<endl;
    }
    return 0;
}