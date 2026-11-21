class Solution
{
public:
    vector<int> answer;
    vector<vector<int>> adj;

    void dfs(int node, vector<int>& parent, string& s)
    {
        adj[node].push_back(node);
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s)
    {
        int n = parent.size();
        adj.resize(n);
        answer.resize(n);

        for(int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        function<void(int)> solve = [&](int node)
        {
            int c = s[node] - 'a';
            int old = last[c];

            if(old != -1)
                newParent[node] = old;
            else
                newParent[node] = parent[node];

            last[c] = node;

            for(int child : adj[node])
                solve(child);

            last[c] = old;
        };

        solve(0);

        vector<vector<int>> finalTree(n);

        for(int i = 1; i < n; i++)
            finalTree[newParent[i]].push_back(i);

        function<int(int)> calculate = [&](int node)
        {
            int size = 1;

            for(int child : finalTree[node])
                size += calculate(child);

            answer[node] = size;
            return size;
        };

        calculate(0);

        return answer;
    }
};