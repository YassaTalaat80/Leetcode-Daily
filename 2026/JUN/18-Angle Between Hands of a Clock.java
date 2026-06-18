class Solution {
  public double angleClock(int hour, int minutes) {
    double angle_minute = minutes * 6.0;
    double angle_hour = hour * 30.0 + minutes * 0.5;
    double ans = Math.abs(angle_hour - angle_minute);
    ans = Math.min(ans, 360.0 - ans);
    return ans;
  }
}
