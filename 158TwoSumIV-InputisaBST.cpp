#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, int k, unordered_set<int>& seen) {
        if (!root) return false;

        if (seen.count(k - root->val)) return true;

        seen.insert(root->val);

        return dfs(root->left, k, seen) || dfs(root->right, k, seen);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }
};

int main() {
    /*
            5
           / \
          3   6
         / \   \
        2   4   7
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << (obj.findTarget(root, 9) ? "true" : "false") << endl;

    return 0;
}