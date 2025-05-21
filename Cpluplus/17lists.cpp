#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(){
    list<string>cars = {"BMW", "3", "Mercedes", "Toyota"};
    cars.push_back("Ford");
    cars.push_front("Chevrolet");
    cars.insert(cars.begin(), "Jeep");
    for(string i : cars){
        cout<<i<<endl;
    }

    cout<<cars.front()<<endl; //Jeep
    cout<<cars.back()<<endl; //Ford

    cars.pop_back();
    cars.pop_front();

    for(string i : cars){
        cout<<i<<endl;
    }
    return 0;
}