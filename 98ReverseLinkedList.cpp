#include<iostream>

using namespace std;
 /// Definition for singly-linked list.
 struct ListNode {
     int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        while(current != nullptr){
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
};

int main(){
    Solution obj;
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(3);
    ListNode* a4 = new ListNode(4);
    ListNode* a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    ListNode *temp = obj.reverseList(a1);
    ListNode* curr = temp;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}