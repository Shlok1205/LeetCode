class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n=len(s)
        ans=""
        minLen=float('inf')
        
        left=0
        ones=0
        
        for right in range(n):
            if s[right]=='1':
                ones+=1
            
            while ones>k:
                if s[left]=='1':
                    ones-=1
                left+=1
            
            if ones==k:
                while s[left]=='0':
                    left+=1
                
                curr=s[left:right+1]
                
                if len(curr)<minLen:
                    minLen=len(curr)
                    ans=curr
                elif len(curr)==minLen and curr<ans:
                    ans=curr
        
        return ans