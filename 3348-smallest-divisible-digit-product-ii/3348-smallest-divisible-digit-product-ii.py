class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        n = len(num)
        tt = t
        a = 0
        while tt % 2 == 0:
            tt //= 2; a += 1
        b = 0
        while tt % 3 == 0:
            tt //= 3; b += 1
        c = 0
        while tt % 5 == 0:
            tt //= 5; c += 1
        dd7 = 0
        while tt % 7 == 0:
            tt //= 7; dd7 += 1
        if tt != 1:
            return "-1"
        needA, needB, needC, needD = a, b, c, dd7

        DIGIT_EXP = {
            1:(0,0,0,0), 2:(1,0,0,0), 3:(0,1,0,0), 4:(2,0,0,0), 5:(0,0,1,0),
            6:(1,1,0,0), 7:(0,0,0,1), 8:(3,0,0,0), 9:(0,2,0,0),
        }

        MD = [[0]*(needB+1) for _ in range(needA+1)]
        for da in range(needA+1):
            for db in range(needB+1):
                lo = min(da, db)
                best = None
                for k in range(lo+1):
                    val = k + (da-k+2)//3 + (db-k+1)//2
                    if best is None or val < best:
                        best = val
                MD[da][db] = best

        prefix2=[0]*(n+1); prefix3=[0]*(n+1); prefix5=[0]*(n+1); prefix7=[0]*(n+1)
        for i, ch in enumerate(num):
            dgt = int(ch)
            e2,e3,e5,e7 = DIGIT_EXP[dgt] if dgt != 0 else (0,0,0,0)
            prefix2[i+1]=prefix2[i]+e2
            prefix3[i+1]=prefix3[i]+e3
            prefix5[i+1]=prefix5[i]+e5
            prefix7[i+1]=prefix7[i]+e7

        hasZero = '0' in num
        firstZeroIdx = num.index('0') if hasZero else n

        def greedy(m, da, db, dc, dd):
            res = []
            for pos in range(m):
                remaining = m - pos - 1
                for dig in range(1, 10):
                    e2,e3,e5,e7 = DIGIT_EXP[dig]
                    nda = da-e2 if da-e2>0 else 0
                    ndb = db-e3 if db-e3>0 else 0
                    ndc = dc-e5 if dc-e5>0 else 0
                    ndd = dd-e7 if dd-e7>0 else 0
                    if ndc+ndd <= remaining and MD[nda][ndb] <= remaining-ndc-ndd:
                        res.append(str(dig))
                        da,db,dc,dd = nda,ndb,ndc,ndd
                        break
            return ''.join(res)

        if not hasZero:
            E2,E3,E5,E7 = prefix2[n],prefix3[n],prefix5[n],prefix7[n]
            if E2>=needA and E3>=needB and E5>=needC and E7>=needD:
                return num

        upper = firstZeroIdx if hasZero else n-1
        for i in range(upper, -1, -1):
            base2,base3,base5,base7 = prefix2[i],prefix3[i],prefix5[i],prefix7[i]
            startD = 1 if (hasZero and i==firstZeroIdx) else int(num[i])+1
            if startD > 9:
                continue
            m = n-1-i
            for dig in range(startD, 10):
                e2,e3,e5,e7 = DIGIT_EXP[dig]
                t2=base2+e2; t3=base3+e3; t5=base5+e5; t7=base7+e7
                da_ = needA-t2 if needA-t2>0 else 0
                db_ = needB-t3 if needB-t3>0 else 0
                dc_ = needC-t5 if needC-t5>0 else 0
                dd_ = needD-t7 if needD-t7>0 else 0
                if dc_+dd_ <= m and MD[da_][db_] <= m-dc_-dd_:
                    suffix = greedy(m, da_, db_, dc_, dd_)
                    return num[:i] + str(dig) + suffix

        minLen = needC + needD + MD[needA][needB]
        L = max(n+1, minLen)
        return greedy(L, needA, needB, needC, needD)