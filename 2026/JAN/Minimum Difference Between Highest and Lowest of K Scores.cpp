class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mn=1e9;
        for(int i=0;i+k-1<nums.size();i++){
            mn=min(mn,nums[k+i-1]-nums[i]);
        }
        return mn;
    }
};
