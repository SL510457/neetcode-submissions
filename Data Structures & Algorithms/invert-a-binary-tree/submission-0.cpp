/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void invert(TreeNode* node) {
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void dfs(TreeNode* node) {
    if(!node)   return;
    invert(node);
    dfs(node->left);
    dfs(node->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
