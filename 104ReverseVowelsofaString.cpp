#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isvowels(char c){
        bool r = false;
        if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i'|| tolower(c) == 'o'|| tolower(c) == 'u')
        return true;
        return false;
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(left < right && !isvowels(s[left])){left++;}
            while(left < right && !isvowels(s[right])){right--;}
            if(left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            
        }
        return s;
    }
};

int main(){
    Solution obj;
    string result = obj.reverseVowels("IceCreAm");
    cout<<result;
    return 0;
}