class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int ok=1;
        int last=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(last==-1) last=i;
                else {
                    ok=((i-last)>k);
                    if(ok==0) return false;
                    last=i;
                }
            }
        }
        return true;
    }
};
