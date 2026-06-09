class Solution {
  public long maxTotalValue(int[] nums, int k) {
    long ans = 0;
    long mx = 0, mn = Integer.MAX_VALUE;
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      mx = Math.max(mx, nums[i]);
      mn = Math.min(mn, nums[i]);
    }
    ans = (mx - mn) * k;
    return ans;
  }
}
