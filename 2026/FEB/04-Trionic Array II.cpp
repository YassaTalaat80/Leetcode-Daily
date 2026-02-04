class Solution {
public:
    long long INF = -1e18;
    vector<vector<long long> > dp;

    long long rec(int index, int st, int n, vector<int> &nums) {
        if (index == n) {
            return (st == 3) ? 0 : INF;
        }
        long long &ret = dp[index][st];
        if (~ret) return ret;
        long long take = INF;
        long long notTake = INF;

        if (st == 0) {
            notTake = rec(index + 1, 0, n, nums);
        }

        if (st == 3) {
            take = nums[index];
        }

        if (index + 1 < n) {
            if (st == 0 && nums[index + 1] > nums[index]) {
                take = max(take, nums[index] + rec(index + 1, 1, n, nums));
            } else if (st == 1) {
                if (nums[index + 1] > nums[index]) {
                    take = max(take, nums[index] + rec(index + 1, 1, n, nums));
                } else if (nums[index + 1] < nums[index]) {
                    take = max(take, nums[index] + rec(index + 1, 2, n, nums));
                }
            } else if (st == 2) {
                if (nums[index + 1] < nums[index]) {
                    take = max(take, nums[index] + rec(index + 1, 2, n, nums));
                } else if (nums[index + 1] > nums[index]) {
                    take = max(take, nums[index] + rec(index + 1, 3, n, nums));
                }
            } else if (st == 3 && nums[index + 1] > nums[index]) {
                take = max(take, nums[index] + rec(index + 1, 3, n, nums));
            }
        }

        return ret = max(take, notTake);
    }

    long long maxSumTrionic(vector<int> &nums) {
        dp.assign(nums.size(), vector<long long>(9, -1));
        return rec(0, 0, nums.size(), nums);
    }
};
