#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
            return true;
        }
        }
        return false;
    }
};

int main() {

    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n4->next = n2;

    Solution obj;
    bool result = obj.hasCycle(n1);

    if(result)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
