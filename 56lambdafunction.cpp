/*
A lambda function in C++ is an anonymous, inline function object, 
introduced in C++11. It allows you to define a small, 
temporary function directly at the point where it is used,
without the need for a separate function declaration or definition.
*/
#include <iostream>
using namespace std;

//basic
auto num = [](){cout<< "69"<<endl;};

//with parameters
auto add = [](int a, int b){return a+b;};

//captures
int x = 10, y = 15;
auto by_val = [x_copy = x](){cout<< x_copy <<"\n";};
auto by_ref = [&y_copy = y](){y_copy += 5; cout<< y_copy <<"\n";};

int main(){
    num();
    cout<<add(9,10)<<endl;
    by_val();
    by_ref();
    return 0;
}

