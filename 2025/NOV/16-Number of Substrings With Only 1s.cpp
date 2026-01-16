class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++){
            long long cnt = 0;
            while(i < n && s[i] == '1'){ 
                i++;
                cnt++;
            }
            ans = (ans + cnt * (cnt + 1) / 2 % MOD) % MOD;
        }   
        return ans;
    }
};
