class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> g(n);
        vector<int> deg(n, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; 
            deg[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] <= 1) q.push(i);
        }

        vector<long long> sum(n);
        for (int i = 0; i < n; i++) sum[i] = values[i];

        vector<bool> visited(n, false);

        int ans = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (visited[u]) continue;
            visited[u] = true;
            if (sum[u] % k == 0) {
                ans++;
            } 
            else {
                for (int v : g[u]) {
                    if (!visited[v]) {
                        sum[v] += sum[u];
                    }
                }
            }

            for (int v : g[u]) {
                deg[v]--;
                if (deg[v] == 1) {
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
