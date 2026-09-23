// class Solution {
// public:
//     int helper(vector<int>& nums, int x,int left,int right) {
        
//         if(x==0) return 0;
//         if(x<0) return -1;
//         int front=helper(nums,x-nums[left],left+1,right);
//         int back=helper(nums,x-nums[right],left,right-1);
//         return min(front,back);
//     }
//     int minOperations(vector<int>& nums, int x) {
//         int n=nums.size();
//         return helper(nums,x,0,n-1);
//     }
// };


class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int left=0;
        int totalsum=0;
        for(int i=0;i<n;i++) totalsum+=nums[i];
        int sum=0;
        int ans=INT_MIN;
        for(int right=0;right<n;right++) {
            sum+=nums[right];

            while(left<=right && sum>totalsum-x) {
                sum-=nums[left];
                left++;
            }
            if(sum==totalsum-x) ans=max(ans,right-left+1);//longest length
        }
        return ans==INT_MIN?-1:n-ans; 
    }
};