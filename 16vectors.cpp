#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    vector<int> numb;
    numb = {1, 2, 3, 4, 5};
    numb.push_back(8);
    for(int i = 0;i<numb.size();i++){
        cout<<i << " "<< numb[i]<<endl;
    }
    cout<<numb.front()<<endl; //1
    cout<<numb.back()<<endl;
    cout<<numb.at(2)<<endl;
    cout<<numb.empty()<<endl; 

    numb.pop_back();
    for(int i = 0;i<numb.size();i++){
        cout<<numb[i]<<endl;
    }

    cout<<numb.size()<<endl;
    cout<<numb.capacity()<<endl;
    
    return 0;
}