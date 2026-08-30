class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int maxiId,miniId;
        if(n==1) return 1;
        for(int i=0;i<n;i++) {
            if(nums[i]==mini) miniId=i;
            if(nums[i]==maxi) maxiId=i;
        }
        int ans;
        if(miniId>maxiId) {
            ans=min({miniId+1,n-maxiId,maxiId+1+n-miniId});
            
        } else {
            ans=min({maxiId+1,n-miniId,miniId+1+n-maxiId});
        }
        return ans;
    }
};