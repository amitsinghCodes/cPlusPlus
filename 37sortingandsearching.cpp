#include <iostream>
using namespace std;

// Sorting (Bubble Sort)
void sorting(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Linear Search
void linearsearching(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

// Binary Search (assumes sorted array)
void binarysearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Element not found.\n";
}

int main() {
    int arr[100], n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nMenu:\n";
    cout << "1. Sorting\n";
    cout << "2. Linear Search\n";
    cout << "3. Binary Search\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            sorting(arr, n);
            break;
        case 2:
            cout << "Enter element to search: ";
            cin >> key;
            linearsearching(arr, n, key);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            sorting(arr, n); // Binary search requires sorted array
            binarysearch(arr, n, key);
            break;
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}
