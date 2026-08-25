// class Solution {
// public:
//     vector<long long>dp;
//     long long helper(int i,vector<int>& nums, vector<int>& colors) {
//         if(i>=nums.size()) return 0;
//         if(dp[i]!=-1) return dp[i];

//         int take=nums[i]+helper(i+2,nums,colors);
//         int skip=helper(i+1,nums,colors);
//         int color;
//         if(i+1<colors.size()) {
//         if(colors[i+1]!=colors[i]) {
//             color=nums[i]+helper(i+1,nums,colors);
//         } else {
//             color=0;
//         }
//         }
//         return dp[i]=max({take*1LL,skip*1LL,color*1LL});
//     }
//     long long rob(vector<int>& nums, vector<int>& colors) {
//         int n=nums.size();
//         dp.assign(n,-1);
//         return helper(0,nums,colors);
//     }
// };


class Solution {
public:
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++) {
            long long take,skip;
                skip=dp[i-1];
            if(colors[i-1]==colors[i]) {
                take=nums[i]*1LL;
                if(i-2>=0) take+=dp[i-2];
            } else {
                take=nums[i]*1LL+dp[i-1];
            }
            dp[i]=max(take,skip);
        }
        return dp[n-1];
    }
};