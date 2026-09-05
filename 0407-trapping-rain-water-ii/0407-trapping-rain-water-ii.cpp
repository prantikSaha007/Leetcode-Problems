class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        if(n<=2 || m<=2) return 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        for(int i=0;i<n;i++) {
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][m-1],i,m-1});
            vis[i][0]=vis[i][m-1]=1;
        }
        for(int j=0;j<m;j++) {
            pq.push({heightMap[0][j],0,j});
            pq.push({heightMap[n-1][j],n-1,j});
            vis[0][j]=vis[n-1][j]=1;
        }
        int ans=0;
        vector<int>dirs={1,0,-1,0,1};
        while(!pq.empty()) {
            auto cur=pq.top();
            pq.pop();
            int h=cur[0],x=cur[1],y=cur[2];
            for(int i=0;i<4;i++) {
                int nx=x+dirs[i],ny=y+dirs[i+1];
                if(nx<0 || ny<0 ||nx>=n ||ny>=m || vis[nx][ny]) continue;
                vis[nx][ny]=1;
                if(heightMap[nx][ny]<h) {
                    ans+=h-heightMap[nx][ny];
                } 
                pq.push({max(heightMap[nx][ny],h),nx,ny});
            }
        }
        return ans;
    }
};