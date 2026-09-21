class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        priority_queue<int,vector<int>,greater<>>pq;
        pq.push(intervals[0][1]);
        long long ans=0;
        for(int i=1;i<n;i++) {
            while(!pq.empty() && pq.top()<intervals[i][0]) {
                pq.pop();
            }
            ans+=pq.size();
            pq.push(intervals[i][1]);
        }
        return ans;
    }
};