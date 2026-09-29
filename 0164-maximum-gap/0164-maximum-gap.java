class Solution
{
    public int maximumGap(int[] nums)
    {
        if(nums.length<2)
        {
            return 0;
        }

        int min=nums[0];
        int max=nums[0];

        for(int num:nums)
        {
            min=Math.min(min,num);
            max=Math.max(max,num);
        }

        if(min==max)
        {
            return 0;
        }

        int n=nums.length;
        int gap=(int)Math.ceil((double)(max-min)/(n-1));

        int[] bucketMin=new int[n-1];
        int[] bucketMax=new int[n-1];
        boolean[] used=new boolean[n-1];

        for(int num:nums)
        {
            if(num==min || num==max)
            {
                continue;
            }

            int index=(num-min)/gap;

            bucketMin[index]=Math.min(bucketMin[index]==0?num:bucketMin[index],num);
            bucketMax[index]=Math.max(bucketMax[index],num);
            used[index]=true;
        }

        int answer=0;
        int previous=min;

        for(int i=0;i<n-1;i++)
        {
            if(!used[i])
            {
                continue;
            }

            answer=Math.max(answer,bucketMin[i]-previous);
            previous=bucketMax[i];
        }

        answer=Math.max(answer,max-previous);

        return answer;
    }
}