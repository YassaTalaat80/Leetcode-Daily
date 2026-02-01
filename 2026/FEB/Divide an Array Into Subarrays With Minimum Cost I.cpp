class Solution {
public:
    int n;
    vector<int> nums;
    int dp[55][4];

    int solve(int i, int k) {
        if (i == n) {
            return (k == 3) ? 0 : 1e9;
        }
        if (k > 3) return 1e9;

        int &res = dp[i][k];
        if (res != -1) return res;

        res = 1e9;
        res = min(res, nums[i] + solve(i + 1, k + 1));
        if (k > 0)
            res = min(res, solve(i + 1, k));

        return res;
    }
    int minimumCost(vector<int>& nums_) {
        nums = nums_;
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};
