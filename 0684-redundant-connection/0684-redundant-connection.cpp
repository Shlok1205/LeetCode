class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b)
    {
        int pa=find(a);
        int pb=find(b);

        if(pa==pb)
        {
            return false;
        }

        if(rank[pa]<rank[pb])
        {
            parent[pa]=pb;
        }
        else if(rank[pa]>rank[pb])
        {
            parent[pb]=pa;
        }
        else
        {
            parent[pb]=pa;
            rank[pa]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();

        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }

        vector<int> ans;

        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            if(!unite(u,v))
            {
                ans=edge;
            }
        }

        return ans;
    }
};