class Solution
{
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        int n=nums1.size();
        long long k=(long long)k1+k2;
        vector<int> diff(n);

        long long total=0;

        for(int i=0;i<n;i++)
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            total+=diff[i];
        }

        if(total<=k)
        {
            return 0;
        }

        int left=0;
        int right=*max_element(diff.begin(),diff.end());

        while(left<right)
        {
            int mid=left+(right-left)/2;
            long long operations=0;

            for(int d:diff)
            {
                if(d>mid)
                {
                    operations+=d-mid;
                }
            }

            if(operations<=k)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }

        int target=left;
        long long ans=0;
        long long remaining=k;

        for(int i=0;i<n;i++)
        {
            if(diff[i]>target)
            {
                remaining-=diff[i]-target;
                diff[i]=target;
            }

            ans+=(long long)diff[i]*diff[i];
        }

        for(int i=0;i<n && remaining>0;i++)
        {
            if(diff[i]==target)
            {
                ans-=(long long)target*target;
                ans+=(long long)(target-1)*(target-1);
                remaining--;
            }
        }

        return ans;
    }
};