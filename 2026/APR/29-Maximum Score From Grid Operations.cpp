#include <bits/stdc++.h>
using namespace std;

class Solution {
  int n;
  long long memo[101][101][3];
  long long pre[101][101];

  long long solve(int col, int last_h, int state) {
    if (col == n)
      return 0;
    if (memo[col][last_h][state] != -1)
      return memo[col][last_h][state];

    long long res = 0;

    for (int h = 0; h <= n; h++) {
      if (state == 0) {
        if (h > last_h) {

          long long score =
              (col > 0) ? pre[col - 1][h] - pre[col - 1][last_h] : 0;
          res = max(res, score + solve(col + 1, h, 0));
        } else if (h < last_h) {

          long long score = pre[col][last_h] - pre[col][h];
          res = max(res, score + solve(col + 1, h, 1));
        } else {
          res = max(res, solve(col + 1, h, 0));
        }
      } else if (state == 1) {
        if (h < last_h) {

          long long score = pre[col][last_h] - pre[col][h];
          res = max(res, score + solve(col + 1, h, 1));
        } else {

          res = max(res, solve(col + 1, h, 2));
        }
      } else {
        if (h > last_h) {
          long long score = pre[col - 1][h] - pre[col - 1][last_h];
          res = max(res, score + solve(col + 1, h, 2));
        } else if (h < last_h) {
          long long score = pre[col][last_h] - pre[col][h];
          res = max(res, score + solve(col + 1, h, 1));
        } else {
          res = max(res, solve(col + 1, h, 2));
        }
      }
    }

    return memo[col][last_h][state] = res;
  }

public:
  long long maximumScore(vector<vector<int>> &grid) {
    n = grid.size();
    for (int j = 0; j < n; j++) {
      pre[j][0] = 0;
      for (int i = 0; i < n; i++) {
        pre[j][i + 1] = pre[j][i] + grid[i][j];
      }
    }

    memset(memo, -1, sizeof(memo));
    return solve(0, 0, 0);
  }
};
