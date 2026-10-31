class Solution {
public:
    
    int mod=1e9+7;
    vector<vector<vector<long long int>>>dp;
    long long int helper(vector<vector<int>>& grid,int i,int j,int dir) {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) {
            return 1;
        }
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        if(grid[i][j]==1) {
            if(dir==0) {
                dp[i][j][dir]=helper(grid,i+1,j,1);
            } else {
                dp[i][j][dir]=helper(grid,i,j+1,0);
            }
        } else {
            dp[i][j][dir]=(helper(grid,i,j+1,0)+helper(grid,i+1,j,1))%mod;
        }
        return dp[i][j][dir];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.assign(n,vector<vector<long long int>>(m,{-1,-1}));
        return helper(grid,0,0,0);        
    }
};