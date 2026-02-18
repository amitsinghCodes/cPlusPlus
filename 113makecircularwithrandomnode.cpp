#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* makeCircular(Node* pnode){
    if(!pnode) return nullptr;
    Node* tail = pnode;
    Node* head = pnode;

    while(head->prev){
        head = head->prev;
    }

    while(tail->next){
        tail = tail->next;
    }
    head->prev = tail;
    tail->next = head;
    
    return head;
}

void traverseForward(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void traverseCircular(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    /*
        Create DLL:
        1 <-> 2 <-> 3 <-> 4
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    cout << "Normal DLL: ";
    traverseForward(n1);

    // Random node given (say n3)
    Node* head = makeCircular(n3);

    cout << "Circular DLL: ";
    traverseCircular(head);

    return 0;
}
