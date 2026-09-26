class Solution {
public:
    void helper(string& s,int idx,int left,int right,int pair,string path,unordered_set<string>& ans) {
        if(idx==s.size()) {
            if(left==0 && right==0 && pair==0) {
                ans.insert(path);
            }
            return;
        }
        if(s[idx]!='(' && s[idx]!=')') {
            helper(s,idx+1,left,right,pair,path+s[idx],ans);
        } else {
            if(s[idx]=='(') {
                if(left>0) {
                    helper(s,idx+1,left-1,right,pair,path,ans);
                }
                helper(s,idx+1,left,right,pair+1,path+s[idx],ans);
            }
            if(s[idx]==')') {
                if(right>0) {
                    helper(s,idx+1,left,right-1,pair,path,ans);
                }
                if(pair>0) {
                    helper(s,idx+1,left,right,pair-1,path+s[idx],ans);
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        int left=0,right=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') left++;
            if(s[i]==')') {
                if(left>0) {
                    left--;
                } else {
                    right++;
                }
            }
        }
        helper(s,0,left,right,0,"",ans);
        return vector<string>(ans.begin(),ans.end());
    }
};