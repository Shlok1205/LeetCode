class Solution
{
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget)
    {
        int n = items.size();
        vector<int> dp(budget + 1, 0);

        for(int i = 0; i < n; i++)
        {
            int factor = items[i][0];
            int price = items[i][1];

            int bonus = 0;

            for(int j = 0; j < n; j++)
            {
                if(i != j && items[j][0] % factor == 0)
                {
                    bonus++;
                }
            }

            vector<int> next = dp;

            for(int b = price; b <= budget; b++)
            {
                next[b] = max(next[b], dp[b - price] + bonus + 1);
            }

            for(int b = price; b <= budget; b++)
            {
                next[b] = max(next[b], next[b - price] + 1);
            }

            dp = next;
        }

        return dp[budget];
    }
};