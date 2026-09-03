
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=nums1[0];
        bool odd=false;
        for(auto& x:nums1) {
            mini=min(mini,x);
            odd |=(x&1);
        }
        return (mini&1)==odd;
    }
};
// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int n=nums1.size();
//         int odd=0,even=0;
//         int oddsmall=INT_MAX,evensmall=INT_MAX;
//         vector<int>nums2(n);
//         for(int i=0;i<n;i++) {
//             if(nums1[i]%2==0) {
//                 even++;
//                 evensmall=min(evensmall,nums1[i]);
//             } else {
//                 odd++;
//                 oddsmall=min(oddsmall,nums1[i]);
//             }
//         }
//         int oddid,evenid;
//         for(int i=0;i<n;i++) {
//             if(nums1[i]==evensmall) evenid=i;
//             if(nums1[i]==oddsmall) oddsmall=i;
//         }
//         if((odd==0 && even!=0)||(odd!=0 && even==0)) {
//             return true;
//         }
//         if(odd!=0 && even!=0) {

//         }
//     }
// };