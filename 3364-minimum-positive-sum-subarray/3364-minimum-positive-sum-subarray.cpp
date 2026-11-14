class Solution
{
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r)
    {
        int n=nums.size();
        int ans=INT_MAX;

        vector<int> prefix(n+1,0);

        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=l;j<=r;j++)
            {
                if(i+j>n)
                {
                    break;
                }

                int sum=prefix[i+j]-prefix[i];

                if(sum>0)
                {
                    ans=min(ans,sum);
                }
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};