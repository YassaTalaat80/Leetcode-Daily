class Solution {
public:
    int minOperations(string s, int k) {
        size_t n = s.size();
        int ones = 0, zeros = 0;
        for (char& ch : s) {
            if (ch == '1') ++ones;
            else ++zeros;
        }
        if (!zeros) return 0;
        for (size_t i = 1; i <= n; ++i) {
            int64_t flips = k * i;
            if ((flips < zeros) || ((flips - zeros) & 1)) continue;
            else if (i & 1) {
                if (flips >= zeros && flips <= zeros * i + ones * (i - 1)) return i;
            } else if (flips >= zeros && flips <= zeros * (i - 1) + ones * i) return i;
        }
        return -1;
    }
};
