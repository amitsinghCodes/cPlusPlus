#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val == val) return root;
            else if (val < root->val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    /*
            4
           / \
          2   7
         / \
        1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode* ans = obj.searchBST(root, 2);

    if (ans) {
        cout << "Subtree preorder: ";
        preorder(ans);
    } else {
        cout << "Not found";
    }

    return 0;
}