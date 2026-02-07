#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26,0);
        for(auto c : s){
            freq[c - 'a']--;
        }
        for(auto c : t){
            freq[c - 'a']++;
        }

        for(int i =0; i < 26; i++){
            if(freq[i] != 0)
            return char(i + 'a');
        }
        return 0;
    }
};

int main(){
    Solution obj;
    string s = "abcde";
    string t = "abcd";
    char c = obj.findTheDifference(s,t);
    cout<<c;
    return 0;
}