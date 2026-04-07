#include <iostream>
#include <vector>
using namespace std;

// Tree Node Definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        dfs(root->left, ans);   // Left
        dfs(root->right, ans);  // Right
        ans.push_back(root->val); // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

int main() {
    /*
        Constructing the tree:
            1
             \
              2
             /
            3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal:\n";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}