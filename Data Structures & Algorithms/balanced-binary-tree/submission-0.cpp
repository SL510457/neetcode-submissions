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
    pair<bool,int> isBalancedH(TreeNode* node, int l) {
        if(!node)   return {true,l};
        
        pair<bool,int> left = isBalancedH(node->left, l+1);
        pair<bool,int> right = isBalancedH(node->right, l+1);
        
        bool isB = false;
        if(left.first && right.first)
            if(abs(left.second - right.second) < 2) isB = true;
        
        int maxl = max(left.second, right.second);
        
        return {isB, maxl};

    }
    

    bool isBalanced(TreeNode* root) {
        pair<bool,int> sol = isBalancedH(root, 0);
        return sol.first;
    }
};
