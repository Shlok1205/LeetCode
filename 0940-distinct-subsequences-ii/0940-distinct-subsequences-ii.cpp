class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int n=s.size();
        int MOD=1e9+7;

        vector<int> dp(26,0);
        int total=0;

        for(char c:s)
        {
            int x=c-'a';

            int add=(total+1-dp[x]+MOD)%MOD;

            dp[x]=(total+1)%MOD;
            total=(total+add)%MOD;
        }

        return total;
    }
};