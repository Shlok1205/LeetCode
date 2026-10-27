class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int total=0;
        int maxSum=nums[0];
        int minSum=nums[0];
        int currMax=0;
        int currMin=0;

        for(int num:nums)
        {
            currMax=max(currMax,0)+num;
            maxSum=max(maxSum,currMax);

            currMin=min(currMin,0)+num;
            minSum=min(minSum,currMin);

            total+=num;
        }

        if(maxSum<0)
        {
            return maxSum;
        }

        return max(maxSum,total-minSum);
    }
};