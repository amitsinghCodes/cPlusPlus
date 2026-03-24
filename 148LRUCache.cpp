#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        removeNode(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            insertFront(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            insertFront(newNode);
            mp[key] = newNode;
        }
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);

    obj->put(1, 1);
    obj->put(2, 2);

    cout << obj->get(1) << endl; // 1

    obj->put(3, 3); // removes key 2

    cout << obj->get(2) << endl; // -1

    obj->put(4, 4); // removes key 1

    cout << obj->get(1) << endl; // -1
    cout << obj->get(3) << endl; // 3
    cout << obj->get(4) << endl; // 4

    return 0;
}