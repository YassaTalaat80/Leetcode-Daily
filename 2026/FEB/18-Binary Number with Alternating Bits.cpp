class Solution {
public:
    bool hasAlternatingBits(int n) {
        int ok = -1;
        int lg = __lg(n);
        for (int i = 0; i <= lg; i++) {
            if (n >> i & 1 && ok == 1) {
                return false;
            } else if (n >> i & 1) {
                ok = 1;
            } else {
                if (ok == 0)
                    return false;
                else
                    ok = 0;
            }
        }
        return true;
    }
};
