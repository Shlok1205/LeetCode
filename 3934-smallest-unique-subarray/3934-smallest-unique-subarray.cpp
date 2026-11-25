class Solution
{
public:
typedef unsigned long long ull;
const ull M=(1ULL<<61)-1;
vector<ull> pre,pw;
int n;
ull mul(ull a,ull b)
{
__uint128_t t=(__uint128_t)a*b;
ull r=(ull)(t&M)+(ull)(t>>61);
if(r>=M)r-=M;
return r;
}
bool ok(int L)
{
vector<ull> h;
for(int i=0;i+L<=n;i++)
{
h.push_back((pre[i+L]+M-mul(pre[i],pw[L]))%M);
}
vector<ull> s=h;
sort(s.begin(),s.end());
int m=s.size();
for(int i=0;i<m;i++)
{
bool l=(i>0&&s[i]==s[i-1]);
bool r=(i+1<m&&s[i]==s[i+1]);
if(!l&&!r)return true;
}
return false;
}
int smallestUniqueSubarray(vector<int>& nums)
{
n=nums.size();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ull B=rng()%(M-1000)+500;
pre.assign(n+1,0);
pw.assign(n+1,1);
for(int i=0;i<n;i++)
{
pre[i+1]=(mul(pre[i],B)+nums[i])%M;
pw[i+1]=mul(pw[i],B);
}
int lo=1,hi=n;
while(lo<hi)
{
int mid=(lo+hi)/2;
if(ok(mid))hi=mid;
else lo=mid+1;
}
return lo;
}
};