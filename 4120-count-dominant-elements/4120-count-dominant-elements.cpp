class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            double avg=0;
            if(i>0 && i<n-1) {
                avg=(double)(nums[i-1]+nums[i+1])/2.0;
            } else if(i==0 && i<n-1) {
                avg=(double)nums[i+1];
            } else if(i==n-1 && i>0) {
                avg=(double)nums[i-1];
            } 
            if((double)nums[i]>=avg) {
                ans++;
            }
        }
        return ans;
    }
};