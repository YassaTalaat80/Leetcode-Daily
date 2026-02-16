class Solution {
public:
    int reverseBits(uint32_t n) {
        string s = "";
        for (int i = 0; i < 32; i++) {
            if (n % 2 == 0) s += '0';
            else s += '1';
            n /= 2;
        }

        int m = 0;
        for (int i = 0; i < 32; i++) {
            if (s[i] == '1') {
                m += (1 << (31 - i));
            }
        }
        return m;
    }
};
