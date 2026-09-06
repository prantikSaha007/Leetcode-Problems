// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         int MOD=(int)1e9+7;
//         vector<vector<int>>dp;
//         dp.assign(n+1,vector<int>(m+1,0));
//         for(int i=0;i<=n;i++) {
//             dp[i][m]=1;
//         }  //tabulation
//         for(int i=n-1;i>=0;i--) {
//             for(int j=m-1;j>=0;j--) {
//                 if(s[i]!=t[j]) {
//                     dp[i][j]=dp[i+1][j]; //skip
//                 } else {
//                     dp[i][j]=(dp[i+1][j+1]+dp[i+1][j])%MOD; //take+skip
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };


// class Solution {
// public:
//     int helper(int i,int j,string& s,string& t,vector<vector<long long>>& dp) {
//         if(j==t.size()) return 1;
//         if(i==s.size()) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         long skip=helper(i+1,j,s,t,dp);
//         long take=0;
//         if(s[i]==t[j]) {
//             take=helper(i+1,j+1,s,t,dp);
//         }
//         return dp[i][j]=skip+take;
//     }
//     int numDistinct(string s, string t) {  //memoization
//         int n=s.size();
//         int m=t.size();
//         vector<vector<long long>>dp;
//         dp.assign(n,vector<long long>(m,-1));
//         return helper(0,0,s,t,dp);
//     }
// };


class Solution {
public:
    int numDistinct(string s, string t) {  
        int n=s.size();
        int m=t.size();
        vector<int>dp(m+1,0);

        int MOD=(int)1e9+7;  //to avoid int overflow

        for(int i=1;i<=n;i++) {
            int last=1;
            for(int j=1;j<=m;j++) {
                int cur=dp[j];
                int take=0,skip=0;
                if(s[i-1]==t[j-1]) {
                    take=last;
                }
                skip=cur;
                dp[j]=(take+skip)%MOD;
                last=cur;  //space optimi
            }
        }
        return dp[m];
    }
};