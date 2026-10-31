class Solution
{
public:
    int uniquePaths(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int mod=1e9+7;

        vector<vector<long long>> right(m,vector<long long>(n,0));
        vector<vector<long long>> down(m,vector<long long>(n,0));

        long long ans=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                long long r=right[i][j];
                long long d=down[i][j];

                if(i==0 && j==0)
                {
                    r=1;
                }

                if(grid[i][j]==1)
                {
                    if(i+1<m)
                    {
                        down[i+1][j]=(down[i+1][j]+r)%mod;
                    }

                    if(j+1<n)
                    {
                        right[i][j+1]=(right[i][j+1]+d)%mod;
                    }
                }
                else
                {
                    long long ways=(r+d)%mod;

                    if(i==m-1 && j==n-1)
                    {
                        ans=ways;
                    }

                    if(j+1<n)
                    {
                        right[i][j+1]=(right[i][j+1]+ways)%mod;
                    }

                    if(i+1<m)
                    {
                        down[i+1][j]=(down[i+1][j]+ways)%mod;
                    }
                }
            }
        }

        return ans;
    }
};