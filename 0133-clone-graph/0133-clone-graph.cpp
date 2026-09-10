class Solution
{
public:
    unordered_map<Node*,Node*> mp;

    Node* dfs(Node* node)
    {
        if(mp.find(node)!=mp.end())
            return mp[node];

        Node* clone=new Node(node->val);
        mp[node]=clone;

        for(Node* neighbour:node->neighbors)
        {
            clone->neighbors.push_back(dfs(neighbour));
        }

        return clone;
    }

    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
            return NULL;

        return dfs(node);
    }
};