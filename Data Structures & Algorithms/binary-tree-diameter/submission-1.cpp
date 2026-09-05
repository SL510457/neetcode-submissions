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

int length(TreeNode* node, int l) {
    if(!node)   return l;
    l++;
    return max(length(node->left,l), length(node->right,l));
}

int diameter(TreeNode* node) {
    if(!node)   return 0;
    int curD = length(node->left,0) + length(node->right,0);
    int maxD = max(diameter(node->left),diameter(node->right));
    return max(curD,maxD);
}


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};
