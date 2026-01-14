#include<iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        string a = strs[0];
        for(int i = 0; i < strs.size(); i++){
            int j = 0;
            while(j < a.size() && j < strs[i].size() && a[j] == strs[i][j]){
                j++;
            }
            a = a.substr(0,j);
            if(a == "")
            return "";
        }
        return a;
    }
};

int main(){
    Solution obj;
    string abc = obj.longestCommonPrefix(vector<string>{"cloud","club","click","close"});
    cout<<abc;
    return 0;
}