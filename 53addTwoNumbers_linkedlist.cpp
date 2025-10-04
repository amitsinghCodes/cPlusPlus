
/*
2) Add Two Numbers (Linked List)
  Description: Add two numbers represented by reversed linked lists.
  Signature:   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
  Example 1:   l1=[2,4,3], l2=[5,6,4] -> output=[7,0,8]
  Example 2:   l1=[0], l2=[0] -> output=[0]

*/
#include<iostream>
#include<list>

using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    
    ListNode(int x): value(x), next(nullptr){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr || carry){
        int sum = carry;
        if(l1) { sum += l1-> value; l1 = l1->next;}
        if(l2) { sum += l2-> value; l2 = l2->next;}
        
        carry = sum/10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return dummy.next;
}

ListNode* buildList(int* ptr , int size){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i = 0; i < size; i++){
        ListNode* NewNode = new ListNode(ptr[i]);
        if(!head) {head = NewNode; tail = NewNode;}
        else {tail->next = NewNode; tail = NewNode;}
    }
    return head;
}

int main(){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int ar[] = {2,9,5}, br[] = {9,1,1};
    int size_ar = sizeof(ar)/sizeof(ar[0]);
    int size_br = sizeof(br)/sizeof(ar[0]);
    ListNode* l1 = buildList(ar, size_ar);
    ListNode* l2 = buildList(br, size_br);
    ListNode* sum = addTwoNumbers(l1, l2);
    while(sum != nullptr){
        cout<<sum->value<<" ";
        sum = sum->next;
    }
    return 0;
}