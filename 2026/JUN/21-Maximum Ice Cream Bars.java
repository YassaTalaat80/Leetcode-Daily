class Solution {
  public int maxIceCream(int[] costs, int coins) {
    int[] freq = new int[100001];
    for (int cost : costs) {
      freq[cost]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100000; i++) {
      if (freq[i] == 0) {
        continue;
      }
      if (coins < i) {
        break;
      }

      long maxBars = Math.min((long) freq[i], (long) coins / i);
      ans += maxBars;
      coins -= maxBars * i;
    }

    return ans;
  }
}
