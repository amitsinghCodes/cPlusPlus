#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;

        path += to_string(root->val);

        // If leaf node
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        path += "->";

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};

int main() {
    /*
        Constructing the tree:
              1
             / \
            2   3
             \
              5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);

    // Print result
    cout << "Binary Tree Paths:\n";
    for (const string& path : result) {
        cout << path << endl;
    }

    return 0;
}