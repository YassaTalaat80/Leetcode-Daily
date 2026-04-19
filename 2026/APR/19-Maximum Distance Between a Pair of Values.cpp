class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        int l = 0;
        for (int r = 0; r < m; r++) {
            while (l < n && nums1[l] > nums2[r])
                l++;
            if (l < n && l <= r) {
                ans = max(ans, r - l);
            }
        }
        return ans;
    }
};
