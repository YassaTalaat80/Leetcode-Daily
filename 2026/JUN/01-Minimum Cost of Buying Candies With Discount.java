import java.util.Arrays;

class Solution {
  public int minimumCost(int[] cost) {
    int n = cost.length;
    Arrays.sort(cost);
    int ans = 0;
    if (n <= 2) {
      for (int i = 0; i < n; i++) {
        ans += cost[i];
      }
    } else {
      for (int i = n - 1; i >= 0; ) {
        if (i - 3 >= 0) {
          ans += cost[i - 1] + cost[i];
        } else {
          for (int j = i; j >= 0; j--) {
            ans += cost[j];
          }
        }
        i -= 3;
      }
    }
    return ans;
  }
}
