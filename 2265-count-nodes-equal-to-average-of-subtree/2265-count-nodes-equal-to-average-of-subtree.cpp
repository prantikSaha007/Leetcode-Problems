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
    int ans=0;
    pair<int,int> helper(TreeNode* root) {
        if(!root) return {0,0};
        auto [leftsum,leftn]=helper(root->left);
        auto [rightsum,rightn]=helper(root->right);
        int sum=root->val+leftsum+rightsum;
        int n=1+leftn+rightn;
        if(root->val==sum/n) ans++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return ans;
    }
};