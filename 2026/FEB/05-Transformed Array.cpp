class Solution {
public:
    vector<int> constructTransformedArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int x = nums[i] % n;
                x = (x + i) % n;
                ans.push_back(nums[x]);
            } else if (nums[i] < 0) {
                int x = abs(nums[i]) % n;
                x = abs(x - i - n);
                x %= n;
                ans.push_back(nums[x]);
            } else ans.push_back(nums[i]);
        }
        return ans;
    }
};
