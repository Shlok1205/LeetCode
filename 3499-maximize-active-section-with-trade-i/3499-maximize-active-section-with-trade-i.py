class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        ones=s.count('1')
        runs=[]
        i=0
        n=len(s)

        while i<n:
            j=i
            while j<n and s[j]==s[i]:
                j+=1
            runs.append((s[i],j-i))
            i=j
        best_gain=0

        for i in range(1,len(runs)-1):
            if runs[i][0]=='1' and runs[i-1][0]=='0' and runs[i+1][0]=='0':
                best_gain=max(best_gain,runs[i-1][1]+runs[i+1][1])

        return ones+best_gain