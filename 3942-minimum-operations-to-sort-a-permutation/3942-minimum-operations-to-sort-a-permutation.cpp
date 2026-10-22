class Solution
{
public:
int minOperations(vector<int>& nums)
{
int n=nums.size();
int best=INT_MAX;
int k=nums[0];
bool asc=true;
bool desc=true;
for(int i=0;i<n;i++)
{
if(nums[i]!=(k+i)%n)
{
asc=false;
}
if(nums[i]!=((k-i)%n+n)%n)
{
desc=false;
}
}
if(asc)
{
best=min(best,min((n-k)%n,k+2));
}
if(desc)
{
int k2=(k+1)%n;
best=min(best,min(k2+1,1+(n-k2)%n));
}
if(best==INT_MAX)
{
return -1;
}
return best;
}
};