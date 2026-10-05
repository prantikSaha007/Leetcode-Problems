class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0;
        int ans=0;
        if(s[0]=='(') depth++;
        for(int i=1;i<s.size();i++) {
            if(s[i]=='(') {
                depth++;
            }
            if(s[i]==')') {
                depth--;
                if(s[i-1]=='(') {
                    ans+=1<<depth;
                }
            }
        }
        return ans;
    }
};