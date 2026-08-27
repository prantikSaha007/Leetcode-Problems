class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans="";
        int cnt[26]={};
        for(char c: s) {
            cnt[c-'a']++;
        }

        for(char ch:target) {
            cnt[ch-'a']--;
        }
        for(int i=target.size()-1;i>=0;i--) {
            int curr=target[i]-'a';
            cnt[curr]++;
            bool ok=true;
            for(int c=0;c<26;c++) {
                if(cnt[c]<0) {
                    ok=false;
                    break;
                }
            }
            if(!ok) continue;
            int next=-1;
            for(int c=curr+1;c<26;c++) {
                if(cnt[c]>0) {
                    next=c;
                    break;
                }
            }
            if(next==-1) continue;
            cnt[next]--;
            string ans=target.substr(0,i);
            ans+=char('a'+next);
            for(int c=0;c<26;c++) {
                ans.append(cnt[c],char('a'+c));
            }
            return ans;
        }
        return "";
    }
};