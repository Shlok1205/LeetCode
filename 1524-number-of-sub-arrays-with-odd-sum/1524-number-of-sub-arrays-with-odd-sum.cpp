class Solution
{
public:
    int numOfSubarrays(vector<int>& arr)
    {
        long long odd=0, even=1;
        long long sum=0;
        long long ans=0;
        int mod=1e9+7;

        for(int num:arr)
        {
            sum+=num;

            if(sum%2==0)
            {
                ans+=odd;
                even++;
            }
            else
            {
                ans+=even;
                odd++;
            }

            ans%=mod;
        }

        return ans;
    }
};