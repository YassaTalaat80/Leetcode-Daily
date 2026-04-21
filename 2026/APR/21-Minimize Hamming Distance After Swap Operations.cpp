class Solution {
public:
    struct DSU {
        vector<int> parent, sz;
        int mxsz, cmps;

        DSU(int n) {
            parent = sz = vector<int>(n);
            for (int i = 0; i < n; i++)
                parent[i] = i, sz[i] = 1;

            mxsz = 1, cmps = n;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        void uni(int x, int y) {
            x = find(x);
            y = find(y);

            if (x == y)
                return;

            if (sz[y] > sz[x])
                swap(x, y);

            parent[y] = x;

            sz[x] += sz[y];
            mxsz = max(mxsz, sz[x]);
            cmps--;
        }
    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& al) {
        int n = source.size();
        DSU dsu(n);
        for (auto& edge : al) {
            dsu.uni(edge[0], edge[1]);
        }
        unordered_map<int, unordered_map<int, int>> counts;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            counts[root][source[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            int val = target[i];

            if (counts[root][val] > 0) {
                counts[root][val]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};
