class Solution
{
    public int minEatingSpeed(int[] piles, int h)
    {
        int low=1;
        int high=0;

        for(int pile:piles)
        {
            high=Math.max(high,pile);
        }

        while(low<high)
        {
            int mid=low+(high-low)/2;

            if(canEat(piles,h,mid))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }

        return low;
    }

    public boolean canEat(int[] piles,int h,int k)
    {
        long hours=0;

        for(int pile:piles)
        {
            hours+=(pile+k-1)/k;

            if(hours>h)
            {
                return false;
            }
        }

        return true;
    }
}