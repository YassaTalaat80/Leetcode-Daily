class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
     vector<vector<int>> grid(m, vector<int>(n, 0)); 
        for (auto &g : guards) grid[g[0]][g[1]] = 2;
        for (auto &w : walls) grid[w[0]][w[1]] = 1;

        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

        for (auto &g : guards) {
            int r = g[0], c = g[1];

            for (auto &d : dirs) {
                int x = r + d[0];
                int y = c + d[1];

                while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 1 && grid[x][y] != 2) {
                 grid[x][y] = 3; 
                    x += d[0];
                    y += d[1];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) ans++;
            }
        }

        return ans;
    }
};
