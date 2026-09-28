class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(auto& c:s) {
            if(c=='(') {
                st.push(c);
            }
            if(c==')') {
                if(ans>st.size()) {
                    ans=ans;
                } else {
                    ans=st.size();
                }
                st.pop();
            }
        }
        return ans;
    }
};