class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,long long> mp;
        long long pre=0,ans=LONG_LONG_MIN;
        mp[0]=0;
        for(int i=1;i<=n;i++){
                pre+=nums[i-1];
                int mod=i%k;
                if(mp.count(mod)) ans=max(ans,pre-mp[mod]),mp[mod]=min(mp[mod],pre);
                else mp[mod]=pre;
        }
        return ans;
    }
};
