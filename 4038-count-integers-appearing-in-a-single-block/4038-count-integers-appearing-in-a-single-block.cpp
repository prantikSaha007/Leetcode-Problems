class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        m[nums[0]]=1;
        for(int i=1;i<n;i++) {
            if(nums[i]!=nums[i-1]) {
                m[nums[i]]++;
            }
        }
        int count=0;
        for(auto& a:m) {
            if(a.second==1) {
                count++;
            }
        }
        return count;
    }
};