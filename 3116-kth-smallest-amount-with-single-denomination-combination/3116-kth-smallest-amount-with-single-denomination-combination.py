from math import gcd

class Solution:
    def findKthSmallest(self, coins, k):
        n=len(coins)

        low=1
        high=min(coin*k for coin in coins)

        while low<high:
            mid=low+(high-low)//2

            if self.count(mid,coins)>=k:
                high=mid
            else:
                low=mid+1

        return low

    def count(self,x,coins):
        n=len(coins)
        total=0

        for mask in range(1,1<<n):
            lcm=1
            bits=0
            possible=True

            for i in range(n):
                if mask&(1<<i):
                    bits+=1
                    lcm=lcm//gcd(lcm,coins[i])*coins[i]

                    if lcm>x:
                        possible=False
                        break

            if not possible:
                continue

            multiples=x//lcm

            if bits%2==1:
                total+=multiples
            else:
                total-=multiples

        return total