#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printList(Node* head){
    while(head){
        cout<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void deletepnode(Node* pnode){
    if(!pnode){
        return;
    }
    if(pnode->prev){
        pnode->prev->next = pnode->next;
    }

    if(pnode->next){
        pnode->next->prev = pnode->prev;
    }

    delete pnode;
}

Node* getNode(Node* head, int pos){
    if(!head){
        return nullptr;
    }
    int i = 1;
    while(head && i < pos){
        head = head->next;
        i++;;
    }
    return head;
} 

int main(){
    int n = 5;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i< n; i++){
        int x;
        cin>>x;
        Node* newNode = new Node(x);

        if(!head){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }  
    cout << "Original list: ";
    printList(head);

    int pos = 3;
    Node* pnode = getNode(head, pos);

    if (pnode == head)
        head = head->next;

    deletepnode(pnode);

    printList(head);
                                                                                                                                
    return 0;
}