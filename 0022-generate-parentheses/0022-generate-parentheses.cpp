class Solution {
public:
    vector<string>ans;
    void helper(int open,int close,string& curr,int n) {
        if(curr.size()==2*n) {
            ans.push_back(curr);
            return;
        }
        if(open<n) {
            curr.push_back('(');
            helper(open+1,close,curr,n);
            curr.pop_back();
        }
        if(close<open) {
            curr.push_back(')');
            helper(open,close+1,curr,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        helper(0,0,curr,n);
        return ans;
    }
};