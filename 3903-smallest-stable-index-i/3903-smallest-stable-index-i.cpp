class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=INT_MAX,idx=-1;
        for(int i=0;i<nums.size();i++) {
            int left=0,right=INT_MAX;
            for(int j=0;j<=i;j++) {
                left=max(left,nums[j]);
            }
            for(int j=i;j<nums.size();j++) {
                right=min(right,nums[j]);
            }
            int curr=left-right;
            if(curr<=k) {
                return i;
            }
        }
        return idx;
    }
};