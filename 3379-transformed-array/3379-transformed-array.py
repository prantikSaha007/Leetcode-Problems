class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans=[0]*n
        for i in range(n):
            idx=(nums[i]+i)%n
            ans[i]=nums[idx]
        return ans
