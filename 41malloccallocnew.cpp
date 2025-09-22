#include <cstdlib> // For malloc, free

int* arr_malloc;
int num_elements = 5;

// Allocate memory for 5 integers (5 * sizeof(int) bytes)
arr_malloc = (int*)malloc(num_elements * sizeof(int));

if (arr_malloc == NULL) {
    // Handle allocation failure
    // For example, print an error and exit
}

// Use the allocated memory
for (int i = 0; i < num_elements; ++i) {
    arr_malloc[i] = i * 10; // Values are initially uninitialized
}

// Don't forget to free the memory when done
free(arr_malloc);
arr_malloc = NULL; // Good practice to nullify after freeing



int* arr_calloc;
int num_elements = 5;

// Allocate memory for 5 integers and initialize all to 0
arr_calloc = (int*)calloc(num_elements, sizeof(int));

if (arr_calloc == NULL) {
    // Handle allocation failure
}

// Use the allocated memory (already initialized to 0)
for (int i = 0; i < num_elements; ++i) {
    std::cout << arr_calloc[i] << " "; // Will print "0 0 0 0 0"
}
std::cout << std::endl;

// Don't forget to free the memory when done
free(arr_calloc);
arr_calloc = NULL;


#include <iostream> // For std::cout, std::bad_alloc

class MyClass {
public:
    int value;
    MyClass() : value(0) { // Default constructor
        std::cout << "MyClass default constructor called." << std::endl;
    }
    MyClass(int v) : value(v) {
        std::cout << "MyClass constructor with value " << v << " called." << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor called (value: " << value << ")." << std::endl;
    }
};

int main() {
    // Allocate a single object
    MyClass* obj1 = nullptr;
    try {
        obj1 = new MyClass(); // Calls default constructor
        std::cout << "obj1->value: " << obj1->value << std::endl; // 0
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
    delete obj1; // Calls destructor

    std::cout << "---" << std::endl;

    // Allocate an object with a specific value
    MyClass* obj2 = new MyClass(42); // Calls constructor with argument
    std::cout << "obj2->value: " << obj2->value << std::endl; // 42
    delete obj2;

    std::cout << "---" << std::endl;

    // Allocate an array of objects
    MyClass* arr_new = nullptr;
    try {
        arr_new = new MyClass[3]; // Calls default constructor for each element
        std::cout << "arr_new[0].value: " << arr_new[0].value << std::endl; // 0
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
    delete[] arr_new; // Calls destructor for each element
}