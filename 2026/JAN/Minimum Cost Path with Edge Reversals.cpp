
class Solution {
public:
    int minCost(int n, vector<vector<int> > &edges) {
        vector<vector<pair<int,int> > > adj(n), radj(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            if (u != n - 1)adj[u].push_back({v, w});
            if (v != n - 1)radj[v].push_back({u, w});
        }
        const int INF = 1e9;
        vector<int> dist(n, INF);
        priority_queue<
            pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dist[u]) continue;
            for (auto &[v, w]: adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
            for (auto &[v, w]: radj[u]) {
                if (dist[v] > cost + 2 * w) {
                    dist[v] = cost + 2 * w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = dist[n - 1];
        return ans == INF ? -1 : ans;
    }
};
