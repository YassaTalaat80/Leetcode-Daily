class Solution {
public:
    int memo[301][27];
    pair<int, int> pr[27];

    int getDist(int a, int b) {
        if (a == 26 || b == 26) return 0;
        return abs(pr[a].first - pr[b].first) + abs(pr[a].second - pr[b].second);
    }

    int minimumDistance(string word) {
        int n = word.size();
        for (int i = 0; i < 26; ++i) pr[i] = {i / 6, i % 6};
                for(int i=0; i<=n; ++i) for(int j=0; j<27; ++j) memo[i][j] = -1;

        auto rec = [&](auto &&rec, int i, int other) -> int {
            if (i == n) return 0;
            if (memo[i][other] != -1) return memo[i][other];

            int curr = word[i] - 'A';
            int prev = (i == 0) ? 26 : word[i-1] - 'A';

            int op1 = getDist(prev, curr) + rec(rec, i + 1, other);

            int op2 = getDist(other, curr) + rec(rec, i + 1, prev);

            return memo[i][other] = min(op1, op2);
        };

        return rec(rec, 0, 26);
    }
};
