#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }

                char top = st.top();
                st.pop();
                if((c == ')' && '(' != top) ||
                  (c == ']' && '[' != top) ||
                  (c == '}' && '{' != top))
                  return false;
            }
        }
        return st.empty();
    }
};

int main(){
    Solution obj;
    cout << obj.isValid("([]){}");
    return 0;
}