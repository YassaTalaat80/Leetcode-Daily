class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visited[505][505];
    int M, N;

    bool dfs(int r, int c, int pr, int pc, char color, vector<vector<char>>& grid) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == color) {
                if (visited[nr][nc] && (nr != pr || nc != pc)) {
                    return true;
                }
                if (!visited[nr][nc]) {
                    if (dfs(nr, nc, r, c, color, grid)) return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid)) return true;
                }
            }
        }
        return false;
    }
};
