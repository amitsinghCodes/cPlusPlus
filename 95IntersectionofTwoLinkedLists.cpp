#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return nullptr;
        }

        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB){
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};

int main(){
    ListNode* c1 = new ListNode(5);
    ListNode* c2 = new ListNode(6);
    ListNode* c3 = new ListNode(9);
    c1->next = c2;
    c2->next = c3;

    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(3);
    a1->next = a2;
    a2->next = c1;

    ListNode* b1 = new ListNode(9);
    ListNode* b2 = new ListNode(10);
    b1->next = b2;
    b2->next = c1;

    Solution obj;
    ListNode* ans = obj.getIntersectionNode(a1,b1);
    if(ans){
        cout<< ans->val<<endl;
        cout <<"address" << ans;
    }
    return 0;
}