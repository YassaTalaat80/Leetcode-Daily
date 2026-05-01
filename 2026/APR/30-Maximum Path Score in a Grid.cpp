#include <bits/stdc++.h>
using namespace std;
class solution {
public:
  int maxpathscore(vector<vector<int>> &grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
    auto rec = [&](auto &&rec, int i, int j, int cost) -> int {
      if (i >= n || j >= m)
        return -1e9;

      int current_cell_cost = (grid[i][j] > 0 ? 1 : 0);
      int ncost = cost + current_cell_cost;

      if (ncost > k)
        return -1e9;

      if (i == n - 1 && j == m - 1)
        return grid[i][j];

      int &ret = dp[i][j][cost];
      if (~ret)
        return ret;

      int ch1 = rec(rec, i + 1, j, ncost);
      int ch2 = rec(rec, i, j + 1, ncost);

      int res = max(ch1, ch2);
      if (res <= -1e8)
        return ret = -1e9;
      return ret = res + grid[i][j];
    };
    int res = rec(rec, 0, 0, 0);
    if (res < 0)
      return -1;
    return res;
  }
};
