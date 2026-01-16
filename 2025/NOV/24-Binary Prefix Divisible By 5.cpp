class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans;
        long long res=0;
        for(int i=0;i<n;i++){
            int cur=0;
                if(nums[i]==0) cur=0;
                else cur=1;
            res=res*2+cur;
            ans.push_back(res%5==0);
            res%=5;
        }
        return ans;
    }
};
