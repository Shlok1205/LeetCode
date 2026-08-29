class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());

        vector<int> ans=nums;

        int start=0;

        while(start<n){
            int end=start;

            while(end+1<n && v[end+1].first-v[end].first<=limit){
                end++;
            }

            vector<int> values;
            vector<int> indices;

            for(int i=start;i<=end;i++){
                values.push_back(v[i].first);
                indices.push_back(v[i].second);
            }

            sort(indices.begin(),indices.end());

            for(int i=0;i<values.size();i++){
                ans[indices[i]]=values[i];
            }

            start=end+1;
        }

        return ans;
    }
};