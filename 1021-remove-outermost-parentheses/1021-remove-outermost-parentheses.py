class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        count=0
        ans=""
        for i in range(len(s)):
            if(s[i]=='('):
                if(count>0): ans+=s[i] 
                count+=1
            if(s[i]==')'):
                if(count>1): ans+=s[i]
                count-=1
        return ans