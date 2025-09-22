#include <iostream>

using namespace std;

class Sclass {
    public:

    int *ptr; // Pointer to an integer

    Sclass(int i){ // default parameterized constructor
        // This constructor initializes the pointer to a new integer
        cout << "Default constructor called" << endl;
        ptr = new int(i); 
    }

    Sclass(const Sclass &s) { // Copy constructor
        cout << "Copy constructor called" << endl;
        ptr = new int(*s.ptr); // Deep copy of the integer pointed to by s.ptr 
    }

    ~Sclass() {
        cout << "Destructor called" << endl;
        delete ptr; // Free the allocated memory
    }
};

int main() {
    Sclass s1(6); // Default constructor is called
    cout<< "Value of ptr: " << *(s1.ptr) << endl; // Output the value pointed to by ptr
    cout<< "Address of ptr: " << s1.ptr << endl; // Output the address of ptr
    Sclass s2(s1); // Copy constructor is called
    cout<< "Value of ptr: " << *(s2.ptr) << endl; // Output the value pointed to by ptr
    cout<< "Address of ptr: " << s2.ptr << endl; // Output the address of ptr
}