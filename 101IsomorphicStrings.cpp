#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size()) return false;
        int mapST[256];
        int mapTS[256];

        for(int i = 0; i < 256; i++){
            mapST[i] = -1;
            mapTS[i] = -1;
            }    

            for (int i = 0; i < (int)s.size(); i++) {
            unsigned char a = (unsigned char)s[i];
            unsigned char b = (unsigned char)t[i];

            // if both not mapped yet → create mapping
            if (mapST[a] == -1 && mapTS[b] == -1) {
                mapST[a] = b;
                mapTS[b] = a;
            } 
            else {
                // mapping exists, must match
                if (mapST[a] != b || mapTS[b] != a) {
                    return false;
                }
            }
        }

            return true;       
        }
};

int main(){
    Solution obj;
    cout<<boolalpha;
    bool result = obj.isIsomorphic("egg","add");
    cout<<result;
    return 0;
}