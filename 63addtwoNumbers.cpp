#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x = 0) : val(x), next(nullptr) {}

    // STATIC: add two numbers
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); 
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;

            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return dummy.next;
    }

    // STATIC: build linked list
    static ListNode* buildList(int* ptr, int size) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int i = 0; i < size; i++) {
            ListNode* newNode = new ListNode(ptr[i]);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
};

int main() {
    int ar[] = {2, 9, 5};
    int br[] = {9, 1, 1};

    int size_ar = sizeof(ar) / sizeof(ar[0]);
    int size_br = sizeof(br) / sizeof(br[0]);

    ListNode* l1 = ListNode::buildList(ar, size_ar);
    ListNode* l2 = ListNode::buildList(br, size_br);

    ListNode* sum = ListNode::addTwoNumbers(l1, l2);

    while (sum != nullptr) {
        cout << sum->val << " ";
        sum = sum->next;
    }
    return 0;
}
