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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*,bool>>q;
        if(root->left) q.push({root->left,true});
        if(root->right) q.push({root->right,false});
        int ans=0;
        // bool curr=true;
        while(!q.empty()) {
            auto [node,curr]=q.front();
            q.pop();
            if(node->left) q.push({node->left,true});
            if(!node->left && !node->right && curr) {
                ans+=node->val;
            }
            if(node->right) q.push({node->right,false});
        }
        return ans;
    }
};