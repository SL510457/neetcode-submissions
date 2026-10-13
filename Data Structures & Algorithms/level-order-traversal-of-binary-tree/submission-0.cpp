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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return {};
        int s = 1;
        vector<vector<int>> sol;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> nodes;

            while(s > 0) {
                TreeNode* cur = q.front();
                q.pop();
                nodes.push_back(cur->val);

                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }

                s--;
            }
            s = q.size();
            sol.push_back(nodes);
        }

        return sol;
    }
};