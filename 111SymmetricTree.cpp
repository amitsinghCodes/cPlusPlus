#include<iostream>
#include<queue>
using namespace std;
  ///Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* a = q.front(); q.pop();
            TreeNode* b = q.front(); q.pop();

            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val != b->val) return false;

            q.push(a->left); q.push(b->right);
            q.push(a->right); q.push(b->left);
        }
        return true;
    }
};

int main() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;

    cout << boolalpha;
    cout << "Is Symmetric: " << sol.isSymmetric(root) << endl;

    return 0;
}