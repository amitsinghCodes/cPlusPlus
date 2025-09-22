#include<iostream>
#include<string>
#include<deque>

using namespace  std;

int main(){
    deque<int> numb = {1, 2, 3, 4, 5};
    numb.push_back(8);
    numb.push_front(0);
    for(int i = 0; i < numb.size(); i++){
        cout<<numb[i]<<endl;
    }

    numb.pop_back();
    cout<< numb.at(5);

    return 0;
}