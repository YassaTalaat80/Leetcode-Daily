class Solution {
public:
    int longestBalanced(string s) {
       int n = s.length();
        int ans = 0;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }

        string pairs[] = {"ab", "ac", "bc"};
        for (string p : pairs) {
            char c1 = p[0];
            char c2 = p[1];
            map<int, int> mp; 
            mp[0] = -1;
            int diff = 0;
            
            for (int i = 0; i < n; i++) {
                if (s[i] != c1 && s[i] != c2) {
                   
                    mp.clear();
                    mp[0] = i;
                    diff = 0;
                } else {
                    if (s[i] == c1) diff++;
                    else diff--;

                    if (mp.count(diff)) {
                        ans = max(ans, i - mp[diff]);
                    } else {
                        mp[diff] = i;
                    }
                }
            }
        }
        map<pair<int, int>, int> mp3;
        mp3[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            int diff1 = a - b;
            int diff2 = b - c;

            if (mp3.count({diff1, diff2})) {
                ans = max(ans, i - mp3[{diff1, diff2}]);
            } else {
                mp3[{diff1, diff2}] = i;
            }
        }

        return ans;
    }
};
