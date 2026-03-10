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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \  /
        4  5 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution obj;
    cout << obj.countNodes(root) << endl;  // Output: 6

    return 0;
}


/*
if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            count++;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return count;
*/