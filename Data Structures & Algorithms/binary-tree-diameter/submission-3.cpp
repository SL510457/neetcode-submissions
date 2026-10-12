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
    pair<int,int> dfs(TreeNode* node) {
        if(!node)   return {0,0};
        
        pair<int,int> pl = dfs(node->left);
        pair<int,int> pr = dfs(node->right);
        
        int mh = max(pl.second, pr.second)+1;
        int md = max({pl.first,pr.first, pl.second+pr.second});
        
        return {md, mh};
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> sol = dfs(root);
        return sol.first;
    }
};
