// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int idx=-1;
//         for(int i=0;i<nums.size();i++) {
//             int left=0,right=INT_MAX;
//             for(int j=0;j<=i;j++) {
//                 left=max(left,nums[j]);
//             }
//             for(int j=i;j<nums.size();j++) {  //its actually O(n2)
//                 right=min(right,nums[j]);
//             }
//             int curr=left-right;
//             if(curr<=k) {
//                 return i;
//             }
//         }
//         return idx;
//     }
// };

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxx(n,INT_MIN);
        vector<int>minn(n,INT_MAX);
        maxx[0]=nums[0];
        minn[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++) {
            maxx[i]=max(maxx[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--) {
            minn[i]=min(minn[i+1],nums[i]);
        }
        for(int i=0;i<n;i++) {
            if((maxx[i]-minn[i])<=k) {
                return i;
            }
        }
        return -1;
    }
};