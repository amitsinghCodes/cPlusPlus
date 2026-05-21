#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};

void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;

    Solution sol;
    vector<TreeNode*> trees = sol.generateTrees(n);

    cout << "Total trees: " << trees.size() << endl;

    for (TreeNode* root : trees) {
        preorder(root);
        cout << endl;
    }

    return 0;
}