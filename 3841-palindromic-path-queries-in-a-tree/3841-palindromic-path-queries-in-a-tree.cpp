class Solution
{
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries)
    {
        vector<vector<int>> adj(n);

        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG=17;

        vector<vector<int>> up(LOG,vector<int>(n));
        vector<int> tin(n),tout(n),depth(n);
        vector<int> pref(n);

        int timer=0;

        vector<tuple<int,int,int>> st;
        st.push_back({0,-1,0});

        while(!st.empty())
        {
            auto [u,p,state]=st.back();
            st.pop_back();

            if(state==0)
            {
                tin[u]=timer++;

                up[0][u]=(p==-1?u:p);
                depth[u]=(p==-1?0:depth[p]+1);

                pref[u]=(p==-1?0:pref[p])^(1<<(s[u]-'a'));

                st.push_back({u,p,1});

                for(int v:adj[u])
                {
                    if(v!=p)
                    {
                        st.push_back({v,u,0});
                    }
                }
            }
            else
            {
                tout[u]=timer-1;
            }
        }

        for(int j=1;j<LOG;j++)
        {
            for(int i=0;i<n;i++)
            {
                up[j][i]=up[j-1][up[j-1][i]];
            }
        }

        auto lca=[&](int u,int v)
        {
            if(depth[u]<depth[v])
            {
                swap(u,v);
            }

            int diff=depth[u]-depth[v];

            for(int j=0;j<LOG;j++)
            {
                if(diff&(1<<j))
                {
                    u=up[j][u];
                }
            }

            if(u==v)
            {
                return u;
            }

            for(int j=LOG-1;j>=0;j--)
            {
                if(up[j][u]!=up[j][v])
                {
                    u=up[j][u];
                    v=up[j][v];
                }
            }

            return up[0][u];
        };

        vector<int> bit(n+2);

        auto update=[&](int i,int val)
        {
            for(;i<=n+1;i+=i&-i)
            {
                bit[i]^=val;
            }
        };

        auto get=[&](int i)
        {
            int res=0;

            for(;i>0;i-=i&-i)
            {
                res^=bit[i];
            }

            return res;
        };

        vector<bool> ans;

        for(string q:queries)
        {
            string type;
            int u,v;

            stringstream ss(q);
            ss>>type>>u;

            if(type=="update")
            {
                char c;
                ss>>c;

                int delta=(1<<(s[u]-'a'))^(1<<(c-'a'));

                update(tin[u]+1,delta);
                update(tout[u]+2,delta);

                s[u]=c;
            }
            else
            {
                ss>>v;

                int w=lca(u,v);

                int mask=(pref[u]^get(tin[u]+1))
                        ^(pref[v]^get(tin[v]+1))
                        ^(1<<(s[w]-'a'));

                ans.push_back(__builtin_popcount((unsigned int)mask)<=1);
            }
        }

        return ans;
    }
};