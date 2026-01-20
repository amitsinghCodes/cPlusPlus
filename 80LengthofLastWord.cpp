#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int best = 0; int l = 0;  int n = s.size();
        while(s[n] == ' ') n--;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                l = 0;
            }
            else
            l++;
            if(l > 0)
            best = l;
        }
        return best;
    }
};

int main(){
    Solution obj;
    string str = "   fly me   to   the moon  ";
    int ans = obj.lengthOfLastWord(str);
    cout<<ans;
    return 0;
}