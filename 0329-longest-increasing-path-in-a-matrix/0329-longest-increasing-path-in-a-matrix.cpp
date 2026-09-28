class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        if(dp[i][j]!=0) {
            return dp[i][j];
        }
        if(j>0 && matrix[i][j]>matrix[i][j-1]) {
            ans=max(ans,1+dfs(i,j-1,matrix,dp));
        }
        if(i>0 && matrix[i][j]>matrix[i-1][j]) {
            ans=max(ans,1+dfs(i-1,j,matrix,dp));
        }
        if(i+1<n && matrix[i][j]>matrix[i+1][j]) {
            ans=max(ans,1+dfs(i+1,j,matrix,dp));
        }
        if(j+1<m && matrix[i][j]>matrix[i][j+1]) {
            ans=max(ans,1+dfs(i,j+1,matrix,dp));
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;    
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};