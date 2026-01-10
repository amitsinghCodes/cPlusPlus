#include<iostream>

using namespace std;
 
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void printList(ListNode* head){
    while(head){
        cout<<head->val;
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while(prev->next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }
        return dummy.next;
    }

};

int main(){
    int n = 5;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i = 0; i< n; i++){
        int x;
        cin>>x;
        ListNode* newNode = new ListNode(x);

        if(!head){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }  

    printList(head);
    
    Solution obj;
    head = obj.swapPairs(head);

    printList(head);
    return 0;
}