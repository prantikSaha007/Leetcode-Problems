/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorder(TreeNode* root,string& ans) {
        if(root==NULL) return;
        ans+=to_string(root->val);
        ans+=',';
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }

    TreeNode* build(vector<int>& preorder,int& idx,long long lower,long long upper) {
        if(idx>=preorder.size()) return NULL;
        int val=preorder[idx];

        if(val<lower || val>upper) return NULL;
        TreeNode* root=new TreeNode(val);
        idx++;
        root->left=build(preorder,idx,lower,val);
        root->right=build(preorder,idx,val,upper);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<int>preorder;
        string part;
        stringstream ss(data);

        while(getline(ss,part,',')) {
            preorder.push_back(stoi(part));
        }
        int idx=0;
        return build(preorder,idx,LLONG_MIN,LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;