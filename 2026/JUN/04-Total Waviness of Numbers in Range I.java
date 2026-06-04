class Solution {
  public int totalMaviness(int num1, int num2) {
    int ans = 0;
    for (int x = num1; x <= num2; x++) {
      String s = String.valueOf(x);
      for (int i = 1; i < s.length() - 1; i++) {
        if (s.length() < 3) break;
        int left = s.charAt(i - 1);
        int mid = s.charAt(i);
        int right = s.charAt(i + 1);
        if ((mid > right && mid > left) || (mid < right && mid < left)) ans++;
      }
    }
    return ans;
  }
}
