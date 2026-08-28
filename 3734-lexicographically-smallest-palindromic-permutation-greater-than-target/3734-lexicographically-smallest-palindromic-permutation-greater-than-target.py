class Solution:
    def lexPalindromicPermutation(self, s, target):
        count=[0]*26

        for ch in s:
            count[ord(ch)-ord('a')]+=1

        odd=[]

        for i in range(26):
            if count[i]%2:
                odd.append(i)

        if len(odd)>1:
            return ""

        middle=chr(odd[0]+ord('a')) if odd else ""
        halfCount=[x//2 for x in count]
        halfLength=len(s)//2
        targetHalf=target[:halfLength]

        def buildPalindrome(left):
            return left+middle+left[::-1]

        def remainingString(freq):
            result=""

            for i in range(26):
                result+=chr(i+ord('a'))*freq[i]

            return result

        def nextGreaterHalf(value):
            freq=halfCount[:]
            matched=0

            while matched<halfLength:
                index=ord(value[matched])-ord('a')

                if freq[index]==0:
                    break

                freq[index]-=1
                matched+=1

            for position in range(matched, -1, -1):
                if position<halfLength:
                    current=ord(value[position])-ord('a')

                    for nextChar in range(current+1, 26):
                        if freq[nextChar]>0:
                            freq[nextChar]-=1
                            return value[:position]+chr(nextChar+ord('a'))+remainingString(freq)

                if position>0:
                    freq[ord(value[position-1])-ord('a')]+=1

            return ""

        freq=halfCount[:]
        canUseTargetHalf=True

        for ch in targetHalf:
            index=ord(ch)-ord('a')

            if freq[index]==0:
                canUseTargetHalf=False
                break

            freq[index]-=1

        if canUseTargetHalf:
            answer=buildPalindrome(targetHalf)

            if answer>target:
                return answer

        nextHalf=nextGreaterHalf(targetHalf)

        if not nextHalf:
            return ""

        return buildPalindrome(nextHalf)