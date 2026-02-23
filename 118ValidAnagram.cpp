#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int>count;
        for(auto c : s){
            count[c]++;
        }
        for(auto c : t){
            count[c]--;
            if(count[c] < 0) return false;
        }
        return true;
    }
};

int main(){
    Solution obj;
    cout<<boolalpha;
    cout<<obj.isAnagram("anagram","nagaram");
    return 0;
}

/*
 bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int x : freq)
            if(x != 0) return false;

        return true;
    }
*/