#include<iostream>
#include<stack>
using namespace std;
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){

    MyQueue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(5);
    obj.push(6);
    obj.push(9);

    cout << "peek: " << obj.peek() << "\n";   // 1
    cout << "pop: "  << obj.pop()  << "\n";   // 1
    cout << "empty: " << obj.empty() << "\n"; // 0 (false)

    // Print remaining elements (this will EMPTY the queue)
    cout << "Queue remaining: ";
    while (!obj.empty()) {
        cout << obj.pop() << " ";
    }
    cout << "\n";

   return 0;
}