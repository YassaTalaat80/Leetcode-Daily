class Solution {
public:
    int getDiv(int n) {
        int cnt = 0, sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;
                if (n / i != i) cnt++, sum += (n / i);
            }
        }
        return (cnt == 4 ? sum : 0);
    }

    int sumFourDivisors(vector<int> &nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            ans += getDiv(x);
        }
        return (int) ans;
    }
};