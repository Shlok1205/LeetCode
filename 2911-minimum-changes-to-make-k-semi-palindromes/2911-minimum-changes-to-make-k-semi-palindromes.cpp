class Solution
{
public:
int minimumChanges(string s,int k)
{
int n=s.size();
vector<vector<int>> cost(n,vector<int>(n,0));
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
int len=j-i+1;
int best=INT_MAX;
for(int d=1;d<len;d++)
{
if(len%d!=0)
{
continue;
}
int c=0;
for(int g=0;g<d;g++)
{
int l=i+g;
int r=i+g+((len/d)-1)*d;
while(l<r)
{
if(s[l]!=s[r])
{
c++;
}
l+=d;
r-=d;
}
}
best=min(best,c);
}
cost[i][j]=best;
}
}
int INF=1e9;
vector<vector<int>> dp(n+1,vector<int>(k+1,INF));
dp[0][0]=0;
for(int j=1;j<=k;j++)
{
for(int i=2*j;i<=n;i++)
{
for(int p=2*(j-1);p<=i-2;p++)
{
if(dp[p][j-1]==INF)
{
continue;
}
dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p][i-1]);
}
}
}
return dp[n][k];
}
};