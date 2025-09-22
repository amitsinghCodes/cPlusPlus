#include <iostream>

// Function to demonstrate pass-by-pointer (allows modifying the original variable)
void incrementWithPointer(int* ptr) {
    // Check for null pointer to prevent dereferencing issues
    if (ptr != nullptr) { //
        (*ptr)++; // Dereference the pointer and increment the value it points to
        std::cout << "Inside incrementWithPointer: Value after increment: " << *ptr << std::endl; //
    } else {
        std::cout << "Error: Null pointer passed to incrementWithPointer." << std::endl; //
    }
}

// Function to demonstrate pass-by-reference (modifies the original variable directly)
void incrementWithReference(int& ref) {
    ref++; // Access and modify the original variable directly (no explicit dereferencing needed)
    std::cout << "Inside incrementWithReference: Value after increment: " << ref << std::endl; //
}

int main() {
    // 1. Definition and Initialization
    int value = 10; // Original integer variable

    // Pointer: Declared with '*' and stores the address of 'value'
    int* ptr = &value; // Initializes 'ptr' with the address of 'value'

    // Reference: Declared with '&' and acts as an alias for 'value'
    int& ref = value; // Initializes 'ref' as an alias to 'value' (must be initialized at declaration)

    std::cout << "Original value: " << value << std::endl; //
    std::cout << "Address of value: " << &value << std::endl; //
    std::cout << "Value of ptr (address of value): " << ptr << std::endl; //
    std::cout << "Value at *ptr (dereferencing ptr): " << *ptr << std::endl; //
    std::cout << "Value of ref (alias for value): " << ref << std::endl; //
    std::cout << "Address of ref (same as address of value): " << &ref << std::endl << std::endl; //

    // 2. Dereferencing
    // Pointers require explicit dereferencing to access the value they point to
    *ptr = 20; // Modifies the value of 'value' through 'ptr'
    std::cout << "Value after modifying through pointer: " << value << std::endl; //

    // References are used directly, no dereferencing needed
    ref = 30; // Modifies the value of 'value' through 'ref'
    std::cout << "Value after modifying through reference: " << value << std::endl << std::endl; //

    // 3. Reassignment
    int anotherValue = 40; // Another integer variable

    // Pointers can be reassigned to point to different variables
    ptr = &anotherValue; // 'ptr' now points to 'anotherValue'
    std::cout << "Ptr reassigned to point to anotherValue: " << *ptr << std::endl; //

    // References cannot be reassigned (will result in a compile-time error if attempted)
    // ref = anotherValue; // This would assign the value of anotherValue to value, not rebind 'ref'
    std::cout << "References cannot be reassigned after initialization." << std::endl << std::endl; //

    // 4. Nullability
    int* nullPtr = nullptr; // Pointers can be assigned nullptr
    std::cout << "Null pointer: " << nullPtr << std::endl; //

    // References cannot be null
    // int& nullRef = nullptr; // This would be a compile-time error
    std::cout << "References cannot be null." << std::endl << std::endl; //

    // 5. Arithmetic Operations
    int arr[] = {100, 200, 300}; // An array
    int* arrayPtr = arr; // Pointer to the first element of the array

    // Pointers support pointer arithmetic
    std::cout << "Pointer arithmetic (arrayPtr + 1): " << *(arrayPtr + 1) << std::endl; // Moves to the next element
    arrayPtr++; // Increment the pointer to point to the next element
    std::cout << "ArrayPtr after increment: " << *arrayPtr << std::endl; //

    // References do not support arithmetic operations (would be a compile-time error)
    // ref++; // This would increment the value of 'value', not the 'reference' itself
    std::cout << "References do not support arithmetic operations directly." << std::endl << std::endl; //

    // 6. Dynamic Memory Allocation
    // Pointers are used for dynamic memory allocation
    int* dynamicInt = new int; // Dynamically allocates an integer on the heap
    *dynamicInt = 50; // Assigns a value to the dynamically allocated integer
    std::cout << "Dynamically allocated integer: " << *dynamicInt << std::endl; //
    delete dynamicInt; // Frees the dynamically allocated memory
    dynamicInt = nullptr; // Avoids dangling pointer issues by setting it to nullptr

    // References cannot be used for direct dynamic memory allocation
    std::cout << "References cannot be used for direct dynamic memory allocation." << std::endl << std::endl; //

    // 7. Function Parameters
    int a = 100; // Integer for pointer demonstration
    int b = 200; // Integer for reference demonstration

    std::cout << "Before function calls: a = " << a << ", b = " << b << std::endl; //

    incrementWithPointer(&a); // Pass the address of 'a' to the function
    incrementWithReference(b); // Pass 'b' by reference to the function

    std::cout << "After function calls: a = " << a << ", b = " << b << std::endl << std::endl; //

    // 8. Multiple levels of indirection
    int value2 = 1000;
    int* ptr1 = &value2;
    int** ptr2 = &ptr1; // Pointer to a pointer

    std::cout << "Value of value2: " << value2 << std::endl; //
    std::cout << "Value through single indirection (*ptr1): " << *ptr1 << std::endl; //
    std::cout << "Value through double indirection (**ptr2): " << **ptr2 << std::endl; //

    // References only have one level of indirection
    std::cout << "References only have one level of indirection." << std::endl; //

    return 0;
}
