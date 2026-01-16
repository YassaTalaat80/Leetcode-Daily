class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
        int gc = 0;
        for (int x : nums) gc = gcd(gc, x);
        if (gc > 1) return -1;
        int ones = 0;
        for (int x : nums) if (x == 1) ones++;
        if (ones > 0) return n - ones;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }

        return ans + n - 1;
    }
};
