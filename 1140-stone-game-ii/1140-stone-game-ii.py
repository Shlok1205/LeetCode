class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n=len(piles)
        suffix=[0]*(n+1)
        for i in range(n-1,-1,-1):
            suffix[i]=suffix[i+1]+piles[i]
        dp={}
        def solve(i,M):
            if i>=n:
                return 0
            if (i,M) in dp:
                return dp[(i,M)]
            if i+2*M>=n:
                dp[(i,M)]=suffix[i]
                return suffix[i]
            best=0
            for X in range(1,2*M+1):
                opponent=solve(i+X,max(M,X))
                current=suffix[i]-opponent
                best=max(best,current)
            dp[(i,M)]=best
            return best
        return solve(0,1)