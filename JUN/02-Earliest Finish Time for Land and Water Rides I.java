class Solution {
  public int earliestFinishTime(
      int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDurationTime) {
    int n = landStartTime.length;
    int m = waterStartTime.length;
    int ans = Integer.MAX_VALUE, cur1 = Integer.MAX_VALUE, cur2 = Integer.MAX_VALUE;
    for (int i = 0; i < n; i++) {
      cur1 = Math.min(landStartTime[i] + landDuration[i], cur1);
    }
    for (int i = 0; i < m; i++) {
      cur2 = Math.min(cur2, Math.max(waterStartTime[i], cur1) + waterDurationTime[i]);
    }
    ans = cur2;
    cur1 = cur2 = Integer.MAX_VALUE;
    for (int i = 0; i < m; i++) {
      cur1 = Math.min(waterStartTime[i] + waterDurationTime[i], cur1);
    }
    for (int i = 0; i < n; i++) {
      cur2 = Math.min(cur2, Math.max(landStartTime[i], cur1) + landDuration[i]);
    }
    ans = Math.min(ans, cur2);

    return ans;
  }
}
