#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    ListNode* headNode;

public:
    Solution(ListNode* head) {
        headNode = head;
    }

    int getRandom() {
        int result = headNode->val;
        ListNode* curr = headNode;
        int count = 1;

        while (curr) {
            if (rand() % count == 0) {
                result = curr->val;
            }

            curr = curr->next;
            count++;
        }

        return result;
    }
};

int main() {
    srand(time(0));

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol(head);

    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;

    return 0;
}