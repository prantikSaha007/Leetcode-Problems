class Solution:
    def helper(self,s:str,idx:int,left:int,right:int,pair:int,path:str,ans:set):
        if(len(s)==idx):
            if(left==0 and right==0 and pair==0): 
                ans.add(path)
            return
        if(s[idx]=='('):
            if(left>0): self.helper(s,idx+1,left-1,right,pair,path,ans)
            self.helper(s,idx+1,left,right,pair+1,path+s[idx],ans)
        elif(s[idx]==')'):
            if(pair>0): self.helper(s,idx+1,left,right,pair-1,path+s[idx],ans)
            if(right>0): self.helper(s,idx+1,left,right-1,pair,path,ans)
        else:
            self.helper(s,idx+1,left,right,pair,path+s[idx],ans)

    def removeInvalidParentheses(self, s: str) -> list[str]:
        ans=set()
        left=0
        right=0
        for i in range(len(s)):
            if(s[i]=='('):
                left+=1
            elif(s[i]==')'):
                if(left>0): left-=1
                else: right+=1
        
        self.helper(s,0,left,right,0,"",ans);
        return list(ans)