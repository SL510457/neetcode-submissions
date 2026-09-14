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

class Solution {
public:
    int cnt = 0;
    void maxnode(int maxVal, TreeNode* node) {
        if(!node)   return;
        
        if(node->val >= maxVal) {
            maxVal = node->val;
            cnt++;
        }

        maxnode(maxVal, node->left);
        maxnode(maxVal, node->right);
    }

    int goodNodes(TreeNode* root) {
        maxnode(-101,root);
        return cnt;
    }
};
