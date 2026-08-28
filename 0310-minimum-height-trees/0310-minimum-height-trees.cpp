class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};

        vector<list<int>>adj(n);
        vector<int>degree(n,0);
        for(auto& edge:edges) {
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>leaves;
        for(int i=0;i<n;i++) {
            if(degree[i]==1) leaves.push(i);
        }
        int remain=n;
        while(remain>2) {
            int leavescount=leaves.size();
            remain=remain-leavescount;
            for(int i=0;i<leavescount;i++) {
                int leaf=leaves.front();
                leaves.pop();
                for(int neigh:adj[leaf]) {
                    degree[neigh]--;
                    if(degree[neigh]==1) {
                        leaves.push(neigh);
                    }
                }
            }
        }
        vector<int>res;
        while(!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
    }
};