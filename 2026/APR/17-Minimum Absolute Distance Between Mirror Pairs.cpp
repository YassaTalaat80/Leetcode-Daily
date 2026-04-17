class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = 1e9;
        map<int, int> nor, rev;
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            int rever = 0;
            while (x) {
                int lst = x % 10;
                rever = rever * 10 + lst;
                x /= 10;
            }
            if (nor.count(rever)) {
                ans = min(ans, nor[rever] - i);
            }
            nor[nums[i]] = i;
        }
        return ans == 1e9 ? -1 : ans;
    }
};
