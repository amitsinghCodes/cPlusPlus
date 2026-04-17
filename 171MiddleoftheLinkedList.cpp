#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps
        }

        return slow;
    }
};

int main() {
    /*
        Creating linked list:
        1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    // Print from middle to end
    cout << "Middle to end: ";
    while (mid) {
        cout << mid->val << " ";
        mid = mid->next;
    }

    return 0;
}