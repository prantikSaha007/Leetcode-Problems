class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n=len(s)
        st=0
        end=n-1
        while(st<end):
            temp=s[st]
            s[st]=s[end]
            s[end]=temp
            st+=1
            end-=1

