#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : protected Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = tail = nullptr;
    }

    void set(int key, int value) override {
        if (mp.find(key) != mp.end()) {
            // Key exists: Update value & move to head
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            // New key insertion
            Node* newNode = new Node(NULL, head, key, value);
            if (mp.size() >= cp) {
                // Cache is full, remove least recently used (tail) node
                mp.erase(tail->key); // Remove LRU from map
                removeNode(tail);    // Remove LRU from linked list
            }
            insertAtHead(newNode);
            mp[key] = newNode;
        }
    }

    int get(int key) override {
        if (mp.find(key) == mp.end()) {
            return -1; // Cache miss
        }
        Node* node = mp[key];
        moveToHead(node); // Mark as recently used
        return node->value;
    }

private:
    void moveToHead(Node* node) {
        if (node == head) return; // Already at head
        removeNode(node);
        insertAtHead(node);
    }

    void removeNode(Node* node) {
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head;
        node->prev = NULL;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head; // First node in the cache
    }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
