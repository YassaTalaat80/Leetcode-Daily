

class Solution {
public:
    int repeatedNTimes(vector<int> &nums) {
        int n = nums.size();
        int ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == (n / 2)) ans = nums[i];
        }
        return ans;
    }
};
