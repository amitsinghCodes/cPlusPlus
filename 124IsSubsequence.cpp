#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool result = false; int start = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[start]){
                result = true;
                start++;
            }
        }
        if(start == s.size()) return true;
    return false;
    }
};

int main(){
    Solution obj;
    cout<<boolalpha;
    cout<<obj.isSubsequence("abc", "ahbgdc");
}