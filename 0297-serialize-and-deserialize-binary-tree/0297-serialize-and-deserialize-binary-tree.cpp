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
        if(root==NULL) {
            ans+="NULL,";
            return;
        }
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

    TreeNode* build(stringstream& ss) {
        string part;
        getline(ss,part,',');
        if(part=="NULL") return NULL;
        TreeNode* root=new TreeNode(stoi(part));
        root->left=build(ss);
        root->right=build(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));