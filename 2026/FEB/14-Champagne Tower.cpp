class Solution {
    double m[101][101];
    int i,j;
public:
    double dp(int r, int c, int p) {
        if (r>i||c>j||c>r) return 0.0;
        if (r == i && c == j) return (double) p;
        if (m[r][c] != -1.0) return m[r][c];

        double left = (dp(r + 1, c, p) - 1.0) / 2.0;
        double right = (dp(r + 1, c + 1, p) - 1.0) / 2.0;

        double res = 0.0;
        if (left > 0) res += left;
        if (right > 0) res += right;

        return m[r][c] = res;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                m[i][j] = -1.0;
            i=query_row;
        j=query_glass;
        double res = dp(0, 0, poured);
        return res > 1.0 ? 1.0 : res;
    }
};
