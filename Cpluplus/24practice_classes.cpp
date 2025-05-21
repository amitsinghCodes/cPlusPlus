#include<iostream>
#include<string>
#include<vector>

using namespace std;

class foo{
    public: foo() : x(0), y(0) {}         // default constructor
    foo(int c, string* p) : counter_(c), str_(p){} // parameterized constructor
    foo(int x, int y) : x(x), y(y) {cout<<"x: "<<x<<" y: "<<y<<endl;}   // parameterized constructor

    private:
    int counter_;
    string* str_;
    int x,y;
};

int main()
{
foo f1; // default constructor called
foo f2(10, 20); // parameterized constructor called

string s = "bar";
foo(2, &s); // parameterized constructor called

foo f3 = f1; // copy constructor called
foo f4(f2); // copy constructor called

return 0;
}