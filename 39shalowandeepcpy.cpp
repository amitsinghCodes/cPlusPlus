#include <iostream>
#include <cstring> // For strlen and strcpy

class MyData {
public:
    char* name;

    // Constructor
    MyData(const char* n) {
        if (n == nullptr) { // Handle nullptr input
            name = nullptr;
        } else {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        std::cout << "MyData constructor called for: " << (n ? n : "nullptr") << std::endl;
    }

    // Deep Copy Constructor
    // Called when a new object is created from an existing object (e.g., MyData newObj = oldObj;)
    MyData(const MyData& other) {
        if (other.name == nullptr) {
            name = nullptr;
        } else {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        std::cout << "MyData deep copy constructor called for: " << (name ? name : "nullptr") << std::endl;
    }

    // Deep Copy Assignment Operator
    // Called when an existing object is assigned the value of another existing object (e.g., obj1 = obj2;)
    MyData& operator=(const MyData& other) {
        // 1. Handle self-assignment (e.g., obj = obj;)
        if (this == &other) {
            std::cout << "Self-assignment detected." << std::endl;
            return *this;
        }

        // 2. Deallocate existing resources to prevent memory leaks
        delete[] name;

        // 3. Allocate new memory and copy data
        if (other.name == nullptr) {
            name = nullptr;
        } else {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        std::cout << "MyData deep copy assignment operator called for: " << (name ? name : "nullptr") << std::endl;
        return *this; // Return a reference to the current object
    }

    // Destructor
    ~MyData() {
        std::cout << "MyData destructor called for: " << (name ? name : "nullptr") << std::endl;
        delete[] name; // Safely deallocate
        name = nullptr; // Prevent dangling pointer after deallocation
    }

    void print() const {
        if (name) {
            std::cout << "Name: " << name << std::endl;
        } else {
            std::cout << "Name: (null)" << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Creating original object ---" << std::endl;
    MyData original("Alice");
    original.print(); // Output: Name: Alice

    std::cout << "\n--- Creating a deep copy using copy constructor ---" << std::endl;
    MyData copied = original; // Calls deep copy constructor
    copied.print(); // Output: Name: Alice

    std::cout << "\n--- Modifying original (should not affect copied) ---" << std::endl;
    // We're modifying the 'name' pointer within 'original'.
    // In a real scenario, you'd have methods to change data, not directly access public members.
    // For demonstration, let's illustrate by showing independence.
    // To properly modify 'name', you'd typically need a setter:
    // void setName(const char* newName) { delete[] name; name = new char[strlen(newName)+1]; strcpy(name, newName); }

    // Let's create a new object to assign to original to show it's independent
    MyData temp("Bob");
    original = temp; // Calls deep copy assignment operator
    std::cout << "Original after assignment from temp: ";
    original.print(); // Output: Name: Bob
    std::cout << "Copied (should still be Alice): ";
    copied.print(); // Output: Name: Alice (remains unaffected)

    std::cout << "\n--- Creating another object for assignment ---" << std::endl;
    MyData another("Charlie");
    another.print(); // Output: Name: Charlie

    std::cout << "\n--- Assigning copied to another ---" << std::endl;
    another = copied; // Calls deep copy assignment operator
    another.print(); // Output: Name: Alice

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}