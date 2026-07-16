class Solution {
public:
    long long gcdSum(vector<int>& nums){
        vector<int>prefixGcd;
        int mx=0;

        for(int x:nums){
            mx=max(mx,x);
            prefixGcd.push_back(gcd(x,mx));
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long ans=0;
        int n=prefixGcd.size();

        for(int i=0;i<n/2;i++){
            ans+=gcd(prefixGcd[i],prefixGcd[n-1-i]);
        }

        return ans;
    }
};