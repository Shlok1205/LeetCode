class Solution
{
public:
    void dfs(int city,vector<vector<int>>& isConnected,vector<int>& visited)
    {
        visited[city]=1;

        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[city][j]==1 && visited[j]==0)
            {
                dfs(j,isConnected,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;

        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                provinces++;
                dfs(i,isConnected,visited);
            }
        }

        return provinces;
    }
};