class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,idx=1;
        int ans=0;
        while(i<nums.size()) {
            if(nums[i]%k==0 && k*idx==nums[i]) {
                idx++;
            } else if(nums[i]%k==0 && k*idx<nums[i]) {
                ans=k*idx;
            }
            i++;
        }
        if(ans==0) ans=idx*k;
        return ans;
    }
};