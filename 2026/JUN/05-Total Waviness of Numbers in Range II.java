class Solution {
  Long dp[][][][][][];

  public long totalWaviness(long num1, long num2) {
    return solve(num2) - solve(num1 - 1);
  }

  private long solve(long x) {
    if (x < 100) return 0;
    dp = new Long[17][2][2][11][11][150];
    return rec(String.valueOf(x), 0, 1, 1, 10, 10, 0);
  }

  private long rec(String str, int idx, int tight, int startZero, int prev2, int prev1, int wave) {
    if (idx == str.length()) return wave;
    if (dp[idx][tight][startZero][prev2][prev1][wave] != null)
      return dp[idx][tight][startZero][prev2][prev1][wave];

    long sum = 0L;

    int low = 0;
    int high = (tight == 1) ? (int) (str.charAt(idx) - '0') : 9;
    for (int i = low; i <= high; i++) {
      boolean isValid = (startZero == 0 && prev1 != 10 && prev2 != 10);
      boolean valley = isValley(prev2, prev1, i);
      boolean peak = isPeak(prev2, prev1, i);

      int newTight = (tight == 1 && i == high) ? 1 : 0;
      int newStartZero = (startZero == 1 && i == 0) ? 1 : 0;

      int newSum = wave + ((isValid && (valley || peak)) ? 1 : 0);
      sum +=
          rec(
              str,
              idx + 1,
              newTight,
              newStartZero,
              (startZero == 1) ? 10 : prev1,
              (newStartZero == 1) ? 10 : i,
              newSum); // Check others
    }
    return dp[idx][tight][startZero][prev2][prev1][wave] = sum;
  }

  public boolean isPeak(int a, int b, int c) {
    return a < b && b > c;
  }

  public boolean isValley(int a, int b, int c) {
    return a > b && b < c;
  }
}
