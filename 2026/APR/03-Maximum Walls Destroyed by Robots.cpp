class Solution {
public:

    int justGreaterEqual(vector<int> &walls, int target) {
    int l = 0, r = walls.size() - 1;
    int ans = walls.size(); 
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (walls[m] >= target) {
            ans = m;     
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans; 
}

    int justLessEqual(vector<int> &walls, int target) {
    int l = 0, r = walls.size() - 1;
    int ans = -1; 
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (walls[m] <= target) {
            ans = m;    
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans; 
}

    int solve(int idx, int dir, vector<pair<int,int>> &vec, vector<int> &walls, int pre, vector<vector<int> > &dp) {
        int n = vec.size();
        if (idx == n) return 0;

        if (dp[idx][dir] != -1) return dp[idx][dir];

        int robotPos = vec[idx].first;
        int robotPow = vec[idx].second;

        // left
        int limit = max(pre, (robotPos - robotPow));
        int x1 = justGreaterEqual(walls, limit);
        int x2 = justLessEqual(walls, robotPos);

        int curr = max(0, (x2 - x1) + 1);
        int takeLeft = solve(idx+1, 0, vec, walls, robotPos+1, dp) + curr;

        // right
        limit = robotPos + robotPow;
        if (idx + 1 < n) {
            limit = min(limit, vec[idx+1].first - 1);
        }
        int y1 = justGreaterEqual(walls, robotPos);
        int y2 = justLessEqual(walls, limit);

        curr = max(0, (y2 - y1) + 1);
        int takeRight = solve(idx+1, 1, vec, walls, limit+1, dp) + curr;

        return dp[idx][dir] = max(takeLeft, takeRight);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());
        vector<pair<int,int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {robots[i], distance[i]};
        }
        sort(vec.begin(), vec.end());

        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        int res = solve(0, 0,vec, walls, 1, dp);
        return res;
    }
};
