#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main() {
    queue<string> laptops;
    laptops.push("Dell");
    laptops.push("HP");
    laptops.push("Lenovo");
    laptops.push("Acer");

    queue<string> temp = laptops;

    for(int i = 0; i < laptops.size(); i++) {
        cout << temp.front() << endl;
        temp.pop();
    }

    cout<<laptops.front()<<endl;
    cout<<laptops.size()<<endl;

    return 0;
}