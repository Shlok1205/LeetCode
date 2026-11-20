class Solution
{
public:
    int maxSelectedElements(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> dp(1000002, 0);

        int ans = 0;

        for(int num : nums)
        {
            dp[num + 1] = max(dp[num + 1], dp[num] + 1);

            dp[num] = max(dp[num], dp[num - 1] + 1);

            ans = max(ans, max(dp[num], dp[num + 1]));
        }

        return ans;
    }
};