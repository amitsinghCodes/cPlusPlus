#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(){
    set<int> numb = {1, 2, 9, 3, 4, 5};
    set<string> names = {"John", "Doe", "Jane", "Doe"};

    numb.insert(8);

    for(int i : numb){
        cout<<i<<endl;
    }
    for(string i : names){
        cout<<i<<endl;
    }

    numb.erase(3);
    cout<<numb.size()<<endl;
    cout<<names.size()<<endl;

    return  0;
}