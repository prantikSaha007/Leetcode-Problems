class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(auto& a:knowledge) {
            m[a[0]]=a[1];
        }
        string curr="";
        string ans="";
        int check=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') check=1;
            if(check==1 && s[i]!='(' && s[i]!=')') curr+=s[i];
            if(check==0 && s[i]!=')') ans+=s[i];
            if(s[i]==')' && check==1) {
                if(m[curr]=="") ans+='?';
                ans+=m[curr];
                check=0;
                curr="";
            }
            
        }
        return ans;
    }
};