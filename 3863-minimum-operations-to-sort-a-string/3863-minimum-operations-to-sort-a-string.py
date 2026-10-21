class Solution:
    def minOperations(self, s: str) -> int:
        n=len(s)
        ok=True
        for i in range(n-1):
            if(s[i]>s[i+1]):
                ok=False
                break
        if(ok):
            return 0
        if(n==2):
            return -1
        mn=min(s)
        mx=max(s)
        if(s[0]==mn or s[n-1]==mx):
            return 1
        for c in s[1:-1]:
            if(c==mn or c==mx):
                return 2
        return 3