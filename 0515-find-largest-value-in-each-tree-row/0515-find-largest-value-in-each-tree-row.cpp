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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        int big=INT_MIN;
        while(!q.empty()) {
            int size=q.size();
            big=INT_MIN;
            for(int i=0;i<size;i++) {
                TreeNode* curr=q.front();
                q.pop();
                big=max(big,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(big);
        }
        return ans;
    }
};