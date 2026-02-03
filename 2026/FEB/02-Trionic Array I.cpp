class Solution {
public:
    bool isTrionic(vector<int> &nums) {
        int n = nums.size();

        if (nums[0] >= nums[1] || nums[n - 1] <= nums[n - 2] || n <= 3)return false;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] < nums[i - 1]) {
                int j = i + 1;
                while (j < n && nums[j] < nums[j - 1]) {
                    j++;
                }
                int ok = 1;
                for (int k = n - 1; k >= j; k--) {
                    if (nums[k] <= nums[k - 1]) {
                        ok = 1;
                        break;
                    } else ok = 0;
                }
                if (ok == 0) return true;
                break;
            } else if (nums[i] == nums[i - 1]) break;
        }
        return false;
    }
};
