#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<string, int> ages = {
        {"John", 23},
        {"Doe", 24},
        {"Jane", 25}
    };

    ages["Smith"] = 26;
    ages.insert({"Joe", 24});

    for(pair<string, int> i : ages){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    ages.erase("Doe");
    cout<<ages.size()<<endl;
    cout<<ages["Smith"]<<endl;

    for(auto  i : ages){
        cout<<i.first<<" : "<<i.second<<endl;
    }


    return 0;
}