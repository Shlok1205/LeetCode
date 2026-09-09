class Solution
{
public:
    long long countCommas(long long n)
    {
        long long ans=0;
        long long p=1000;

        while(p<=n)
        {
            ans+=(n-p+1);

            if(p>n/1000)
                break;

            p*=1000;
        }

        return ans;
    }
};