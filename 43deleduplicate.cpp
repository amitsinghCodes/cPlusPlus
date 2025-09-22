#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> numbers = {1,1,3,3,5,6,7,7,7,9};
    //for(int i = 0 ;i < 10; i++){
      //  cin>>numbers[i];
    //}

    for(int i = 0;i < numbers.size() - 1;){
        if(numbers[i] == numbers[i + 1]){
            numbers.erase(numbers.begin() + i + 1);
        }
        else ++i;
    }

    for(int i = 0 ;i < numbers.size() ; i++){
        cout<<numbers[i];
    }


    return 0;
}