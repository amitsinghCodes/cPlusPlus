/* Two Sum
  Description: Find indices of two numbers that add up to target.
  Signature:   vector<int> twoSum(const vector<int>& nums, int target);
  Example 1:   nums=[2,7,11,15], target=9 -> output=[0,1]
  Example 2:   nums=[3,2,4], target=6 -> output=[1,2]
  */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> indices(int* ptr, int size, int target){
    vector<int> index;
    for(int i = 0; i<size ; i++){
        int sum = 0;
        for(int j = i + 1; j < size; j++){
            sum = ptr[i] + ptr[j];
            if(sum == target){
                index.push_back(i);
                index.push_back(j);
                return index;
            }
        }
    }
    return index;
}

int main() {
int num[] = {2,7,11,15};
int target = 9;
int size = sizeof(num)/sizeof(num[0]);
vector<int> ind = indices(num, size, target);
vector<int>::iterator it = ind.begin();
cout<<"indices are : ";
for(; it < ind.end(); it++){
    cout<<*it<< " ";
}
    return 0;
}

/*
O(n) hash-map solution

#include <unordered_map>
using namespace std;

bool twosum(int* ptr, int size, int target, int& iout , int& jout){
    unordered_map<int, int>  seen; // value -> index
    for(int i = 0; i < size; ++i){
        int need = target - ptr[i];
        unordered_map<int,int>::const_iterator it = seen.find(need);
        if(it != seen.end()){
            iout = it->second;
            jout = i;
            return true;
        }
            // store AFTER checking so we don't use the same element twice
        seen[ptr[i]] = i;
    }
    return false;
}

int main() {
int num[] = {2,7,11,15};
int target = 18;
int size = sizeof(num)/sizeof(num[0]), i = -1, j = -1;
if(twosum(num, size, target, i , j)){
    cout<<"[ "<<i<< " "<<j<<" ]";
}
else
cout<<"no pair";

    return 0;
}
*/