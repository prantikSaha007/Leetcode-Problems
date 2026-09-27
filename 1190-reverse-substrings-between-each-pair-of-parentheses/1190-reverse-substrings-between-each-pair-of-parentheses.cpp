// class Solution {
// public:
//     string ans="";
//     void helper(string s) {
//         int r=s.find(')');
//         if(r==string::npos) {
//             ans=s;
//             return;
//         }
//         int l=s.rfind('(',r);
//         string left=s.substr(0,l);
//         string right=s.substr(r+1);
//         string inside=s.substr(l+1,r-l-1);
//         reverse(inside.begin(),inside.end()); //inside part reverse it
//         helper(left+inside+right);  //call it recursivly
//     }
//     string reverseParentheses(string s) {
//         helper(s);
//         return ans;
//     }
// };

class Solution {
public:
    
    string reverseParentheses(string s) {
        stack<string>st;
        string curr="";
        for(auto& c:s) {
            if(c=='(') {
                st.push(curr);
                curr.clear();
            }else if(c==')') {
                reverse(curr.begin(),curr.end());
                curr=st.top()+curr;
                st.pop();
            } else {
                curr+=c;
            }
        }
        return curr;
    }
};