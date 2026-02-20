#include<iostream>
#include<queue>
using namespace std;

  //Definition for a binary tree node.
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();
            if(!node->left && !node->right) return depth;
            if(node->left) q.push({node->left, depth + 1});
            if(node->right) q.push({node->right, depth + 1});
        }
        return 0;
    }
};

int main() {
    /*
            3
           / \
          9  20
             / \
            15  7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Minimum Depth: " << obj.minDepth(root);

    return 0;
}