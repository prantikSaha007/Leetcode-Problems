class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>>& vis) {
        vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
        int n=heights.size();
        int m=heights[0].size();
        vis[i][j]=true;  //the main part where water flow getting true
        for(auto& d:dirs) {
            int x=i+d[0],y=j+d[1];
            if(x<0 ||x>=n ||y<0 ||y>=m) continue;
            if(vis[x][y]) continue;
            if(heights[x][y]<heights[i][j]) continue;
            dfs(x,y,heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        for(int i=0;i<n;i++) dfs(i,0,heights,pacific); //pacific ones
        for(int i=0;i<m;i++) dfs(0,i,heights,pacific);
        for(int i=0;i<n;i++) dfs(i,m-1,heights,atlantic); //atlantic ones
        for(int i=0;i<m;i++) dfs(n-1,i,heights,atlantic);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};