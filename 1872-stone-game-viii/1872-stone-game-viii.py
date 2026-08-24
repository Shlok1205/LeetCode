class Solution:
    def stoneGameVIII(self, stones):
        n=len(stones)

        prefix=0
        for i in range(n):
            prefix+=stones[i]
            stones[i]=prefix

        dp=stones[-1]

        for i in range(n-2,0,-1):
            dp=max(dp,stones[i]-dp)

        return dp