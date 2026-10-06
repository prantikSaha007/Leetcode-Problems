class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        // stack<char>st;  //O(n) space
        int open=0;
        for(auto& c:s) {
            if(c=='(') {
                open++;
            } 
            if(c==')') {
                if(open==0) ans++;
                else open--;
            }
        }
        ans+=open;
        return ans;
    }
};