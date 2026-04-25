class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> e;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            if (y == 0)
                e.push_back(x);
            else if (x == side)
                e.push_back(side + y);
            else if (y == side)
                e.push_back(2LL * side + (side - x));
            else
                e.push_back(3LL * side + (side - y));
        }
        sort(e.begin(), e.end());
        long long p = 4LL * side;

        vector<long long> ext(2 * n);
        for (int i = 0; i < n; i++) {
            ext[i] = e[i];
            ext[i + n] = e[i] + p;
        }
        auto can = [&](int x) {
            for (int i = 0; i < n; i++) {
                long long cur = ext[i];
                int idx = i;
                bool ok = true;
                for (int j = 1; j < k; j++) {
                    long long tar = cur + x;
                    auto it = lower_bound(ext.begin() + 1 + idx,
                                          ext.begin() + i + n, tar);
                    if (it == ext.begin() + i + n) {
                        ok = false;
                        break;
                    }
                    idx = it - ext.begin();
                    cur = *it;
                }
                if (ok && ext[i] + p - cur >= x) {
                    return true;
                }
            }
            return false;
        };
        int lo = 1, hi = 2ll * side, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans;
    }
};
