class Solution {
    const int mod = 1e9 + 7;

public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int B = 320; 
        vector<vector<int>> queries_by_k(B);
        
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            
            if (k >= B) {
                for (int j = l; j <= r; j += k) {
                    nums[j] = (1LL * nums[j] * v) % mod;
                }
            } else {
               
                queries_by_k[k].push_back(i);
            }
        }

        vector<long long> lazy(n + B + 1, 1);

        for (int k = 1; k < B; k++) {
            if (queries_by_k[k].empty()) continue;

            fill(lazy.begin(), lazy.end(), 1);

            for (int idx : queries_by_k[k]) {
                int l = queries[idx][0], r = queries[idx][1], v = queries[idx][3];
                lazy[l] = (lazy[l] * v) % mod;
                
                int next_pos = l + ((r - l) / k + 1) * k;
                if (next_pos < n + B) {
                    lazy[next_pos] = (lazy[next_pos] * modInverse(v)) % mod;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    lazy[i] = (lazy[i] * lazy[i - k]) % mod;
                }
                if (lazy[i] != 1) {
                    nums[i] = (1LL * nums[i] * lazy[i]) % mod;
                }
            }
        }

        int xor_sum = 0;
        for (int x : nums) {
            xor_sum ^= x;
        }
        return xor_sum;
    }
};
