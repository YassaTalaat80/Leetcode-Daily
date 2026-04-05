class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
               int INF = 2e9; 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -INF)));

        auto rec = [&](auto&& rec, int i, int j, int cur) -> int {
            if (i == n - 1 && j == m - 1) {
                if (cur > 0 && coins[i][j] < 0) return 0; 
                return coins[i][j];
            }

            if (dp[i][j][cur] != -INF) return dp[i][j][cur];

            int res = -INF;

            if (i + 1 < n) {
                res = max(res, coins[i][j] + rec(rec, i + 1, j, cur));
                if (cur > 0) {
                    res = max(res, 0 + rec(rec, i + 1, j, cur - 1));
                }
            }

            if (j + 1 < m) {
                res = max(res, coins[i][j] + rec(rec, i, j + 1, cur));
                if (cur > 0) {
                    res = max(res, 0 + rec(rec, i, j + 1, cur - 1));
                }
            }

            return dp[i][j][cur] = res;
        };

        return rec(rec, 0, 0, 2);
    }
};
