class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int f) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] % f != v[i + 1] % f)
                return -1;
        }
        if ((n * m) % 2) {
            int x = (n * m) / 2;
            int y = v[x];
            int ans = 0;
            for (int i = 0; i < v.size(); i++) {
                ans += abs(y - v[i]);
            }
            return ans / f;
        } else {
            int x = (n * m) / 2;
            int a = v[x];
            int b = v[x - 1];
            int ans1 = 0, ans2 = 0;
            for (int i = 0; i < v.size(); i++) {
                ans1 += abs(a - v[i]);
                ans2 += abs(b - v[i]);
            }
            return min(ans1, ans2) / f;
        }
    }
};
