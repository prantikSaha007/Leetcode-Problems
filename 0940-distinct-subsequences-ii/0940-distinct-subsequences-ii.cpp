class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD=1e9+7;
        int n=s.size();
        vector<int>dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++) {
            //try extending subsequence ending before i
            for(int j=0;j<i;j++) {
                if(s[i]!=s[j]) {
                    dp[i]=(dp[i]+dp[j])%MOD;
                }
            }
            ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};