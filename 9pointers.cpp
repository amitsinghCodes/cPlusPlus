#include<iostream>
#include<string>
#include<vector>

using namespace std;
// pointers are variables that stor address of other variables,, so that the valuess are easy to modify.
int main(){
    string  food = "Pizza";
    string*  ptr = &food;  //ptr has the address of food
    
    cout << "Value of food: " << *ptr << "\n";
    cout << "Address of food: " << ptr << "\n";

    cout << "Food: " << food << "\n";
    cout  << "Address of food: " << &food << "\n";
    cout << "Size of food: " << sizeof(food) << "\n";

    *ptr = "Burger";  //changing the value of food using pointer
    cout << "Value of food: " << *ptr << "\n";
}
