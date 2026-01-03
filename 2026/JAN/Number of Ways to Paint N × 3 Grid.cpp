class Solution {
    const long long mod = 1e9 + 7;
    long long dp[5001][2];

public:
    long long solve(int n, int last) {
        if (n == 0) return 1;
        if (dp[n][last] != -1) return dp[n][last];
        long long res = 0;
        if (last == 0) {
            res = (3 * solve(n - 1, 0) + 2 * solve(n - 1, 1)) % mod;
        } else {
            res = (2 * solve(n - 1, 0) + 2 * solve(n - 1, 1)) % mod;
        }
        return dp[n][last] = res;
    }
    int numOfWays(int n) {
        for(int i = 0; i <= n; i++) {
            dp[i][0] = dp[i][1] = -1;
        }
        long long ans = (6 * solve(n-1, 0) + 6 * solve(n-1, 1)) % mod;
        return (int)ans;
    }
};