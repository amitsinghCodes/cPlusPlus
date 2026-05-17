#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {

        int spaces = 0;
        vector<string> words;

        string word = "";

        // count spaces + extract words
        for(char c : text){

            if(c == ' '){
                spaces++;

                if(word != ""){
                    words.push_back(word);
                    word = "";
                }
            }
            else{
                word += c;
            }
        }

        // last word
        if(word != ""){
            words.push_back(word);
        }

        // only one word case
        if(words.size() == 1){
            return words[0] + string(spaces, ' ');
        }

        int gap = spaces / (words.size() - 1);
        int extra = spaces % (words.size() - 1);

        string ans = "";

        for(int i = 0; i < words.size(); i++){

            ans += words[i];

            if(i != words.size() - 1){
                ans += string(gap, ' ');
            }
        }

        ans += string(extra, ' ');

        return ans;
    }
};

int main() {

    Solution s;

    string text = "  this   is  a sentence ";

    string result = s.reorderSpaces(text);

    cout << "Output:\n";
    cout << "\"" << result << "\"" << endl;

    return 0;
}