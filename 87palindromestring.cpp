#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int i = 0, j = size - 1;
        while(i<j){
            if(!isalnum(s[i])){i++; continue;}
            if(!isalnum(s[j])){j--; continue;}
            if(tolower(s[i]) != tolower(s[j]))
            return false;
            i++; j--;
        }
        return true;
    }
};

int main(){
    Solution obj;
    bool ans = obj.isPalindrome("A man, a plan, a canal: Panama");
    cout<<ans;
    return 0;
}