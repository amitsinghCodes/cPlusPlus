#include <iostream>
#include <string>

using namespace std;

class Human {
public:
    void setAge(int value) {
        if (value < 18) {
            cout << "You are in for Kidz Zone." << endl;
        } else {
            throw "Oops! Not allowed.";  // Exception is thrown here
        }
    }
};

int main() {
    Human obj;
    try {
        obj.setAge(20);  // Exception will be thrown
    }
    catch (const char* msg) {
        cout << msg << endl;  // Exception is caught here
    }

    return 0;
}
