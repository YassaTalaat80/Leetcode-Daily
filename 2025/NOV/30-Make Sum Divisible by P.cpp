class Solution {
public:
   int minSubarray(vector<int>& nums, int p) {
    long long total = 0;
    for (long long v : nums) total += v;
    int need = total % p;
    if (need == 0) return 0;

    unordered_map<long long,int> last;
    last[0] = -1;
    long long prefix = 0;
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        prefix = (prefix + nums[i]) % p;
        int target = (prefix - need) % p;
        if (target < 0) target += p;
        if (last.find(target) != last.end()) {
            ans = min(ans, i - last[target]);
        }
        last[prefix] = i;
    }
    return (ans == INT_MAX || ans == (int)nums.size()) ? -1 : ans;
}

};
