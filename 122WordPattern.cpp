#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // split s into words
        vector<string> words;
        string w;
        stringstream ss(s);
        while (ss >> w) words.push_back(w);

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;

        for (int i = 0; i < (int)pattern.size(); i++) {
            char c = pattern[i];
            const string &word = words[i];

            // if c already mapped, it must match current word
            if (c2w.count(c) && c2w[c] != word) return false;

            // if word already mapped, it must match current char
            if (w2c.count(word) && w2c[word] != c) return false;

            // set/confirm mapping
            c2w[c] = word;
            w2c[word] = c;
        }
        return true;
    }
};

int main(){
    Solution obj;
    cout<<boolalpha;
    cout<<obj.wordPattern("abba", "dog cat cat dog");
    return 0;
}