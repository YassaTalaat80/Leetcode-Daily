class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        auto rec = [&](auto &&self, int i, int j)-> int {
            if (i == n && j == m) return 0;
            if (i == n || j == m) return -1e9;
            int &ret = dp[i][j];
            if (~ret) return ret;
            int ch1 = max(0, self(self, i + 1, j + 1)) + (nums1[i] * nums2[j]);
            int ch2 = self(self, i + 1, j);
            int ch3 = self(self, i, j + 1);
            return ret = max(ch1, max(ch2, ch3));
        };
        return rec(rec, 0, 0);
    }
};