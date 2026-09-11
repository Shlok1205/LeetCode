class Solution
{
    int timer=0;

    void dfs(int u,int parent,List<List<Integer>> graph,int[] disc,int[] low,List<List<Integer>> ans)
    {
        disc[u]=low[u]=timer++;

        for(int v:graph.get(u))
        {
            if(v==parent)
            {
                continue;
            }

            if(disc[v]==-1)
            {
                dfs(v,u,graph,disc,low,ans);

                low[u]=Math.min(low[u],low[v]);

                if(low[v]>disc[u])
                {
                    ans.add(Arrays.asList(u,v));
                }
            }
            else
            {
                low[u]=Math.min(low[u],disc[v]);
            }
        }
    }

    public List<List<Integer>> criticalConnections(int n,List<List<Integer>> connections)
    {
        List<List<Integer>> graph=new ArrayList<>();

        for(int i=0;i<n;i++)
        {
            graph.add(new ArrayList<>());
        }

        for(List<Integer> edge:connections)
        {
            int u=edge.get(0);
            int v=edge.get(1);

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        int[] disc=new int[n];
        int[] low=new int[n];

        Arrays.fill(disc,-1);

        List<List<Integer>> ans=new ArrayList<>();

        dfs(0,-1,graph,disc,low,ans);

        return ans;
    }
}