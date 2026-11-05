// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         int ans=0;
//         int n=arr1.size();
//         int m=arr2.size();
//         for(int i=0;i<n;i++) {
//             int cur=0;
//             for(int j=0;j<m;j++) { //O(n^2)time comp
//                 if(abs(arr1[i]-arr2[j])<=d) cur=1;
//             }
//             if(cur==0) ans++; 
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        int n=arr1.size();
        int m=arr2.size();
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<n;i++) {
            int cur=0;
            int st=0,end=m-1;
            while(st<=end){
                int mid=st+(end-st)/2;
                if(abs(arr1[i]-arr2[mid])<=d) {
                    cur=1;
                    break;
                } 
                if(arr2[mid]<arr1[i]) {
                    st=mid+1;
                } else {
                    end=mid-1;
                }
            }
            if(cur==0) ans++; 
        }
        return ans;
    }
};