class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int a=0,b=1;
        for(int i=2;i<nums.size();i++) {
            if(nums[a]>nums[b]) {
                arr1.push_back(nums[i]);
                a=i;
            } else {
                arr2.push_back(nums[i]);
                b=i;
            }
        }
        for(auto& x:arr2) {
            arr1.push_back(x);
        }
        return arr1;
    }
};