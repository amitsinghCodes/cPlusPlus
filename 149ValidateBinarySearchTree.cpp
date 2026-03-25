#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* prev = NULL;

    bool inorder(TreeNode* root) {
        if (!root) return true;

        if (!inorder(root->left)) return false;

        if (prev && root->val <= prev->val)
            return false;

        prev = root;

        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};

int main() {
    /*
            2
           / \
          1   3
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution obj;

    cout << (obj.isValidBST(root) ? "true" : "false");

    return 0;
}