#include<iostream>
#include<stack>
#include<vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while(current || !st.empty()){
            while(current){
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}