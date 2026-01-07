#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        int i =0, j =0;

        while(i < haystack.size()){
            if(needle[j] == haystack[i]){
                i++; j++;
                if(j == needle.size()){
                    return i - j;
                }
            }
            else{
            i = i - j + 1;
            j = 0;
            }
        }
        return index -1;
    }
};

int main(){
    Solution obj;
    int x = obj.strStr("ramjamdamm", "jam");
    cout<< x;
    return 0;
    
}