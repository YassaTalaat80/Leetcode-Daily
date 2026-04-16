class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mapa;

        for (int i = 0; i < n; i++) 
            mapa[nums[i]].push_back(i);

        vector<int> res;

        for (int q : queries) {
            auto& v = mapa[nums[q]];
            int s = v.size();

            if (s <= 1) {
                res.push_back(-1);
                continue;
            }

            int index = lower_bound(v.begin(), v.end(), q) - v.begin();

            int prev = v[(index - 1 + s) % s];
            int next = v[(index + 1) % s];

            int l = abs(q - prev);
            int r = abs(next - q);

            l = min(l, n - l);
            r = min(r, n - r);

            res.push_back(min(l, r));
        }

        return res;
    }
};
