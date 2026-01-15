class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int mx1 = 1, cnt = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) { 
                cnt++;
            } else {
                cnt = 1;
            }
            mx1 = max(mx1, cnt);
        }
        int mx2 = 1;
        cnt = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            mx2 = max(mx2, cnt);
        }
        int sideH = mx1 + 1;
        int sideV = mx2 + 1;
        long long side = min(sideH, sideV);
        return side * side;
    }
};
