#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> freq(26, 0);

        // Count characters in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Try to construct ransomNote
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0)
                return false;
            freq[c - 'a']--;
        }

        return true;
    }
};

int main() {

    string ransomNote = "aa";
    string magazine = "aab";

    Solution obj;

    if (obj.canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}