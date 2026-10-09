class Solution:
    def minInsertions(self, s: str) -> int:
        count=0
        ans=0
        i=0
        while(i<len(s)):
            if(s[i]=='('):
                count+=1
            else :
                if(i+1<len(s) and s[i+1]==')'):
                    i+=1
                else:
                    ans+=1
                if(count>0): 
                    count-=1
                else: 
                    ans+=1
            i+=1
        
        return ans+count*2