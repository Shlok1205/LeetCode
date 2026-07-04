class Solution 
{
    List<int[]>[] graph;
    boolean[] visited;
    int minScore=Integer.MAX_VALUE;

    public int minScore(int n,int[][]roads) 
    {
        graph=new ArrayList[n+1];

        for (int i=1;i<=n;i++) 
        {
            graph[i]=new ArrayList<>();
        }
        for (int[] road:roads) 
        {
            int u=road[0];
            int v=road[1];
            int d=road[2];

            graph[u].add(new int[]{v,d});
            graph[v].add(new int[]{u,d});
        }
        visited=new boolean[n+1];
        dfs(1);
        return minScore;
    }
    private void dfs(int node) 
    {
        visited[node]=true;
        for (int[] neighbor:graph[node]) 
        {
            int next=neighbor[0];
            int dist=neighbor[1];

            minScore=Math.min(minScore, dist);

            if (!visited[next]) 
            {
                dfs(next);
            }
        }
    }
}