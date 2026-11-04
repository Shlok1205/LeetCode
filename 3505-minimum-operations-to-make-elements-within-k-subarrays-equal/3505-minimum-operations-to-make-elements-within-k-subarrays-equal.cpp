class Solution
{
public:
    multiset<int> low,high;
    long long sumLow=0,sumHigh=0;

    void add(int num)
    {
        if(low.empty() || num<=*low.rbegin())
        {
            low.insert(num);
            sumLow+=num;
        }
        else
        {
            high.insert(num);
            sumHigh+=num;
        }

        balance();
    }

    void remove(int num)
    {
        if(low.find(num)!=low.end())
        {
            low.erase(low.find(num));
            sumLow-=num;
        }
        else
        {
            high.erase(high.find(num));
            sumHigh-=num;
        }

        balance();
    }

    void balance()
    {
        while(low.size()>high.size()+1)
        {
            int num=*low.rbegin();
            low.erase(low.find(num));
            sumLow-=num;

            high.insert(num);
            sumHigh+=num;
        }

        while(low.size()<high.size())
        {
            int num=*high.begin();
            high.erase(high.find(num));
            sumHigh-=num;

            low.insert(num);
            sumLow+=num;
        }
    }

    long long getCost()
    {
        long long median=*low.rbegin();

        return median*low.size()-sumLow+
               sumHigh-median*high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k)
    {
        int n=nums.size();

        vector<long long> cost(n-x+1);

        for(int i=0;i<n;i++)
        {
            add(nums[i]);

            if(i>=x)
            {
                remove(nums[i-x]);
            }

            if(i>=x-1)
            {
                cost[i-x+1]=getCost();
            }
        }

        const long long INF=1e18;

        vector<vector<long long>> dp(k+1,
                                     vector<long long>(n+1,INF));

        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }

        for(int j=1;j<=k;j++)
        {
            for(int i=1;i<=n;i++)
            {
                dp[j][i]=dp[j][i-1];

                if(i>=x && dp[j-1][i-x]!=INF)
                {
                    dp[j][i]=min(dp[j][i],
                                 dp[j-1][i-x]+cost[i-x]);
                }
            }
        }

        return dp[k][n];
    }
};