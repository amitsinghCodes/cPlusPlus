//delete node n from end;
//Definition for singly-linked list.

#include<iostream>
using namespace std;
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        for(int j = 0; j < n; j++){
            fast = fast->next;
        }
        
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return dummy.next;
    }
};


int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(4); 
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(7);
    Solution oobj;
    head = oobj.removeNthFromEnd(head, 2);
    while(head!= nullptr){
        cout<<head->val;
        head = head->next;
    }
    return 0;
}