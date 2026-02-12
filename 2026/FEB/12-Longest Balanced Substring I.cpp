
class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            vector<int> count(26, 0);
            for (int j = i; j < s.length(); ++j) {
                count[s[j] - 'a']++;
                int cnt = -1;
                bool balanced = true;
                for (int k = 0; k < 26; ++k) {
                    if (count[k] > 0) {
                        if (cnt == -1) cnt = count[k];
                        else if (count[k] != cnt) {
                            balanced = false;
                            break;
                        }
                    }
                }
                if (balanced) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
