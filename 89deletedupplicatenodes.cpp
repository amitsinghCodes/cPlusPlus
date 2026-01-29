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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* previous= &dummy;
        ListNode* current = head;
        while(current && current->next){
            previous->next = current;
            if(current->val == current->next->val){
                int value = current->val;
                while(current && value == current->val){
                    current = current->next;
                }
                 previous->next = current;
            }
            else{
            previous = current;
            current = current->next;
            }
        }
        return dummy.next;
    }
};

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

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    vector<int> input = {1,2,3,3,4,4,5};

    ListNode* head = buildList(input);

    cout << "Before: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After : ";
    printList(head);

    return 0;
}