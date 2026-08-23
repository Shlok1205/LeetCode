class Solution:
    def sumGame(self, num: str) -> bool:
        n=len(num)
        leftSum=rightSum=0
        leftQ=rightQ=0

        for i in range(n):
            if num[i]=='?':
                if i<n//2:
                    leftQ+=1
                else:
                    rightQ+=1
            else:
                if i<n//2:
                    leftSum+=int(num[i])
                else:
                    rightSum+=int(num[i])

        # Odd number of '?' means Alice gets an extra move
        if (leftQ+rightQ)%2==1:
            return True

        # Bob can balance only if the required difference matches
        return leftSum-rightSum!=(rightQ-leftQ)//2*9