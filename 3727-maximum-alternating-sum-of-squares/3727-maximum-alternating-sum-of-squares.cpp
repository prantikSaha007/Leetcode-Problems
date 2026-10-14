class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end(),greater());
        long long ans=0;
        if(n%2==0) {
        for(int i=0;i<n/2;i++) {
            ans+=nums[i]*nums[i]*1LL;
        }
        } else {
            for(int i=0;i<n/2+1;i++) {
            ans+=nums[i]*nums[i]*1LL;
        }
        }
        if(n%2==0) {
        for(int i=n/2;i<n;i++) {
            ans-=nums[i]*nums[i]*1LL;
        }
        } else {
            for(int i=n/2+1;i<n;i++) {
            ans-=nums[i]*nums[i]*1LL;
        }
        }
        return ans;
    }
};