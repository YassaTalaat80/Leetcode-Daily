class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        auto rec = [&](auto &&self, int i, int j) -> int {
            if (i == n && j == m) return 0;
            if (i == n) {
                int sum = 0;
                for (int k = j; k < m; k++) sum += (int) s2[k];
                return sum;
            }
            if (j == m) {
                int sum = 0;
                for (int k = i; k < n; k++) sum += (int) s1[k];
                return sum;
            }

            int &ret = dp[i][j];
            if (~ret) return ret;
            if (s1[i] == s2[j]) {
                return ret=self(self, i + 1, j + 1);
            }
            int ch1 = self(self, i + 1, j) + (int) s1[i];
            int ch2 = self(self, i, j + 1) + (int) s2[j];
            return ret = min(ch1, ch2);
        };

        return rec(rec, 0, 0);
    }
};
