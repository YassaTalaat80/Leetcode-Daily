class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                ans += (s[i] == '0');
            } else {
                ans += (s[i] == '1');
            }
        }
        int ans2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                ans2 += (s[i] == '1');
            } else
                ans2 += (s[i] == '0');
        }
        return min(ans, ans2);
    }
};
