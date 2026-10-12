class Solution
{
public:
    int maxSum(vector<int>& nums, int k)
    {
        const long long MOD=1000000007;
        vector<long long> bits(32,0);

        for(int n:nums)
        {
            for(int i=0;i<32;i++)
            {
                if(n & (1<<i))
                {
                    bits[i]++;
                }
            }
        }

        long long ans=0;

        for(int i=0;i<k;i++)
        {
            long long num=0;

            for(int j=31;j>=0;j--)
            {
                if(bits[j]>0)
                {
                    num|=(1LL<<j);
                    bits[j]--;
                }
            }

            ans=(ans+num*num)%MOD;
        }

        return ans;
    }
};