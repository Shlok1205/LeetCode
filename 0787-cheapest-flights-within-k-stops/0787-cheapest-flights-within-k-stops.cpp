class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // At most k stops = at most k+1 flights
        for(int i=0;i<=k;i++) {
            vector<int> temp = dist;

            for(auto &flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if(dist[u] != 1e9) {
                    temp[v] = min(temp[v], dist[u] + price);
                }
            }

            dist = temp;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};