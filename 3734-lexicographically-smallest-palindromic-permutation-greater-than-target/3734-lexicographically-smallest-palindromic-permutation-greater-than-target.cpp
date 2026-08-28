class Solution {
public:
    bool helper(vector<int>&cnt) {
        for(int i=0;i<26;i++) {
            if(cnt[i]<0) return false;
        }
        return true;
    }
    string lexPalindromicPermutation(string s, string target) {
        string ans="";
        string curr="";
        vector<int>cnt(26,0);
        for(char c:s) {
            cnt[c-'a']++;
        }
        int center=0;
        for(int i=0;i<26;i++) {
            if(cnt[i]%2) {
                if(center!=0) return "";
                center='a'+i;
                cnt[i]--;
            }
        }
        int size=s.size();
        int half=size/2;
        for(int i=0;i<half;i++) {
            cnt[target[i]-'a']-=2;
        }

        if(helper(cnt)) {
            string head=target.substr(0,half);
            string rev=head;
            reverse(rev.begin(),rev.end());
            string tail="";
            if(center!=0) tail+=center;
            tail+=rev;
            if(tail>target.substr(half)) {
                return head+tail;
            }
        }
        for(int i=half-1;i>=0;i--) {
            int idx=target[i]-'a';
            cnt[idx]+=2;
            if(!helper(cnt)) continue;

            for(int c=idx+1;c<26;c++) {
                if(cnt[c]==0) continue;
                cnt[c]-=2;
                string result=target.substr(0,i+1);
                result[i]='a'+c;

                for(int k=0;k<26;k++) {
                    int count=cnt[k]/2;
                    if(count>0) result.append(count,'a'+k);
                }
                string part=result;
                reverse(part.begin(),part.end());
                if(center!=0) result.push_back(center);
                result+=part;
                return result;
            }
        }
        return "";
    }
};