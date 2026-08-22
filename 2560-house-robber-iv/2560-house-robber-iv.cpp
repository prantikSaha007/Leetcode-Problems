// class Solution {
// public:
//     int capability=INT_MAX;
//     vector<vector<int>>dp;
//     int helper(vector<int>& nums, int k,int i) {
//         if( k==0) return 0;
//         if(i>=nums.size()) return INT_MAX;
//         if(dp[i][k]!=-1) return dp[i][k];
//         int take;
//         take=max(nums[i],helper(nums,k-1,i+2));  //dp approach but gives TLE time comp O(n*k)
//         int skip=helper(nums,k,i+1);
//         capability=min(take,skip);
//         return dp[i][k]=capability;
//     }
//     int minCapability(vector<int>& nums, int k) {
//         int n=nums.size();
//         dp.assign(n,vector<int>(k+1,-1));
//         return helper(nums,k,0);
//     }
// };



class Solution {
public:
    bool helper(vector<int>& nums, int k,int cap) {
        int count=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<=cap) {
                count++;
                i++;
            }
        }
        if(count>=k) {
            return true;
        } else {
            return false;
        }
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(helper(nums,k,mid)) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};