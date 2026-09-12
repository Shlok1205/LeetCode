class Solution
{
    static class State
    {
        long score;
        int[] ids;

        State(long score,int[] ids)
        {
            this.score=score;
            this.ids=ids;
        }
    }

    boolean better(State a,State b)
    {
        if(a.score!=b.score)
        {
            return a.score>b.score;
        }

        int n=Math.min(a.ids.length,b.ids.length);

        for(int i=0;i<n;i++)
        {
            if(a.ids[i]!=b.ids[i])
            {
                return a.ids[i]<b.ids[i];
            }
        }

        return a.ids.length<b.ids.length;
    }

    public int[] maximumWeight(List<List<Integer>> intervals)
    {
        int n=intervals.size();

        int[][] a=new int[n][4];

        for(int i=0;i<n;i++)
        {
            a[i][0]=intervals.get(i).get(0);
            a[i][1]=intervals.get(i).get(1);
            a[i][2]=intervals.get(i).get(2);
            a[i][3]=i;
        }

        Arrays.sort(a,(x,y)->
        {
            if(x[1]!=y[1])
            {
                return Integer.compare(x[1],y[1]);
            }

            return Integer.compare(x[0],y[0]);
        });

        int[] pre=new int[n+1];

        for(int i=1;i<=n;i++)
        {
            int l=a[i-1][0];

            int lo=0;
            int hi=i-1;

            while(lo<hi)
            {
                int mid=(lo+hi+1)/2;

                if(a[mid-1][1]<l)
                {
                    lo=mid;
                }
                else
                {
                    hi=mid-1;
                }
            }

            pre[i]=lo;
        }

        State[][] dp=new State[n+1][5];

        for(int i=0;i<=n;i++)
        {
            for(int k=0;k<=4;k++)
            {
                dp[i][k]=new State(0,new int[0]);
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int k=0;k<=4;k++)
            {
                dp[i][k]=dp[i-1][k];
            }

            for(int k=1;k<=4;k++)
            {
                State prev=dp[pre[i]][k-1];

                int[] ids=Arrays.copyOf(prev.ids,prev.ids.length+1);
                ids[ids.length-1]=a[i-1][3];

                Arrays.sort(ids);

                State take=new State(
                    prev.score+a[i-1][2],
                    ids
                );

                if(better(take,dp[i][k]))
                {
                    dp[i][k]=take;
                }
            }
        }

        State ans=dp[n][0];

        for(int k=1;k<=4;k++)
        {
            if(better(dp[n][k],ans))
            {
                ans=dp[n][k];
            }
        }

        return ans.ids;
    }
}