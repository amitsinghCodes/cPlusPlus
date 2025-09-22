#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    stack<string> animals;
    animals.push("Lion");
    animals.push("Tiger");
    animals.push("Goat");
    animals.push("Sheep");

    stack<string> temp = animals;

    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }

    cout<<animals.size()<<endl;
    cout<<animals.top()<<endl;

    return 0;
}