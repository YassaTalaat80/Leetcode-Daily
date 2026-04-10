class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(103);
        for (int i = 0; i < n; i++) {
            v[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for (int i = 1; i <= 100; i++) {
            if (v[i].size() >= 3) {
                for (int j = 0; j + 2 < v[i].size(); j++) {
                    int x = v[i][j];
                    int y = v[i][j + 1];
                    int z = v[i][j + 2];
                    ans = min(ans, abs(x - y) + abs(y - z) + abs(z - x));
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};
