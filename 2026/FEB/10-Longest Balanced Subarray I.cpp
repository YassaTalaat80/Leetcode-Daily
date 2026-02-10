class Solution {
public:
    int longestBalanced(vector<int> &nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> odd,even;
            for (int j = i; j < n; j++) {
                int x = nums[j] % 2;
                if (x) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if (odd.size()==even.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
