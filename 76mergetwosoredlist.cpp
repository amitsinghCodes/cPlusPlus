#include <iostream>
using namespace std;
#include <vector>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
      ListNode* buildList(vector<int> vals){}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
            tail->next = list1;
            list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != nullptr) tail->next = list1;
        else tail->next = list2;
        return dummy.next;
    }
};

ListNode* buildList(vector<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}


int main(){
    Solution obj;

    ListNode* list1 = buildList({1,2,4});
    ListNode* list2 = buildList({1,2,3});

    ListNode* newList = obj.mergeTwoLists(list1, list2);
    while(newList){
        cout<<newList->val;
        newList = newList->next;
    }
    return 0;
}