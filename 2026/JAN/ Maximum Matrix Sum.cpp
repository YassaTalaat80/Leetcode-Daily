class Solution {
public:
    long long maxMatrixSum(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long cnt = 0, mn = INT_MAX, sum = 0;
        bool zero = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);
                mn = min(abs(matrix[i][j]) * 1ll, mn);
                if (matrix[i][j] < 0) {
                    cnt++;
                }
                if (matrix[i][j] == 0) zero = true;
            }
        }
        if (!zero && cnt % 2 == 1) sum -= (mn * 2);
        return sum;
    }
};