#include<iostream>
#include<vector>
using namespace std;
 
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smalldummy(0), bigdummy(0);
        ListNode* small = &smalldummy;
        ListNode* big = &bigdummy;
        while(head){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }
            else{
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        big->next = nullptr;
        small->next = bigdummy.next;
        return smalldummy.next;
    }
};

// build linked list from vector
ListNode* buildList(const vector<int>& a) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int x : a) {
        ListNode* node = new ListNode(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    vector<int> input = {1,4,3,2,5,2};
    int x = 3;

    ListNode* head = buildList(input);

    cout << "Before: ";
    printList(head);

    Solution obj;
    head = obj.partition(head, x);

    cout << "After : ";
    printList(head);

    return 0;
}
