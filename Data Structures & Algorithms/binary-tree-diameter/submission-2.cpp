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

pair<int,int> diameter(TreeNode* node) {
    if(!node)   return {0,0};
    
    pair<int,int> pl = diameter(node->left);
    pair<int,int> pr = diameter(node->right);

    int ml = 1 + max(pl.second,pr.second);
    int md = max(max(pl.first,pr.first),pl.second+pr.second);
    
    return {md, ml};
}


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> sol = diameter(root);
        return sol.first;
    }
};
