class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="",curr="";
        int left=0;
        int ones=0;
        int len=INT_MAX;
        for(int right=0;right<s.size();right++) {
            if(s[right]=='1') {
                ones++;
                while(ones==k) {
                    if(ones==k) {
                        if(len>=right-left+1) {
                            if(len==right-left+1) {
                                if(ans>s.substr(left,len)) ans=s.substr(left,len);
                            } else {
                                ans=s.substr(left,right-left+1);
                            }
                            len=right-left+1;
                        }
                    }
                    if(s[left]=='1') ones--;
                    left++;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
//         string ans="",curr="";
//         int left=k;
//         int len=INT_MAX;
//         for(int i=0;i<s.size();i++) {
//             left=k;
//             for(int j=i;j<s.size();j++) {
//                 if(s[j]=='1') {
//                     left--;
//                     if(left==0) {
//                         if(len>j-i+1) {
//                             len=min(len,j-i+1);
//                             ans=s.substr(i,len);
//                         } else if(len==j-i+1) {
//                             if(ans>s.substr(i,len)) ans=s.substr(i,len);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };