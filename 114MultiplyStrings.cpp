#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size();
        int m = num2.size();

        vector<int>result(m + n, 0);
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum/10;
                }
            }
            string answer;  int k = 0;
            while (k < (int)result.size() && result[k] == 0) k++;
            for(; k < (int)result.size(); k++){
            answer.push_back(result[k] + '0');
        }
        return answer;
    }
};

int main(){
    Solution obj;
    cout<<obj.multiply("234","325");
    return 0;
}