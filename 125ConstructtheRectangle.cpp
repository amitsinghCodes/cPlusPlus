#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>constructRectangle(int area) {
        int start = area;
        int end = 1;
        for(int w = 1; w * w <= area; w++ ){
            if(area % w == 0){
                int l = area /w;
                start = l;
                end = w;
            }
        }
        return {start,end};
    }
};

int main(){
    Solution obj;
    vector<int>result = obj.constructRectangle(40);
    for(auto x : result){
        cout<<x;
    }
    return 0;
}