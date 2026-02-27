//Rule:

//Any character with frequency f can contribute 2 * (f/2) (i.e., the largest even part).

//If at least one character has an odd leftover, you can place exactly one odd character in the center (+1).

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128,0);
        for(auto c : s){
            freq[c]++;
        }

        bool hasodd = false;
        int length = 0;

        for(int i : freq){
            length += (i/2) * 2;
            if(i % 2 == 1){
                hasodd = true;
            }
        }
        if(hasodd) length++;
        return length;
    }
};

int main(){
    Solution obj;
    cout<<obj.longestPalindrome("abccccdd");
    return 0;
}

/*
class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        int len = 0;
        bool flag = false;
        for (auto m : mp) {
            if (m.second % 2 == 0) {
                len += m.second;
            }
            else{
                len+= m.second - 1;
                flag = true;
            }
        }
        if(flag) len++;

        return len;
    }
};
*/