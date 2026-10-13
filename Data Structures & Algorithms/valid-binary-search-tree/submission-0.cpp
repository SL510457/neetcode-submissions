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
    bool dfs(TreeNode* node, long long max, long long min) {
        if(!node)   return true;
        if(node->val < max && node->val > min)
            return dfs(node->left, node->val, min) && dfs(node->right, max, node->val);
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        // dfs
        if(!root)   return true;
        
    
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }
};