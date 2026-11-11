class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        long long ans = 0;

        int mn = min(need1, need2);
        int mx = max(need1, need2);

        if(costBoth < cost1 + cost2)
        {
            ans += 1LL * mn * costBoth;

            if(need1 > need2)
                ans += 1LL * (need1 - need2) * min(cost1, costBoth);
            else
                ans += 1LL * (need2 - need1) * min(cost2, costBoth);
        }
        else
        {
            ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }

        return ans;
    }
};