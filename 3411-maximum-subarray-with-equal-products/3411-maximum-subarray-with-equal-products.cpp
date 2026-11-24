#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxLength(vector<int>& nums)
    {
        int n=nums.size();
        int ans=2;
        int left=0;

        for(int right=0;right<n;right++)
        {
            for(int i=left;i<right;i++)
            {
                if(gcd(nums[i],nums[right])>1)
                {
                    left=i+1;
                }
            }

            if(right-left+1>=3)
            {
                ans=max(ans,right-left+1);
            }

            if(nums[right]==1)
            {
                ans=max(ans,1);
            }
        }

        return ans;
    }
};