class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n=len(word1)
        m=len(word2)
        last=[-1]*m
        i=n-1
        j=m-1
        while i>=0 and j>=0:
            if word1[i]==word2[j]:
                last[j]=i
                j-=1
            i-=1
        ans=[]
        j=0
        canChange=True
        for i in range(n):
            if j==m:
                break
            if word1[i]==word2[j]:
                ans.append(i)
                j+=1
            elif canChange:
                if j==m-1 or i<last[j+1]:
                    ans.append(i)
                    j+=1
                    canChange=False
        if j==m:
            return ans
        return []