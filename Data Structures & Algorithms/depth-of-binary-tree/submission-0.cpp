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
    int depth(int d, TreeNode* node) {
        if(!node)   return d;
        
        d++;
        
        return max(depth(d,node->left), depth(d,node->right));
    }
    
    int maxDepth(TreeNode* root) {
        return depth(0,root);
    }
};
