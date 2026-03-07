#include<iostream>
#include<vector>

using namespace std;

class MyHashSet {
public:
    vector<bool> present;

    MyHashSet() {
        present.resize(1000001, false);
    }
    
    void add(int key) {
        present[key] = true;
    }
    
    void remove(int key) {
        present[key] = false;
    }
    
    bool contains(int key) {
        return present[key];
    }
};

int main() {
    MyHashSet myHashSet;
    cout<<boolalpha;
    myHashSet.add(1);
    myHashSet.add(2);

    cout << myHashSet.contains(1) << endl; // 1
    cout << myHashSet.contains(3) << endl; // 0

    myHashSet.add(2);
    cout << myHashSet.contains(2) << endl; // 1

    myHashSet.remove(2);
    cout << myHashSet.contains(2) << endl; // 0

    return 0;
}